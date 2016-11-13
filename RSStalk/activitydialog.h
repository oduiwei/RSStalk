#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef ACTIVITYDIALOG_H
#define ACTIVITYDIALOG_H

#include <QDialog>
#include <QListWidgetItem>
#include <QListWidget>
#include "filedownloader.h"

namespace Ui {
class ActivityDialog;
}

class ActivityDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ActivityDialog(QWidget *parent = 0);
    ~ActivityDialog();

    void showActivity(QList<Activity_Info> list);

private:
    Ui::ActivityDialog *ui;

    QList<Activity_Info> actiList;

private slots:
    void showActivityContent(int);
    void showPreActivity();
    void showNextActivity();
};

#endif // ACTIVITYDIALOG_H
