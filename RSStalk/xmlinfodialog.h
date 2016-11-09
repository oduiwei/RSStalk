#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef XMLINFODIALOG_H
#define XMLINFODIALOG_H

#include <QDialog>
#include <QHeaderView>
#include <QTreeWidgetItem>
#include <QAbstractButton>
#include <QDialogButtonBox>
#include <QPushButton>
#include "filedownloader.h"

namespace Ui {
class XMLInfoDialog;
}

class XMLInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit XMLInfoDialog(QWidget *parent = 0);
    ~XMLInfoDialog();

    void setContent(QList<Univ_Info> list);
    QList<QList<int>> getSelectedTuple();

private:
    Ui::XMLInfoDialog *ui;
    QList<Univ_Info> univList;

    void updateParentItem(QTreeWidgetItem* item);

private slots:
    void treeItemChanged(QTreeWidgetItem* item, int column);
    void subscriptionSelectedFinished();
};

#endif // XMLINFODIALOG_H
