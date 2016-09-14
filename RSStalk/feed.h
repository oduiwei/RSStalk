#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
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
#include <QMessageBox>
#include <QDir>

#define read 1 //标记是否为已读
#define unread 0

/*feed类是rss, atom类的父类，主要负责通过DownloadManager来下载文件和保存文件信息*/
class Feed : public QObject
{
    Q_OBJECT
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
    QString fileAddr;
    bool alreadyDownload = false;
    bool overTime = false;

public slots:
    void setFileAddr(QString);
    void processDownloadOverTime(QUrl);
signals:
    void feedDownloaded();
    void downloadOverTime(QUrl);
};

/*DownloadManager类，负责下载文件*/
class DownloadManager : public QObject
{
    Q_OBJECT
private:
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QFile file;
    QString filename;
    QString newName;
    QString absoluteAddr;

public:
    DownloadManager();
    void doDownload(QUrl url);
    QString saveFileName(QUrl url);//给下载的文件命名
    void rename();//给下载好的文件重命名
    QString getFileAddr();

signals:
    void downloadFinishedSignal(QString);
    void downloadOverTime(QUrl);

public slots:
    void downloadFinished(QNetworkReply*);
    void setFileAddrSlot(QString);
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

/*XmlParser类用于解析xml文件并保存解析结果*/
class XmlParser : public QObject, public QXmlStreamReader
{
    Q_OBJECT
private:
    QList<rssArticle> rssArtList;
    QList<atomArticle> atomArtList;
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
