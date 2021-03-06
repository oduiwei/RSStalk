﻿#include "filedownloader.h"

/************************************FileDownloader类部分***********************************************/
FileDownloader::FileDownloader()
{
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(downloadFinished(QNetworkReply*)));
}

void FileDownloader::doDownload(const QUrl url)
{
    //qDebug() << "enter 2";
    filename = saveFileName(url);
    //qDebug() << filename;
    QDir xmlDir;
    //qDebug() << xmlDir.currentPath();
    if (!xmlDir.exists("XML"))
    {
        xmlDir.mkdir("XML");
    }
    file.setFileName(filename);
    xmlDir.setCurrent("XML");

    if (!file.open(QIODevice::ReadWrite)) {
        //QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("打开文件错误！"));
        return;
    }

    QNetworkRequest request(url);
    reply = manager->get(request);
}

QString FileDownloader::saveFileName(QUrl url)
{
    //qDebug() << "enter 3";
    QString path = url.path();
    QString basename = QFileInfo(path).fileName();

    if (basename.isEmpty())
        basename = "feed";

    if (QFile::exists(basename)) {
        //已经存在这个名字，重新命一个名字
        int i = 0;
        //basename += '.';
        while (QFile::exists(basename + QString::number(i)))
            ++i;

        basename += QString::number(i);
    }

    //qDebug() << basename;
    return basename;
}

void FileDownloader::downloadFinished(QNetworkReply *reply)
{
    //qDebug() << "enter 4";
    if (reply->error())
    {
        qDebug() << "download error.";
        //QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("下载失败！请检查输入网址是否正确！"));
        return;
    }

    file.write(reply->readAll());
    file.flush();
    file.close();
    reply->deleteLater();

    QFileInfo info(file);
    this->absoluteAddr = info.absoluteFilePath();
    //qDebug() << absoluteAddr;
    QDir dir;
    dir.setCurrent("../");
    emit downloadSuccess();
}

QString FileDownloader::getFileAddr()
{
    return absoluteAddr;
}

/************************************InfoXMLParser类部分***********************************************/
InfoXMLParser::InfoXMLParser(QString path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Open file failed in InfoXMLParser.";
        return;
    }
    this->currentPath = path;

    setDevice(&file);
    //int count = 0;

    while(!atEnd())
    {
        readNext();

        if (isStartElement())
        {
            if (name() == "category")
            {
                this->readXMLDocument();
            }
        }//这里不需要判断结束标签，需要读取全文内容
    }
}

QList<Univ_Info> InfoXMLParser::getUnivInfoList()
{
    return this->univInfoList;
}

void InfoXMLParser::readXMLDocument()
{
    //int count = 0;
    while (!atEnd())
    {
        readNext();
        if (isStartElement())
        {
            if (name() == "university")
            {
//                count++;
//                qDebug() << tr("the %1 call readUnivInfo().").arg(count);
                Univ_Info univInfo;
                this->readUnivInfo(&univInfo);
                //将读取的Univ_Info类加入到列表中
                this->univInfoList.append(univInfo);
            }
        }

        //当读取到category结束标签时（即文件结尾），结束循环
        if (isEndElement())
        {
            if (name() == "category")
                break;
        }
    }
}

void InfoXMLParser::readUnivInfo(Univ_Info *univInfo)
{
    QList<College_Info> list;

    while (!atEnd())
    {
        readNext();

        if (isStartElement())
        {
            if (name() == "uname")
            {
                QString name = readElementText();
                univInfo->setName(name);
            }
            else if (name() == "college")
            {
                College_Info collegeInfo;
                this->readCollegeInfo(&collegeInfo);
                //qDebug() << collegeInfo.getName();
                //将读取的College_Info加入到临时变量list中
                list.append(collegeInfo);
            }
        }

        //当读到university结束标签，此次读取univ信息结束
        if (isEndElement())
        {
            if (name() == "university")
                break;
        }
    }
    univInfo->setCollegeInfoList(list);
}

