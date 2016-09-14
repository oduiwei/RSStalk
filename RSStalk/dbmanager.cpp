#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "dbmanager.h"
#include <QMessageBox>

DBManager::DBManager(QWidget *parent) : QDialog(parent)
{
    initDB();
}

DBManager::~DBManager()
{
}

void DBManager::initDB()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    //db.setDatabaseName("rsstalk.db");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("rsstalk");
    db.setUserName("root");
    db.setPassword("zhangzhuo123");
    if (!db.open())
    {
        qDebug() << "open mysql failed.";
    }
}

void DBManager::insertToFeed(int feed_id, int class_id, QString title, QString createTime, QString lastBuildTime)
{
    QSqlQuery query(db);
    //qDebug() << class_id << feed_id << title << createTime << lastBuildTime;
    query.prepare("INSERT INTO feed VALUES(?, ?, ?, ?, ?)");

    query.bindValue(0, feed_id);
    query.bindValue(1, class_id);
    query.bindValue(2, title);
    query.bindValue(3, createTime);
    query.bindValue(4, lastBuildTime);
    bool ok = query.exec();
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText();
        qDebug() << "bug in insertToFeed";
    }
}

void DBManager::insertToFolder(int index, QString name)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO class VALUES(?, ?)");

    query.bindValue(0, index);
    query.bindValue(1, name);
    bool ok = query.exec();
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText();
        qDebug() << "bug in insertToFolder";
    }
}

void DBManager::insertToSite(int id, QString url)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO site VALUES(?, ?)");
    query.bindValue(0, id);
    query.bindValue(1, url);

    bool ok = query.exec();
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText();
        qDebug() << "bug in insertToSite";
    }
}

void DBManager::insertToStorage(int id, int feed_id, QString path)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO storage VALUES(?, ?, ?)");
    query.bindValue(0, id);
    query.bindValue(1, feed_id);
    query.bindValue(2, path);

    bool ok = query.exec();
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText();
        qDebug() << "bug in insertToStorage";
    }
}

void DBManager::insertToContents(int article_id, QString title, int deleted, int favorite, int failed)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO contents VALUES(?, ?, ?, ?, ?)");
    query.bindValue(0, article_id);
    query.bindValue(1, title);
    query.bindValue(2, deleted);
    query.bindValue(3, favorite);
    query.bindValue(4, failed);

    bool ok = query.exec();
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText();
        qDebug() << "bug in insertToContents.";
    }
}

void DBManager::insertToFolder_Store_Feed(int storage_id, int feed_id)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO folder_store_feed VALUES(?, ?)");
    query.bindValue(0, storage_id);
    query.bindValue(1, feed_id);

    bool ok = query.exec();
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText();
        qDebug() << "bug in insertToFolder_Store_Feed";
    }
}

void DBManager::insertToSite_Donate_Feed(int site_id, int feed_id)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO site_donate_feed VALUES(?, ?)");
    query.bindValue(0, site_id);
    query.bindValue(1, feed_id);

    bool ok = query.exec();
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText();
        qDebug() << "bug in insertToSite_Donate_Feed";
    }
}

void DBManager::insertToStorage_Store_Feed(int storage_id, int feed_id)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO storage_store_feed VALUES(?, ?)");
    query.bindValue(0, storage_id);
    query.bindValue(1, feed_id);

    bool ok = query.exec();
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText();
        qDebug() << "bug in insertToStorage_Store_Feed";
    }
}

void DBManager::insertToFeed_Has_Contents(int feed_id, int content_id)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO feed_own_content VALUES(?, ?)");
    query.bindValue(0, feed_id);
    query.bindValue(1, content_id);

    bool ok = query.exec();
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText();
        qDebug() << "bug in insertToFeed_Has_Contents.";
    }
}

void DBManager::insertToDelete_Feed(int id, QString title, int class_id, QString url, QString path, QString date)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO delete_feed VALUES(?, ?, ?, ?, ?, ?)");
    query.bindValue(0, id);
    query.bindValue(1, title);
    query.bindValue(2, class_id);
    query.bindValue(3, url);
    query.bindValue(4, path);
    query.bindValue(5, date);

    bool ok = query.exec();
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText();
        qDebug() << "bug in insertToDelete_Feed.";
    }
}

