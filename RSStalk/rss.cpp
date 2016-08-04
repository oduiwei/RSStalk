#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "rss.h"

Rss::Rss()
{
}

Rss::Rss(QString addr)
{
    QString fileName = addr;
    this->parseRss(fileName);
}

QString Rss::getRssTitle()
{
    return this->title;
}

QString Rss::getRssLink()
{
    return this->url;
}

QStringList Rss::getArticleTitle()
{
    return this->articleTitle;
}

QStringList Rss::getArticleLink()
{
    return this->articleLink;
}

QStringList Rss::getArticleDescription()
{
    return this->articleDescription;
}

QString Rss::getPubDate()
{
    return this->pubDate;
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

QList<rssArticle> Rss::getArtList()
{
    return this->articleList;
}

int Rss::getArtNum()
{
    return this->articleList.size();
}
