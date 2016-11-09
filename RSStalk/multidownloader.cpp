#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "multidownloader.h"

MultiDownloader::MultiDownloader()
{
    this->dbManager = new DBManager;
}

void MultiDownloader::setDownloadList(QList<int> feedIdList)
{
    this->feedIdList = feedIdList;
}

void MultiDownloader::run()
{
    QList<int> feedIdList = this->feedIdList;

    if (feedIdList.size() <= 0)
        return;

    QList<QString> feedUrlList;
    QList<QString> feedPathList;
    int feedNum = feedIdList.length();

    int feedIdTmp;
    QString feedUrlTmp;
    QString feedPathTmp;
    //获取所有的订阅的url
    for (int i = 0; i < feedNum; i++)
    {
        feedIdTmp = feedIdList.at(i);
        feedUrlTmp = this->dbManager->getFeedUrl(feedIdTmp);
        //qDebug() << feedUrlTmp;
        feedUrlList << feedUrlTmp;
    }
    //下载所有的订阅
    QMap<int, QList<QString> > articleNamesList;
    QMap<int, QList<QString> > articleUrlList;
    for (int j = 0; j < feedNum; j++)
    {
        emit showUpdateDialog(QString("正在下载第%1个订阅，共%2个订阅").arg(j+1).arg(feedNum));
        QTime t;
        t.start();
        QEventLoop loop;
        Feed *newFeed = new Feed(feedUrlList[j]);
        //qDebug() << feedUrlList[j];
        connect(newFeed, SIGNAL(feedDownloaded()), &loop, SLOT(quit()));
        if (t.elapsed() > 20000)
        {
            this->failedNum++;
            break;
        }
        loop.exec();

        if (!newFeed->alreadyDownload)
        {
            qDebug() << "download file failed.";
            return;
        }
        //错误写法：feedPathList并没有初始化，所以通过所以访问元素会出索引错误
        //feedPathList[j] << newFeed->fileAddr;
        feedPathList.append(newFeed->fileAddr);
        //qDebug() << "the file address is :" << newFeed->fileAddr;

        QFile file(feedPathList[j]);
        if (!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "open the downloaded file failed in updateThread";
            return;
        }
        XmlParser parser(&file);
        QList<QString> titleListTmp;
        QList<QString> linkListTmp;
        if (parser.getFeedKind() == "atom")
        {
            Atom atomFeed(feedPathList[j]);
            QList<atomArticle> atomArticleList = atomFeed.getArtList();

            for (int i = 0; i < atomArticleList.size(); i++)
            {
                titleListTmp.append(atomArticleList[i].title);
                linkListTmp.append(atomArticleList[i].link);
            }
        }
        else if (parser.getFeedKind() == "rss")
        {
            Rss rssFeed(feedPathList[j]);
            QList<rssArticle> rssArticleList = rssFeed.getArtList();

            for (int i = 0; i < rssArticleList.size(); i++)
            {
                titleListTmp.append(rssArticleList[i].title);
                linkListTmp.append(rssArticleList[i].link);
            }
        }
        articleNamesList.insert(feedIdList[j], titleListTmp);
        articleUrlList.insert(feedIdList[j], linkListTmp);
    }
    emit alreadyUpdate();//发送更新完成信号
    qDebug() << "access here.";
    QList<QString> titleList;
    QList<QString> urlList;

    for (int i = 0; i < feedNum; i++)
    {
        feedIdTmp = feedIdList.at(i);
        feedPathTmp = feedPathList.at(i);

        //更新数据库
        int storage_id = this->dbManager->getVacantStorageId();
        this->dbManager->insertToStorage(storage_id, feedIdTmp, feedPathTmp);//插入storage
        this->dbManager->insertToStorage_Store_Feed(storage_id, feedIdTmp);//插入storage_store_feed

        titleList = articleNamesList.value(feedIdTmp);
        urlList = articleUrlList.value(feedIdTmp);
        for (int j = 0; j < titleList.size(); j++)//重新插入新的内容
        {
            int content_id = this->dbManager->getVacantContentId();
            this->dbManager->insertToContents(content_id, titleList[j], urlList[j], 0, 0, 0);//插入contents
            this->dbManager->insertToFeed_Has_Contents(feedIdTmp, content_id);//插入feed_has_contents
        }
    }
    //判断是否有更新失败
    if (failedNum > 0)
        emit updateError(failedNum);
}