void DBManager::insertToBrowserHistory(int id, QString url, QString date)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO browser_history VALUES(?, ?, ?)");
    query.bindValue(0, id);
    query.bindValue(1, url);
    query.bindValue(2, date);

    bool ok = query.exec();
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText();
        qDebug() << "bug in insertToBrowserHistory.";
    }
}

void DBManager::deleteTable(QString tableName)
{
    QSqlQuery query(db);
    bool ok = query.exec(QString("DELETE FROM %1").arg(tableName));

    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\ndelete table failed.";
    }
}

int DBManager::getTupleNumInSite()
{
    QSqlQuery query(db);
    bool ok = query.exec("SELECT COUNT(*) FROM site;");
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getTupleNumInsite.";
    }
    int tupleNum;
    if (query.next())
        tupleNum = query.value(0).toInt();
    //qDebug() << tupleNum;
    return tupleNum;
}

int DBManager::getTupleNumInFeed()
{
    QSqlQuery query(db);
    bool ok = query.exec("SELECT COUNT(*) FROM feed;");
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getTupleNumInFeed.";
    }
    int tupleNum;
    if (query.next())
        tupleNum = query.value(0).toInt();
    //qDebug() << tupleNum;
    return tupleNum;
}

int DBManager::getTupleNumInStorage()
{
    QSqlQuery query(db);
    bool ok = query.exec("SELECT COUNT(*) FROM storage;");
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getTupleNumInStorage.";
    }
    int tupleNum;
    if (query.next())
        tupleNum = query.value(0).toInt();
    //qDebug() << tupleNum;
    return tupleNum;
}

int DBManager::getTupleNumInContent()
{
    QSqlQuery query(db);
    bool ok = query.exec("SELECT COUNT(*) FROM contents;");
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getTupleNumInContent.";
    }
    int tupleNum;
    if (query.next())
        tupleNum = query.value(0).toInt();
    //qDebug() << tupleNum;
    return tupleNum;
}

int DBManager::getTupleNumInClass()
{
    QSqlQuery query(db);
    bool ok = query.exec("SELECT COUNT(*) FROM class;");
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getTupleNumInClass.";
    }
    int tupleNum;
    if (query.next())
        tupleNum = query.value(0).toInt();
    //qDebug() << tupleNum;
    return tupleNum;
}

int DBManager::getVacantFeedId()
{
    QList<int> feedIdList = getFeedIdList();
    for (int i = 0; i < feedIdList.size(); i++)
    {
        if (i != feedIdList[i])
            return i;
    }
    return feedIdList.size();
}

int DBManager::getVacantClassId()
{
    QList<int> classIdList = getClassIdList();
    for (int i = 0; i < classIdList.size(); i++)
    {
        if (i != classIdList[i])
            return i;
    }
    return classIdList.size();
}

int DBManager::getVacantSiteId()
{
    QList<int> siteIdList = getSiteIdList();
    for (int i = 0; i < siteIdList.size(); i++)
    {
        if (i != siteIdList[i])
            return i;
    }
    return siteIdList.size();
}

int DBManager::getVacantStorageId()
{
    QList<int> storageIdList = getStorageIdList();
    for (int i = 0; i < storageIdList.size(); i++)
    {
        if (i != storageIdList[i])
            return i;
    }
    return storageIdList.size();
}

int DBManager::getVacantContentId()
{
    QList<int> contentIdList = getContentIdList();
    for (int i = 0; i < contentIdList.size(); i++)
    {
        if (i != contentIdList[i])
            return i;
    }
    return contentIdList.size();
}

int DBManager::getVacantDeleteFeedId()
{
    QList<int> list = getDeleteFeedIdList();
    for (int i = 0; i < list.size(); i++)
    {
        if (i != list[i])
            return i;
    }
    return list.size();
}

int DBManager::getVacantBrowserHistoryId()
{
    QList<int> list = getBrowserHistoryIdList();
    for (int i = 0; i < list.size(); i++)
    {
        if (i != list[i])
            return i;
    }
    return list.size();
}

