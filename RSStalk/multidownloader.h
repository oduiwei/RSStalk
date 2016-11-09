#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef MULTIDOWNLOADER_H
#define MULTIDOWNLOADER_H

#include <QThread>
#include <QList>
#include <QDebug>
#include <QLabel>
#include <QMovie>
#include <QUrl>
#include <QTime>
#include <QEventLoop>
#include <QHBoxLayout>
#include <QMessageBox>
#include "atom.h"
#include "rss.h"
#include "dbmanager.h"
#include "feed.h"

class MultiDownloader : public QThread
{
    Q_OBJECT
public:
    MultiDownloader();

    void setDownloadList(QList<int> list);
protected:
    void run();
private:
    DBManager *dbManager;
    int failedNum = 0;//订阅更新失败的个数
    QList<int> feedIdList;
signals:
    void alreadyUpdate();
    void updateError(int);
    void showUpdateDialog(QString);
};

#endif // MULTIDOWNLOADER_H
