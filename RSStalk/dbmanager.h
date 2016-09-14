#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef DBDIALOG_H
#define DBDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <qDebug>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QTextCodec>
#include <QDateTime>

class DBManager : public QDialog
{
    Q_OBJECT

public:
    explicit DBManager(QWidget *parent = 0);
    ~DBManager();

    void initDB();
    void initGUI();
    void insertToFolder(int index, QString name);
    void insertToFeed(int, int, QString, QString, QString);
    void insertToSite(int id, QString url);
    void insertToStorage(int, int, QString);
    void insertToFolder_Store_Feed(int, int);
    void insertToSite_Donate_Feed(int, int);
    void insertToStorage_Store_Feed(int, int);
    void insertToContents(int, QString, int, int, int);
    void insertToFeed_Has_Contents(int, int);
    void insertToDelete_Feed(int, QString, int, QString, QString, QString);
    void insertToBrowserHistory(int, QString, QString);

    void deleteFeed(int);
    void deleteFolder(int);
    void deleteTable(QString tableName);
    void deleteFeedContent(int);

    void renameClassName(int, QString);
    void renameFeedName(int, QString);
    void updateFeedPath(int, QString);

    int getTupleNumInSite();
    int getTupleNumInFeed();
    int getTupleNumInStorage();
    int getTupleNumInContent();
    int getFeedId(int, QString);
    int getClassId(QString);
    int getSiteId(int);
    int getTupleNumInClass();
    int getVacantFeedId();
    int getVacantClassId();
    int getVacantSiteId();
    int getVacantStorageId();
    int getVacantContentId();
    int getVacantDeleteFeedId();
    int getVacantBrowserHistoryId();
    int getClassIdByFeedTitle(QString);

    QList<int> getContentId(int);
    QList<int> getFeedIdList();
    QList<int> getClassIdList();
    QList<int> getSiteIdList();
    QList<int> getStorageIdList();
    QList<int> getContentIdList();
    QList<int> getDeleteFeedIdList();
    QList<int> getBrowserHistoryIdList();
    //QList<int> getFeedContentIdList(int);
    QList<QString> getFolderNameList();
    QList<QString> getSubsNameList(int);
    QList<QString> getTableNames();

    QString getFeedPath(int, QString);
    QString getFeedName(int);
    QString getFeedUrl(int);
    QString getFeedPath(int);
    QString getDeleteFeedTitle(int);
    int getDeleteFeedClass_Id(int);
    QString getDeleteFeedUrl(int);
    QString getDeleteFeedPath(int);
    QString getDeleteFeedDate();

private:
    QSqlDatabase db;
};

#endif // DBDIALOG_H
