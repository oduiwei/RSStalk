#include "feed.h"


/*初始化Feed类*/
Feed::Feed()
{

}

Feed::Feed(QString url)
{
    DownloadManager manager;
    manager.doDownload(url);
}

QString Feed::getTitle()
{
    return this->title;
}

void Feed::setTitle(QString string)
{
    this->title = string;
}

QString Feed::getUrl()
{
    return this->url;
}

void Feed::setUrl(QString string)
{
    this->url = string;
}

bool Feed::getReadMark()
{
    return this->readmark;
}

void Feed::setReadMark(bool readOrNot)
{
    readmark = readOrNot;
}



/*初始化DownlaodManager类*/
DownloadManager::DownloadManager()
{
    connect(&manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(downloadFinished(QNetworkReply*)));//当回复完成的时候，下载完成
}

void DownloadManager::doDownload(const QUrl &url)
{
    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);

    currentDownloads.append(reply);
}

QString DownloadManager::saveFileName(const QUrl &url)
{
    QString path = url.path();
    QString basename = QFileInfo(path).fileName();

    if (basename.isEmpty())
        basename = "feed";

    if (QFile::exists(basename)) {
        //已经存在这个名字，重新命一个名字
        int i = 0;
        basename += '.';
        while (QFile::exists(basename + QString::number(i)))
            ++i;

        basename += QString::number(i);
    }

    qDebug() << basename;
    return basename;
}

bool DownloadManager::saveToDisk(const QString &filename, QIODevice *data)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }

    file.write(data->readAll());
    file.close();

    return true;
}

void DownloadManager::downloadFinished(QNetworkReply *reply)
{
    QUrl url = reply->url();
    if (reply->error()) {
        return;//下载出现错误
    } else {
        QString filename = saveFileName(url);
        if (saveToDisk(filename, reply))
//            printf("Download of %s succeeded (saved to %s)\n",
//                   url.toEncoded().constData(), qPrintable(filename));
            qDebug() << "downloadSuccess";
    }

    currentDownloads.removeAll(reply);//移除reply
    reply->deleteLater();

    if (currentDownloads.isEmpty())
        //所有的文件都下载完了
        //QCoreApplication::instance()->quit();
        qDebug() << "download all";
}



/*初始化XmlParser类*/
XmlParser::XmlParser(QIODevice *device)
{
    setDevice(device);

    while(!atEnd())
    {
        readNext();
        if(isStartElement())//判断是atom源还是rss源文件
        {
            if (name() == "rss")
            {
                feedKind = "rss";
                read_rss();
            }
            else if (name() == "feed")
            {
                feedKind = "atom";
                read_feed();
            }
        }
    }
}

void XmlParser::read_rss()
{
    while (!atEnd())
    {
        readNext();

        if (isStartElement())
            if (name() == "channel")
                read_channel();

        if (isEndElement())
            if (name() == "rss")
                break;
    }
}

void XmlParser::read_channel()
{
    QString elementName;
    while (!atEnd())
    {
        readNext();
        if (isStartElement())
        {
            elementName = name().toString();

            if (elementName == "title")
                this->feedTitle = readElementText();
            if (elementName == "item")
                read_item();
        }
        if (isEndElement())
            if (name() == "channnel")
                break;
    }
}

void XmlParser::read_item()
{
    int count = 0;

    while (!atEnd())
    {
        readNext();

        rssArticle t_rssArt;
        while (!(isEndElement() && (name() == "item")))
        {
            if (isStartElement())
            {
                t_rssArt.id = count;

                if (name() == "title")
                    t_rssArt.title = readElementText();
                else if (name() == "link")
                    t_rssArt.link = readElementText();
                else if (name() == "description")
                    t_rssArt.description = readElementText();
                else if (name() == "pubDate")
                    t_rssArt.updateTime = readElementText();
            }
            readNext();
        }
        this->rssArtList << t_rssArt;
        count++;

        if (isEndElement() && (name() == "item"))
            break;
    }
}

void XmlParser::read_atom()
{
    while (!atEnd())
    {
        readNext();

        if (isStartElement())
            if (name() == "feed")
                read_feed();

        if (isEndElement())
            if (name() == "feed")
                break;
    }
}

void XmlParser::read_feed()
{
    QString elementName;
    while (!atEnd())
    {
        readNext();
        if (isStartElement())
        {
            elementName = name().toString();

            if (elementName == "title")
                this->feedTitle = readElementText();
            if (elementName == "entry")
                read_entry();
        }
        if (isEndElement())
            if (name() == "feed")
                break;
    }
}

void XmlParser::read_entry()
{
    int count = 0;

    while (!atEnd())
    {
        readNext();

        atomArticle t_atomArt;
        while (!(isEndElement() && (name() == "entry")))
        {
            if (isStartElement())
            {
                t_atomArt.id = count;

                if (name() == "title")
                    t_atomArt.title = readElementText();
                else if (name() == "link")  //atom中网址形式是写在属性中的,<link href=""/>所以解析的方式和rss不同
                {
                    QXmlStreamAttributes attr = attributes();
                    if (attr.hasAttribute("href"))
                    {
                        t_atomArt.link = attr.value("href").toString();
                    }
                }
                else if (name() == "summary")
                    t_atomArt.summary = readElementText();
                else if (name() == "content")
                    t_atomArt.content = readElementText();
                else if (name() == "updated")
                    t_atomArt.updateTime = readElementText();
            }
            readNext();
        }
        this->atomArtList << t_atomArt;
        count++;

        if (isEndElement() && (name() == "entry"))
            break;
    }
}

QList<rssArticle> XmlParser::getRssArtList()
{
    return this->rssArtList;
}

QList<atomArticle> XmlParser::getAtomArtList()
{
    return this->atomArtList;
}

QString XmlParser::getFeedTitle()
{
    return this->feedTitle;
}

QString XmlParser::getFeedKind()
{
    return this->feedKind;
}