void InfoXMLParser::readCollegeInfo(College_Info *collegeInfo)
{
    QList<Feed_Info> list;

    while (!atEnd())
    {
        readNext();

        if (isStartElement())
        {
            if (name() == "cname")
            {
                QString name = readElementText();
                collegeInfo->setName(name);
            }
            else if (name() == "feed")
            {
                Feed_Info feedInfo;
                this->readFeedInfo(&feedInfo);
                //qDebug() << feedInfo.getName() << " " << feedInfo.getLink() << " " << feedInfo.getDescription();
                //将读取的Feed_Info加入到临时变量list中
                list.append(feedInfo);
            }
        }

        //当读到college结束标签时，结束本次读取College_Info
        if (isEndElement())
        {
            if (name() == "college")
                break;
        }
    }

    collegeInfo->setFeedInfoList(list);
    //这里要注意list只是读出一个链表，并不能设置collegeInfo的链表属性
    //所以要调用setFeedInfoList方法

//    QList<Feed_Info> list2 = collegeInfo->getFeedInfoList();
//    for (int i = 0; i < list2.size(); i++)
//    {
//        Feed_Info feedInfo = list2.at(i);
//        qDebug() << feedInfo.getName() << " " << feedInfo.getLink() << " " << feedInfo.getDescription();
//    }
}

void InfoXMLParser::readFeedInfo(Feed_Info *feedInfo)
{
    while (!atEnd())
    {
        readNext();

        if (isStartElement())
        {
            if (name() == "fname")
            {
                QString name = readElementText();
                feedInfo->setName(name);
                //qDebug() << name;
            }
            else if (name() == "link")
            {
                QString link = readElementText();
                feedInfo->setLink(link);
                //qDebug() << link;
            }
            else if (name() == "description")
            {
                QString description = readElementText();
                feedInfo->setDescription(description);
                //qDebug() << description;
            }
        }

        if (isEndElement())
        {
            if (name() == "feed")
                break;
        }
    }
}

void InfoXMLParser::deleteCurrentXML()
{
    QFile::remove(this->currentPath);
}


/****************************************Feed_Info类部分***********************************************/
Feed_Info::Feed_Info(QString name, QString link, QString description)
{
    this->name = name;
    this->link = link;
    this->description = description;
}

Feed_Info::Feed_Info() {}

QString Feed_Info::getName()
{
    return this->name;
}

QString Feed_Info::getLink()
{
    return this->link;
}

QString Feed_Info::getDescription()
{
    return this->description;
}

void Feed_Info::setName(QString name)
{
    this->name = name;
}

void Feed_Info::setLink(QString link)
{
    this->link = link;
}

void Feed_Info::setDescription(QString description)
{
    this->description = description;
}


/*************************************College_Info类部分***********************************************/
College_Info::College_Info(QString name, QList<Feed_Info> list)
{
    this->name = name;
    this->feedInfoList = list;
}

College_Info::College_Info() {}

QString College_Info::getName()
{
    return this->name;
}

QList<Feed_Info> College_Info::getFeedInfoList()
{
    return this->feedInfoList;
}

void College_Info::setName(QString name)
{
    this->name = name;
}

void College_Info::setFeedInfoList(QList<Feed_Info> list)
{
    //this->feedInfoList = list;
    for (int i = 0; i < list.size(); i++)
        this->feedInfoList.append(list.at(i));
}

/****************************************Univ_Info类部分***********************************************/
Univ_Info::Univ_Info(QString name, QList<College_Info> list)
{
    this->name = name;
    this->collegeInfoList = list;
}

Univ_Info::Univ_Info() {}

QString Univ_Info::getName()
{
    return this->name;
}

QList<College_Info> Univ_Info::getCollegeInfoList()
{
    return this->collegeInfoList;
}

void Univ_Info::setName(QString name)
{
    this->name = name;
}

void Univ_Info::setCollegeInfoList(QList<College_Info> list)
{
    //this->collegeInfoList = list;
    for (int i = 0; i < list.size(); i++)
        this->collegeInfoList.append(list.at(i));
}

/****************************************Activity_Info类部分********************************************/
Activity_Info::Activity_Info(QString title, QString time, QString address,
                             QString content, QString name, QString stunum,
                             QString tel, QString schname, QString colname)
{
    this->title = title;
    this->time = time;
    this->address = address;
    this->content = content;
    this->name = name;
    this->stunum = stunum;
    this->tel = tel;
    this->schname = schname;
    this->colname = colname;
}