QList<QString> DBManager::getFolderNameList()
{
    QSqlQuery query(db);
    QList<QString> list;
    bool ok = query.exec("SELECT name FROM class;");
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getFolderNameList.";
    }
    while(query.next())
    {
        list.append(query.value(0).toString());
    }
    return list;
}

QList<QString> DBManager::getSubsNameList(int class_id)
{
    QSqlQuery query(db);
    QList<QString> list;
    bool ok = query.exec(QString("SELECT title FROM feed WHERE class_id = %1;").arg(class_id));
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getSubsNameList.";
    }
    while(query.next())
    {
        list.append(query.value(0).toString());
    }
    return list;
}

QList<QString> DBManager::getTableNames()
{
    QSqlQuery query(db);
    QList<QString> list;
    bool ok = query.exec(QString("show tables;"));
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getTableNames.";
    }
    while(query.next())
    {
        list.append(query.value(0).toString());
    }
    return list;
}

QList<int> DBManager::getFeedIdList()
{
    QSqlQuery query(db);
    QList<int> list;
    bool ok = query.exec(QString("SELECT feed_id FROM feed;"));
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getFeedIdList.";
    }
    while(query.next())
    {
        list.append(query.value(0).toInt());
    }
    return list;
}

QList<int> DBManager::getClassIdList()
{
    QSqlQuery query(db);
    QList<int> list;
    bool ok = query.exec(QString("SELECT id FROM class;"));
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getClassIdList.";
    }
    while(query.next())
    {
        list.append(query.value(0).toInt());
    }
    return list;
}

QList<int> DBManager::getSiteIdList()
{
    QSqlQuery query(db);
    QList<int> list;
    bool ok = query.exec(QString("SELECT id FROM site;"));
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getSiteIdList.";
    }
    while(query.next())
    {
        list.append(query.value(0).toInt());
    }
    return list;
}

QList<int> DBManager::getStorageIdList()
{
    QSqlQuery query(db);
    QList<int> list;
    bool ok = query.exec(QString("SELECT id FROM storage;"));
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getStorageIdList.";
    }
    while(query.next())
    {
        list.append(query.value(0).toInt());
    }
    return list;
}

QList<int> DBManager::getContentIdList()
{
    QSqlQuery query(db);
    QList<int> list;
    bool ok = query.exec(QString("SELECT id FROM contents;"));
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getContentIdList.";
    }
    while(query.next())
    {
        list.append(query.value(0).toInt());
    }
    return list;
}

QList<int> DBManager::getDeleteFeedIdList()
{
    QSqlQuery query(db);
    QList<int> list;
    bool ok = query.exec(QString("SELECT id FROM delete_feed;"));
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getDeleteFeedIdList.";
    }
    while(query.next())
    {
        list.append(query.value(0).toInt());
    }
    return list;
}

QList<int> DBManager::getBrowserHistoryIdList()
{
    QSqlQuery query(db);
    QList<int> list;
    bool ok = query.exec(QString("SELECT id FROM browser_history;"));
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getBrowserHistoryIdList.";
    }
    while(query.next())
    {
        list.append(query.value(0).toInt());
    }
    return list;
}

/*获取指定feed_id的订阅的文章标题列表*/
//QList<int> DBManager::getFeedContentIdList(int feed_id)
//{
//    QSqlQuery query(db);
//    QList<int> list;
//    bool ok = query.exec(QString("SELECT content_id FROM feed_own_content where feed_id=%1;").arg(feed_id));
//    if (!ok)
//    {
//        QSqlError lastError = query.lastError();
//        qDebug() << lastError.driverText() << "\nfail in getFeedContentNameList.";
//    }
//    while(query.next())
//    {
//        list.append(query.value(0).toInt());
//    }
//    return list;
//}

QString DBManager::getFeedPath(int class_id, QString title)
{
    QSqlQuery query(db);
    QString path;
    //qDebug() << class_id << title;

    bool ok = query.exec(QString("SELECT path FROM feed, storage WHERE feed.feed_id = storage.feed_id and class_id = %1 and title = '%2';").arg(class_id).arg(title));

    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getFeedPath.";
    }
    if (query.next())
        path = query.value(0).toString();
    return path;
}

