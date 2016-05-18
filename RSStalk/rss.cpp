#include "rss.h"

Rss::Rss()
{
    QString fileName = "C:\\Users\\19843\\Desktop\\test\\RSS\\feed.xml";
    this->parseRss(fileName);
}

Rss::Rss(QString url)
{
    QString fileName = url;
    this->parseRss(fileName);
}

QString Rss::getArticleTitle()
{
    QString s = "111";

    return s;
}

QStringList Rss::getArticleLink()
{
    QStringList sl;
    QList<QString> l;
    l.append("111");
    l.append("222");
    sl.append(l);

    return sl;
}

QStringList Rss::getArticleDescription()
{
    QStringList sl;
    QList<QString> l;
    l.append("111");
    l.append("222");
    sl.append(l);

    return sl;
}

QString Rss::getPubDate()
{
    return this->pubDate;
}

void Rss::setRssTitle(QString title)
{
}

void Rss::setArticleTitle(QString childTitle)
{

}

void Rss::parseRss(QString fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "open file failed";
    }

    XmlParser rssParser(&file);
    this->title = rssParser.getFeedTitle();
    this->articleList = rssParser.getRssArtList();

    file.close();
}

//void Rss::parseRss(QFile &file)
//{

//}

void Rss::downLoadRssFile(QString url)
{

}

void Rss::update(QString url)
{

}

QList<rssArticle> Rss::getArtList()
{
    return this->articleList;
}

int Rss::getArtNum()
{
    return this->articleList.size();
}

QString Rss::getRssTitle()
{
    return this->title;
}
