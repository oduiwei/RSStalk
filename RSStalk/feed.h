#ifndef FEED_H
#define FEED_H

#include <QString>
#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QList>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QStringList>
#include <QTimer>
#include <QUrl>
#include <QMap>
#include <QXmlStreamReader>
#include <QXmlStreamAttributes>

#define read 1 //标记是否为已读
#define unread 0

class Feed
{
public:
    Feed();
    Feed(QUrl url);
    QString getTitle();
    void setTitle(QString string);

    QString getUrl();
    void setUrl(QString url);

    bool getReadMark();
    void setReadMark(bool readOrNot);

public:
    QString title;
    QString url;
    bool readmark = unread;
};

class DownloadManager : public QObject
{
    Q_OBJECT
private:
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QFile *file;
    QFileInfo fileInfo;
    QString filename;

public:
    DownloadManager();
    void doDownload(QUrl url);
    QString saveFileName(QUrl url);//给下载好的文件命名
    void rename();

public slots:
    void downloadFinished(QNetworkReply*);
};

struct rssArticle {
    int id;
    QString title;
    QString link;
    QString description;
    QString updateTime;
};

struct atomArticle {
    int id;
    QString title;
    QString link;
    QString summary;
    QString updateTime;
    QString content;
};

class XmlParser : public QObject, public QXmlStreamReader
{
    Q_OBJECT
private:
    QList<rssArticle> rssArtList;
    QList<atomArticle> atomArtList;
    //QMap<QString,QString> articles;
    QString feedTitle;
    QString feedKind;

public:
    XmlParser(QIODevice *device);

    void read_rss();//解析rss源
    void read_channel();
    void read_item();

    void read_atom();//解析atom源
    void read_feed();
    void read_entry();

    QList<rssArticle> getRssArtList();
    QList<atomArticle> getAtomArtList();
    QString getFeedTitle();
    QString getFeedKind();
};

#endif // FEED_H
