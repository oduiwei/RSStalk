#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "searchtexttool.h"

SearchTextTool::SearchTextTool(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager;
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_search_finished()));
}

QString SearchTextTool::getPath()
{
    return this->path;
}

void SearchTextTool::searchKeyWord(QUrl url, QString keyWord)
{
    reply = manager->get(QNetworkRequest(url));

    QEventLoop eventLoop;
    connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    QString responseData;
    responseData = QString::fromUtf8(reply->readAll());
    responseData = responseData.replace(QRegExp(keyWord), "<style type=\"text/css\">mark{background-color: #97FFFF;}</style> <mark>" + keyWord + "</mark>");

    QDir htmlDir;
    //qDebug() << xmlDir.currentPath();
    if (!htmlDir.exists("HTML"))
    {
        htmlDir.mkdir("HTML");
    }
    htmlDir.setCurrent("HTML");

    QString fileName = this->saveFileName(url);
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out.setCodec("UTF-8");
    out<<responseData;
    file.close();

    QFileInfo info(fileName);
    this->path = info.absoluteFilePath();

    htmlDir.setCurrent("../");
}

QString SearchTextTool::saveFileName(QUrl url)
{
    QString path = url.path();
    QString basename = QFileInfo(path).fileName();

    if (basename.isEmpty())
        basename = "result";

    if (QFile::exists(basename)) {
        //已经存在这个名字，重新命一个名字
        int i = 0;
        //basename += '.';
        while (QFile::exists(basename + QString::number(i)))
            ++i;

        basename += QString::number(i);
    }

    basename += ".html";
    return basename;
}

void SearchTextTool::slot_search_finished()
{
    emit signal_search_finished();
    //qDebug() << "search finished slot has sent.";
}