QString DBManager::getFeedName(int feed_id)
{
    QSqlQuery query(db);
    QString title;

    bool ok = query.exec(QString("SELECT title FROM feed where feed_id = %1;").arg(feed_id));

    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getFeedName.";
    }
    if (query.next())
        title = query.value(0).toString();
    return title;
}

QString DBManager::getFeedUrl(int feed_id)
{
    QSqlQuery query(db);
    QString url;

    bool ok = query.exec(QString("SELECT url FROM site where id = (select site_id from site_donate_feed where feed_id = %1);").arg(feed_id));

    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getFeedUrl.";
    }
    if (query.next())
        url = query.value(0).toString();
    return url;
}

QString DBManager::getFeedPath(int feed_id)
{
    QSqlQuery query(db);
    QString path;

    bool ok = query.exec(QString("SELECT path FROM storage where feed_id = %1;").arg(feed_id));

    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getFeedPath2.";
    }
    if (query.next())
        path = query.value(0).toString();
    return path;
}

int DBManager::getFeedId(int class_id, QString title)
{
    QSqlQuery query(db);
    int feed_id;
    //qDebug() << class_id << title << "in getFeedId";

    bool ok = query.exec(QString("SELECT feed_id FROM feed WHERE class_id = %1 and title = '%2';").arg(class_id).arg(title));
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getFeedId.";

    }
    if (query.next())
        feed_id = query.value(0).toInt();

    return feed_id;
}

int DBManager::getClassId(QString name)
{
    QSqlQuery query(db);
    int class_id;

    bool ok = query.exec(QString("SELECT id FROM class WHERE name = '%1';").arg(name));
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getClassId.";

    }
    if (query.next())
        class_id = query.value(0).toInt();

    return class_id;
}

int DBManager::getClassIdByFeedTitle(QString feed_title)
{
    QSqlQuery query(db);
    int class_id;

    bool ok = query.exec(QString("SELECT class_id FROM feed WHERE title = '%1';").arg(feed_title));
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getClassIdByFeedTitle.";

    }
    if (query.next())
        class_id = query.value(0).toInt();

    return class_id;
}

int DBManager::getSiteId(int feed_id)
{
    QSqlQuery query(db);
    int site_id;
    bool ok = query.exec(QString("select site_id from site_donate_feed where feed_id = %1;").arg(feed_id));
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getSiteId.";
    }
    if (query.next())
        site_id = query.value(0).toInt();

    return site_id;
}

QList<int> DBManager::getContentId(int feed_id)
{
    QSqlQuery query(db);
    QList<int> content_id_list;
    bool ok = query.exec(QString("select content_id from feed_own_content where feed_id = %1;").arg(feed_id));
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getContentId.";
    }
    while (query.next())
    {
        content_id_list.append(query.value(0).toInt());
    }

    return content_id_list;
}

void DBManager::deleteFeed(int feed_id)
{
    QSqlQuery query(db);
    //qDebug() << feed_id << "in deleteFeed.";
    int site_id = this->getSiteId(feed_id);
    //qDebug() << site_id << "in deleteFeed.";
    QList<int> contentList = this->getContentId(feed_id);

    int delete_feed_id = getVacantDeleteFeedId();
    QString delete_feed_title = getDeleteFeedTitle(feed_id);
    int delete_feed_class_id = getDeleteFeedClass_Id(feed_id);
    QString delete_feed_url = getDeleteFeedUrl(feed_id);
    QString delete_feed_path = getDeleteFeedPath(feed_id);
    QString delete_feed_date = getDeleteFeedDate();
    insertToDelete_Feed(delete_feed_id, delete_feed_title, delete_feed_class_id, delete_feed_url, delete_feed_path, delete_feed_date);

    bool ok1 = query.exec(QString("delete from storage_store_feed where feed_id = %1;").arg(feed_id));
    bool ok2 = query.exec(QString("delete from storage where feed_id = %1;").arg(feed_id));
    bool ok3 = query.exec(QString("delete from site_donate_feed where feed_id = %1;").arg(feed_id));
    bool ok4 = query.exec(QString("delete from site where id = %1;").arg(site_id));
    bool ok5 = query.exec(QString("delete from feed_own_content where feed_id = %1;").arg(feed_id));
    bool ok6 = query.exec(QString("delete from feed where feed_id = %1;").arg(feed_id));
    for (int i = 0; i < contentList.size(); i++)
    {
        bool ok7 = query.exec(QString("delete from contents where id = %1;").arg(contentList[i]));
        if (!ok7)
            qDebug() << "delete content fail in deleteFeed.";
    }

    if (!(ok1 && ok2 && ok3 && ok4 && ok5 && ok6))
    {
        qDebug() << "delete feed and all connected table fail.";
    }
}

