#ifndef RSS_H
#define RSS_H

#include "feed.h"
#include <QStringList>
#include <QFile>

class Rss : public Feed
{
public:
    Rss();
    Rss(QString url);
    QString getRssTitle();
    QString getRssLink();
    QString getArticleTitle();
    QStringList getArticleLink();
    QStringList getArticleDescription();
    QString getPubDate();

    QList<rssArticle> getArtList();
    int getArtNum();

    void setRssTitle(QString title);
    void setArticleTitle(QString childTitle);

    void parseRss(QString fileName);
    //void parseRss(QFile &file);
    void downLoadRssFile(QString url);
    void update(QString url);

private:
    QStringList articleTitle;
    QStringList articleLink;
    QStringList articleDescription;
    QString pubDate;

    QList<rssArticle> articleList;

};

#endif // RSS_H
