#ifndef RSS_H
#define RSS_H

#include "feed.h"
#include <QStringList>
#include <QFile>

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
