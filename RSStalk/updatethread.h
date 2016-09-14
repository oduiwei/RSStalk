#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef UPDATETHREAD_H
#define UPDATETHREAD_H

#include <QThread>
#include <QDebug>
#include <QLabel>
#include <QMovie>
#include "dbmanager.h"

class UpdateThread : public QThread
{
    Q_OBJECT
public:
    UpdateThread();
protected:
    void run();
private:
    DBManager *dbManager;
    int failedNum = 0;//订阅更新失败的个数
signals:
    void alreadyUpdate();
    void updateError(int);
    void showUpdateDialog(QString);
    void noFeed();
};

#endif // UPDATETHREAD_H
