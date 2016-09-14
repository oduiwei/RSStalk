#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "updatethread.h"
#include "feed.h"
#include <QUrl>
#include <QTime>
#include <QEventLoop>
#include <QHBoxLayout>
#include <QMessageBox>
#include "atom.h"
#include "rss.h"

UpdateThread::UpdateThread()
{
    dbManager = new DBManager;
}

void UpdateThread::run()
{
    //qDebug() << "success to run() in updateThread";
    QList<int> feedIdList = this->dbManager->getFeedIdList();
    QList<QString> feedUrlList;
    QList<QString> feedPathList;
    QList<QString> feedPathListUp;
    int feedNum = feedIdList.length();
    //qDebug() << feedNum;
    if (feedNum == 0)
    {
        emit noFeed();
        return;
    }
    int feedIdTmp;
    QString feedUrlTmp;
    QString feedPathTmp;
    //获取所有的订阅的url和path
    for (int i = 0; i < feedNum; i++)
    {
        feedIdTmp = feedIdList.at(i);
        feedUrlTmp = this->dbManager->getFeedUrl(feedIdTmp);
        feedPathTmp = this->dbManager->getFeedPath(feedIdTmp);
        feedUrlList << feedUrlTmp;
        feedPathList << feedPathTmp;
        feedPathListUp << feedPathTmp;//先让更新地址列表默认值为旧地址（不赋值后面会报错）
        //qDebug() << feedIdTmp << " " << feedUrlTmp << " " << feedPathTmp;
    }
    //重新下载所有的订阅
    QList<QString> articleNamesList;
    for (int j = 0; j < feedNum; j++)
    {
        QUrl urlTmp(feedUrlList[j]);
        //qDebug() << feedUrlList[j];
        emit showUpdateDialog(QString("正在更新第%1个订阅，共%2个订阅，请稍等...").arg(j+1).arg(feedNum));
        QTime t;
        t.start();
        QEventLoop loop;
        Feed *newFeed = new Feed(urlTmp);
        connect(newFeed, SIGNAL(feedDownloaded()), &loop, SLOT(quit()));
        if (t.elapsed() > 20000)
        {
            this->failedNum++;
            break;
        }
        loop.exec();
        //qDebug() << "access here.";
        if (!newFeed->alreadyDownload)
        {
            qDebug() << "download file failed.";
            return;
        }
        feedPathListUp[j] = newFeed->fileAddr;
        //qDebug() << "qccess here";

        QFile file(feedPathListUp[j]);
        if (!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "open the downloaded file failed in updateThread";
            return;
        }
        XmlParser parser(&file);
        if (parser.getFeedKind() == "atom")
        {
            Atom atomFeed(feedPathListUp[j]);
            QList<atomArticle> atomArticleList = atomFeed.getArtList();
            for (int i = 0; i < atomArticleList.size(); i++)
            {
                articleNamesList.append(atomArticleList[i].title);
            }
        }
        else if (parser.getFeedKind() == "rss")
        {
            Rss rssFeed(feedPathListUp[j]);
            QList<rssArticle> rssArticleList = rssFeed.getArtList();
            for (int i = 0; i < rssArticleList.size(); i++)
            {
                articleNamesList.append(rssArticleList[i].title);
            }
        }
    }
    emit alreadyUpdate();//发送更新完成信号
    //更新数据库
    for (int i = 0; i < feedNum; i++)//先删除所有的旧XML文件
    {
        QString feedPathOld = feedPathList.at(i);
        QFile::remove(feedPathOld);
    }

    for (int i = 0; i < feedNum; i++)
    {
        feedIdTmp = feedIdList.at(i);
        feedPathTmp = feedPathListUp.at(i);
        this->dbManager->updateFeedPath(feedIdTmp, feedPathTmp);
        //qDebug() << feedIdTmp << " " << feedPathTmp;
        this->dbManager->deleteFeedContent(feedIdTmp);//删除feedIdTmp的所有文章内容
        for (int j = 0; j < articleNamesList.size(); j++)//重新插入新的内容
        {
            int content_id = this->dbManager->getVacantContentId();
            this->dbManager->insertToContents(content_id, articleNamesList[j], 0, 0, 0);
            this->dbManager->insertToFeed_Has_Contents(feedIdTmp, content_id);
        }
    }
    //判断是否有更新失败
    if (failedNum > 0)
        emit updateError(failedNum);
}
