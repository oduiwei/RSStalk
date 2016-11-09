#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "feed.h"
#include <QEventLoop>


/*==============================================初始化Feed类======================================*/
Feed::Feed()
{

}

Feed::~Feed()
{
    needAlter = false;
}

Feed::Feed(QString url)
{
    DownloadManager *download = new DownloadManager;//必须要new一个，这样才能放到堆中，只有程序退出
    //这些数据才会删除，防止后面的qnetworkaccessmanager finished信号不能触发

    //判断是否是html文件，如果是，需要将html转换成xml
    QRegExp regForSchoolSubs("^http{0,1}://[\\w/.&?=]*(sw.scu.edu.cn)+[\\w/.&?=]*");
    if (regForSchoolSubs.exactMatch(url))
    {
        this->needAlter = true;
    }

    download->doDownload((QUrl)url);//开始下载文件
    connect(download, SIGNAL(downloadFinishedSignal(QString)), this, SLOT(setFileAddr(QString)));
    connect(download,SIGNAL(downloadOverTime(QUrl)), this, SLOT(processDownloadOverTime(QUrl)));
}

void Feed::setFileAddr(QString addr)
{
    QFileInfo info(addr);
    fileAddr = info.absoluteFilePath();
    alreadyDownload = true;

    if (!needAlter)
    {
        emit feedDownloaded();
        return;
    }

    //HTMLtoXMLParser *parser = new HTMLtoXMLParser(fileAddr);
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


/*===============================初始化DownlaodManager类===============================================*/
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
        qDebug() << "download error in downloadFinished of DownloadManager.";
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

QString DownloadManager::getFileAddr()
{
    //这里会面临一个问题，当文件还没下完时，获取的名字是空的
    return absoluteAddr;
}

void DownloadManager::setFileAddrSlot(QString newName)
{
    QFileInfo info(newName);
    absoluteAddr = info.absoluteFilePath();
    //qDebug() << absoluteAddr;
}



/*================================初始化XmlParser类==================================================*/
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

/*=============================初始化HtmlParser类======================================================*/
//HtmlParser::HtmlParser(QString fileAddr)
//{
//    QFile file(fileAddr);
//    if (!file.open(QIODevice::ReadOnly))
//    {
//        qDebug() << "open the downloaded html file failed";
//        return;
//    }

//    this->dom = new QDomDocument;
//    dom->setContent(&file);

//    QDomElement root = dom->documentElement();
//    QDomNode list = root.firstChild();
//    QDomNode next = list.nextSibling();
//    qDebug() << root.tagName();
////    for (int i = 0; i < list.size(); i++)
////    {
////        QDomElement temp = list.item(i).toElement();
////        qDebug() << temp.tagName() << endl;
////    }
//    //qDebug() << "enter HtlmParser's construction function.";
////    setDevice(device);

////    while (!atEnd())
////    {
////        readNext();
////        qDebug() << name();
////        if (isStartElement())
////        {
////            qDebug() << "access here.\n";
////            if (name() == "html")//读取HTML标签
////                read_table();
////        }

////        if (isEndElement())
////            if (name() == "html")
////                break;
////    }
//}

//HtmlParser::~HtmlParser()
//{

//}

//void HtmlParser::read_table()
//{
//    qDebug() << "enter read_table.";
////    while (!atEnd())
////    {
////        readNext();
////        if (isStartElement())
////            if (name() == "table" && attributes().hasAttribute("id"))//找到id为__01的table标签
////                if (attributes().value("id") == "__01")
////                    read_td_header();
////    }
//}

//void HtmlParser::read_td_header()
//{
//    qDebug() << "enter read_td_header.";
////    while (!atEnd())
////    {
////        readNext();
////        if (isStartElement())
////            if (name() == "td" && (attributes().value("background") == "/sw/lib/images/sw02_3.jpg"))
////                read_tr_header();
////    }
//}

//void HtmlParser::read_tr_header()
//{
//    qDebug() << "enter read_tr_header.";
////    while (!atEnd())
////    {
////        readNext();
////        if (isStartElement())
////            if (name() == "td" && (attributes().hasAttribute("width")))
////                this->header = readElementText();

////        if (isEndElement())
////            if (name() == "td")
////                break;
////    }
//}

//QString HtmlParser::getHeader()
//{
//    return this->header;
//}

//QMap<QString, QString> HtmlParser::getArticles()
//{
//    return this->articles;
//}

/*=============================初始化HTMLtoXMLParser类=================================================*/
//HTMLtoXMLParser::HTMLtoXMLParser(QString fileAddr)
//{
////    qDebug() << fileAddr;
////    QFile file(fileAddr);
////    if (!file.open(QIODevice::ReadOnly))
////    {
////        qDebug() << "open the downloaded html file failed";
////        return;
////    }

//    HtmlParser *htmlp = new HtmlParser(fileAddr);
//    //QString title = htmlp->getHeader();
//    //qDebug() << title + "in HTMLtoXMLParser.";
//}

//HTMLtoXMLParser::~HTMLtoXMLParser()
//{
//}

///*从HTML文件中读取标题*/
//QString HTMLtoXMLParser::readHeader(QString fileAddr)
//{
//    return "a";
//}

///*从HTML文件中读取文章（包括文章标题和文章对应链接）*/
////QMap<QString, QString> HTMLtoXMLParser::readArticle(QString fileAddr)
////{

////}

