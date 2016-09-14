#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "feed.h"
#include <QEventLoop>


/*初始化Feed类*/
Feed::Feed()
{

}

Feed::Feed(QUrl url)
{
    DownloadManager *download = new DownloadManager;//必须要new一个，这样才能放到堆中，只有程序退出这些数据才会删除，防止
    //后面的qnetworkaccessmanager finished信号不能触发
    download->doDownload(url);
    connect(download, SIGNAL(downloadFinishedSignal(QString)), this, SLOT(setFileAddr(QString)));
    connect(download,SIGNAL(downloadOverTime(QUrl)), this, SLOT(processDownloadOverTime(QUrl)));
}

void Feed::setFileAddr(QString addr)
{
    QFileInfo info(addr);
    fileAddr = info.absoluteFilePath();
    alreadyDownload = true;
    emit feedDownloaded();
    //qDebug() << "already emit";
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

void Feed::processDownloadOverTime(QUrl url)
{
    overTime = true;
    emit downloadOverTime(url);
}


/*初始化DownlaodManager类*/
DownloadManager::DownloadManager()
{
    //qDebug() << "enter 1";
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(downloadFinished(QNetworkReply*)));
    connect(this, SIGNAL(downloadFinishedSignal(QString)), this, SLOT(setFileAddrSlot(QString)));
}

void DownloadManager::doDownload(const QUrl url)
{
    //qDebug() << "enter 2";
    filename = saveFileName(url);
    //qDebug() << filename;
    QDir xmlDir;
    //qDebug() << xmlDir.currentPath();
    if (!xmlDir.exists("XML"))
    {
        xmlDir.mkdir("XML");
    }
    file.setFileName(filename);
    xmlDir.setCurrent("XML");

    if (!file.open(QIODevice::ReadWrite)) {
        //QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("打开文件错误！"));
        return;
    }

    QNetworkRequest request(url);
    reply = manager->get(request);
}

QString DownloadManager::saveFileName(QUrl url)
{
    //qDebug() << "enter 3";
    QString path = url.path();
    QString basename = QFileInfo(path).fileName();

    if (basename.isEmpty())
        basename = "feed";

    if (QFile::exists(basename)) {
        //已经存在这个名字，重新命一个名字
        int i = 0;
        //basename += '.';
        while (QFile::exists(basename + QString::number(i)))
            ++i;

        basename += QString::number(i);
    }

    //qDebug() << basename;
    return basename;
}

void DownloadManager::downloadFinished(QNetworkReply *reply)
{
    //qDebug() << "enter 4";
    if (reply->error())
    {
        qDebug() << "download error.";
        //QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("下载失败！请检查输入网址是否正确！"));
        return;//下载出现错误
    }

    file.write(reply->readAll());
    file.flush();
    file.close();
    reply->deleteLater();

    rename();
    //qDebug() << newName;
    QDir dir;
    dir.setCurrent("../");
}

/*给下载好的文件重命名，名字为xml文件的标题*/
void DownloadManager::rename()
{
    //qDebug() << "enter 5";
    if (!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "file open failed in rename";
        return;
    }
    if (file.size() == 0)
    {
        qDebug() << "file size equals 0.";
        return;
    }

    //qDebug() << file->size();
    XmlParser parser(&file);
    QString tempName = parser.getFeedTitle() + ".xml";
    newName = parser.getFeedTitle();

    if (QFile::exists(tempName)) {
        //已经存在这个名字，重新命一个名字
        int i = 1;
        while (QFile::exists(newName + QString::number(i)))
            ++i;

        newName += QString::number(i);
        tempName = newName + ".xml";
    }
    newName += ".xml";
    file.rename(newName);
    //qDebug() << newName;

    file.close();
    emit downloadFinishedSignal(newName);
}

QString DownloadManager::getFileAddr()//这里会面临一个问题，当文件还没下完时，获取的名字是空的
{
    return absoluteAddr;
}

void DownloadManager::setFileAddrSlot(QString newName)
{
    QFileInfo info(newName);
    absoluteAddr = info.absoluteFilePath();
    //qDebug() << absoluteAddr;
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