void DBManager::deleteFolder(int class_id)
{
    QSqlQuery query(db);
    bool ok = query.exec(QString("delete from class where id = %1;").arg(class_id));
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in deleteFolder.";
    }
}

void DBManager::deleteFeedContent(int feed_id)
{
    QSqlQuery query(db);
    /*这里必须先删除关系表内容，后删除contents内容*/
    bool ok;
    QList<int> contentIdList = this->getContentId(feed_id);
    bool ok2 = query.exec(QString("delete from feed_own_content where feed_id=%1").arg(feed_id));
    int length = contentIdList.size();
    for(int i = 0; i < length; i++)
    {
        ok = query.exec(QString("delete from contents where id=%1").arg(contentIdList.at(i)));
        if (!ok || !ok2)
        {
            QSqlError lastError = query.lastError();
            qDebug() << lastError.driverText() << "\nfail in deleteFeedContent.";
        }
    }
}

QString DBManager::getDeleteFeedTitle(int feed_id)
{
    QSqlQuery query(db);
    bool ok = query.exec(QString("SELECT title FROM feed where feed_id = %1;").arg(feed_id));
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getDeleteFeedTitle.";
    }
    QString title;
    if (query.next())
        title = query.value(0).toString();
    return title;
}

int DBManager::getDeleteFeedClass_Id(int feed_id)
{
    QSqlQuery query(db);
    bool ok = query.exec(QString("SELECT class_id FROM feed where feed_id = %1;").arg(feed_id));
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getDeleteFeedClass_Id.";
    }
    int class_id;
    if (query.next())
        class_id = query.value(0).toInt();
    return class_id;
}

QString DBManager::getDeleteFeedUrl(int feed_id)
{
    QSqlQuery query(db);
    int site_id = getSiteId(feed_id);
    bool ok = query.exec(QString("SELECT url FROM site where id = %1;").arg(site_id));
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getDeleteFeedUrl.";
    }
    QString url;
    if (query.next())
        url = query.value(0).toString();
    return url;
}

QString DBManager::getDeleteFeedPath(int feed_id)
{
    QSqlQuery query(db);
    bool ok = query.exec(QString("SELECT path FROM storage where feed_id = %1;").arg(feed_id));
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in getDeleteFeedPath.";
    }
    QString path;
    if (query.next())
        path = query.value(0).toString();
    return path;
}

QString DBManager::getDeleteFeedDate()
{
    QDateTime date = QDateTime::currentDateTime();
    QString date_time = date.toString("yyyy-MM-dd hh:mm:ss ddd");
    return date_time;
}

void DBManager::renameClassName(int class_id, QString name)
{
    QSqlQuery query(db);
    bool ok = query.exec(QString("update class set name = '%1' where id = %2;").arg(name).arg(class_id));
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in renameClassName.";
    }
}

void DBManager::renameFeedName(int feed_id, QString name)
{
    QSqlQuery query(db);
    bool ok = query.exec(QString("update feed set title = '%1' where feed_id = %2;").arg(name).arg(feed_id));
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in renameFeedName.";
    }
}

void DBManager::updateFeedPath(int feed_id, QString path)
{
    QSqlQuery query(db);
    bool ok = query.exec(QString("update storage set path = '%1' where feed_id = %2;").arg(path).arg(feed_id));
    if (!ok)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << "\nfail in renameFeedPath.";
    }
}
