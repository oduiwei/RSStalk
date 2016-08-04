#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef RSS_H
#define RSS_H

#include "feed.h"
#include <QStringList>
#include <QFile>

/*Rss类继承于Feed类，负责通过XmlParser类解析Rss文件并提供获取解析结果的接口*/
class Rss : public Feed
{
public:
    Rss();
    Rss(QString addr);
    QString getRssTitle();
    QString getRssLink();
    QStringList getArticleTitle();
    QStringList getArticleLink();
    QStringList getArticleDescription();
    QString getPubDate();

    QList<rssArticle> getArtList();
    int getArtNum();

    void parseRss(QString fileName);

private:
    QStringList articleTitle;
    QStringList articleLink;
    QStringList articleDescription;
    QString pubDate;

    QList<rssArticle> articleList;

};

#endif // RSS_H
