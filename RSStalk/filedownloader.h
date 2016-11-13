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
class ActivityXmlParser;
class Feed_Info;
class College_Info;
class Univ_Info;
class Activity_Info;

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

/*服务器的activity.xml的解析器，可以获取一个Activity_Info的链表*/
class ActivityXmlParser : public QObject, public QXmlStreamReader
{
    Q_OBJECT
public:
    ActivityXmlParser(QString path);

    QList<Activity_Info> getActivityInfoList();
    void deleteCurrentXML();

private:
    QString currentPath;
    QList<Activity_Info> actiInfoList;

    void readXMLDocuemnt();
    void readActivityInfo(Activity_Info *actiInfo);
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

/*activity.xml中的activity标签类*/
class Activity_Info
{
private:
    QString title;
    QString time;
    QString address;
    QString content;
    QString name;
    QString stunum;
    QString tel;
    QString schname;
    QString colname;

public:
    Activity_Info(QString, QString, QString, QString, QString, QString, QString, QString, QString);
    Activity_Info() {}

    QString getTitle();
    QString getTime();
    QString getAddress();
    QString getContent();
    QString getName();
    QString getStunum();
    QString getTel();
    QString getSchname();
    QString getColname();

    void setTitle(QString title);
    void setTime(QString time);
    void setAddress(QString address);
    void setContent(QString content);
    void setName(QString name);
    void setStunum(QString stunum);
    void setTel(QString tel);
    void setSchname(QString schname);
    void setColname(QString colname);
};

#endif // FILEDOWNLOADER_H
