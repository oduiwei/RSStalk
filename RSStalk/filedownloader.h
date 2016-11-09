#ifndef FILEDOWNLOADER_H
#define FILEDOWNLOADER_H

#include <QObject>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QXmlStreamReader>
#include <QXmlStreamAttributes>

class InfoXMLParser;
class Feed_Info;
class College_Info;
class Univ_Info;

/*服务器中info.xml的下载器*/
class FileDownloader : public QObject
{
    Q_OBJECT
public:
    explicit FileDownloader();

    void doDownload(QUrl url);
    QString saveFileName(QUrl url);//给下载的文件命名
    QString getFileAddr();

signals:
    void downloadOverTime(QUrl);
    void downloadSuccess();

public slots:
    void downloadFinished(QNetworkReply*);

private:
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QFile file;
    QString filename;
    QString absoluteAddr;
};

/*服务器的info.xml的解析器，可以获取一个Univ_Info的链表*/
class InfoXMLParser : public QObject, public QXmlStreamReader
{
    Q_OBJECT
public:
    InfoXMLParser(QString path);

    QList<Univ_Info> getUnivInfoList();
    void deleteCurrentXML();

private:
    QString currentPath;

    QList<Univ_Info> univInfoList;
    void setUnivInfoList(QList<Univ_Info> list);

    void readXMLDocument();
    void readUnivInfo(Univ_Info *univInfo);
    void readCollegeInfo(College_Info *collegeInfo);
    void readFeedInfo(Feed_Info *feedInfo);
};

/*info.xml中的Feed标签类*/
class Feed_Info
{
public:
    Feed_Info(QString name, QString link, QString description);
    Feed_Info();

    QString getName();
    QString getLink();
    QString getDescription();

    void setName(QString name);
    void setLink(QString link);
    void setDescription(QString description);

private:
    QString name;
    QString link;
    QString description;
};

/*info.xml中的college标签类*/
class College_Info
{
public:
    College_Info(QString name, QList<Feed_Info> list);
    College_Info();

    QString getName();
    QList<Feed_Info> getFeedInfoList();
    void setName(QString name);
    void setFeedInfoList(QList<Feed_Info> list);

private:
    QString name;
    QList<Feed_Info> feedInfoList;
};

/*info.xml中的university标签类*/
class Univ_Info
{
public:
    Univ_Info(QString name, QList<College_Info> list);
    Univ_Info();

    QString getName();
    void setName(QString name);
    QList<College_Info> getCollegeInfoList();
    void setCollegeInfoList(QList<College_Info> list);
private:
    QString name;
    QList<College_Info> collegeInfoList;
};

#endif // FILEDOWNLOADER_H
