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
    Feed(QString url);
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
    QNetworkAccessManager manager;
    QList<QNetworkReply *> currentDownloads;//下载的列表

public:
    DownloadManager();
    void doDownload(const QUrl &url);
    QString saveFileName(const QUrl &url);//给下载好的文件命名
    bool saveToDisk(const QString &filename, QIODevice *data);

public slots:
    //void execute();
    void downloadFinished(QNetworkReply *reply);
};

//class article : public QObject
//{
//    Q_OBJECT

//public:
//    int id;
//    QString title;
//    QString link;
//    QString updateTime;

////    QString description;

////    QString summary;
////    QString content;


//    article() { }
//    ~article() { }
//    article(const article& art)
//    {
//        id = art.id;
//        title = art.title;
//        link = art.link;
//        updateTime = art.updateTime;

////        description = art.description;

////        summary = art.summary;
////        content = art.content;
//    }
//};

//class rssArticle : public article
//{
//    Q_OBJECT
//public:
//    QString description;

//    rssArticle() { }
//    ~rssArticle() { }
//    rssArticle(const rssArticle& rss)
//    {
//        description = rss.description;
//    }
//};

//class atomArticle : public article
//{
//    Q_OBJECT
//public:
//    QString summary;
//    QString content;

//    atomArticle() { }
//    ~atomArticle() { }
//    atomArticle(const atomArticle& atom)
//    {
//        summary = atom.summary;
//        content = atom.content;
//    }
//};

/*发现用结构体来对文章进行分类后，在后面的qmap对应键和值的时候会有麻烦，所以用类来表示*/
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