QString Activity_Info::getTitle()
{
    return this->title;
}

QString Activity_Info::getTime()
{
    return this->time;
}

QString Activity_Info::getAddress()
{
    return this->address;
}

QString Activity_Info::getContent()
{
    return this->content;
}

QString Activity_Info::getName()
{
    return this->name;
}

QString Activity_Info::getStunum()
{
    return this->stunum;
}

QString Activity_Info::getTel()
{
    return this->tel;
}

QString Activity_Info::getSchname()
{
    return this->schname;
}

QString Activity_Info::getColname()
{
    return this->colname;
}

void Activity_Info::setTitle(QString title)
{
    this->title = title;
}

void Activity_Info::setTime(QString time)
{
    this->time = time;
}

void Activity_Info::setAddress(QString address)
{
    this->address = address;
}

void Activity_Info::setContent(QString content)
{
    this->content = content;
}

void Activity_Info::setName(QString name)
{
    this->name = name;
}

void Activity_Info::setStunum(QString stunum)
{
    this->stunum = stunum;
}

void Activity_Info::setTel(QString tel)
{
    this->tel = tel;
}

void Activity_Info::setSchname(QString schname)
{
    this->schname = schname;
}

void Activity_Info::setColname(QString colname)
{
    this->colname = colname;
}

/*********************************ActivityXmlParser类部分************************************/
ActivityXmlParser::ActivityXmlParser(QString path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Open file failed in InfoXMLParser.";
        return;
    }
    this->currentPath = path;

    setDevice(&file);

    while(!atEnd())
    {
        readNext();

        if (isStartElement())
        {
            if (name() == "rsstalk")
            {
                this->readXMLDocuemnt();
            }
        }//这里不需要判断结束标签，需要读取全文内容
    }
}

void ActivityXmlParser::readXMLDocuemnt()
{
    while (!atEnd())
    {
        readNext();
        if (isStartElement())
        {
            if (name() == "activity")
            {
                Activity_Info actiInfo;
                this->readActivityInfo(&actiInfo);
                //将读取的Activity_Info类加入到列表中
                this->actiInfoList.append(actiInfo);
            }
        }

        //当读取到rsstalk结束标签时（即文件结尾），结束循环
        if (isEndElement())
        {
            if (name() == "rsstalk")
                break;
        }
    }
}

void ActivityXmlParser::readActivityInfo(Activity_Info *actiInfo)
{
    while (!atEnd())
    {
        readNext();

        if (isStartElement())
        {
            if (name() == "title")
            {
                QString title = readElementText();
                actiInfo->setTitle(title);
                continue;
            }
            else if (name() == "time")
            {
                QString time = readElementText();
                actiInfo->setTime(time);
                continue;
            }
            else if (name() == "address")
            {
                QString address = readElementText();
                actiInfo->setAddress(address);
                continue;
            }
            else if (name() == "content")
            {
                QString content = readElementText();
                actiInfo->setContent(content);
                continue;
            }
            else if (name() == "name")
            {
                QString name = readElementText();
                actiInfo->setName(name);
                continue;
            }
            else if (name() == "stunum")
            {
                QString stunum = readElementText();
                actiInfo->setStunum(stunum);
                continue;
            }
            else if (name() == "tel")
            {
                QString tel = readElementText();
                actiInfo->setTel(tel);
                continue;
            }
            else if (name() == "schname")
            {
                QString schname = readElementText();
                actiInfo->setSchname(schname);
                continue;
            }
            else if (name() == "colname")
            {
                QString colname = readElementText();
                actiInfo->setColname(colname);
                continue;
            }
        }

        //当读到activity结束标签，此次读取activity信息结束
        if (isEndElement())
        {
            if (name() == "activity")
                break;
        }
    }
}

QList<Activity_Info> ActivityXmlParser::getActivityInfoList()
{
    return this->actiInfoList;
}

void ActivityXmlParser::deleteCurrentXML()
{
    QFile::remove(this->currentPath);
}
