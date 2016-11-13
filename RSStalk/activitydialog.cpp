#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "activitydialog.h"
#include "ui_activitydialog.h"

//#define DEBUG_ACTIVITY

ActivityDialog::ActivityDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActivityDialog)
{
    ui->setupUi(this);

    setWindowTitle(tr("最新活动列表"));
    ui->splitter->setStretchFactor(0, 2);
    ui->splitter->setStretchFactor(1, 5);
    setMinimumWidth(830);
    setMinimumHeight(620);
    setMaximumHeight(620);
    setMaximumWidth(830);

    connect(ui->listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(showActivityContent(int)));
    connect(ui->preBtn, SIGNAL(clicked(bool)), this, SLOT(showPreActivity()));
    connect(ui->nextBtn, SIGNAL(clicked(bool)), this, SLOT(showNextActivity()));
}

ActivityDialog::~ActivityDialog()
{
    delete ui;
}

void ActivityDialog::showActivity(QList<Activity_Info> list)
{
    for (int i = 0; i < list.size(); i++)
    {
        this->actiList.append(list.at(i));
    }
#ifdef DEBUG_ACTIVITY
    for (int i = 0; i < actiList.size(); i++)
    {
        Activity_Info tmp = actiList.at(i);
        qDebug() << "activity" << i + 1;
        qDebug() << "  -->" << tmp.getTitle();
        qDebug() << "  -->" << tmp.getTime();
        qDebug() << "  -->" << tmp.getAddress();
        qDebug() << "  -->" << tmp.getContent();
        qDebug() << "  -->" << tmp.getName();
        qDebug() << "  -->" << tmp.getStunum();
        qDebug() << "  -->" << tmp.getTel();
        qDebug() << "  -->" << tmp.getSchname();
        qDebug() << "  -->" << tmp.getColname();
        qDebug() << "";
    }
#endif

    for (int i = 0; i < list.size(); i++)
    {
        Activity_Info tmp_activity = list.at(i);
        QListWidgetItem* tmp_item = new QListWidgetItem;
        tmp_item->setText(tmp_activity.getTitle());
        ui->listWidget->addItem(tmp_item);
    }
}

void ActivityDialog::showActivityContent(int row)
{
    Activity_Info current = this->actiList.at(row);

    QString title = current.getTitle();
    QString time = current.getTime();
    QString address = current.getAddress();
    QString content = current.getContent();
    QString name = current.getName();
    QString stunum = current.getStunum();
    QString tel = current.getTel();
    QString schname = current.getSchname();
    QString colname = current.getColname();

    ui->titleLineEdit->setText(title);
    ui->timeLineEdit->setText(time);
    ui->addressLineEdit->setText(address);
    ui->contentTextEdit->setText(content);
    ui->nameLineEdit->setText(name);
    ui->stunumLineEdit->setText(stunum);
    ui->telLineEdit->setText(tel);
    ui->schnameLineEdit->setText(schname);
    ui->colnameLineEdit->setText(colname);
}

void ActivityDialog::showPreActivity()
{
    int currentRow = ui->listWidget->currentRow();
    int totalActi = this->actiList.size();

    currentRow = (currentRow - 1 + totalActi) % totalActi;
    ui->listWidget->setCurrentRow(currentRow);
}

void ActivityDialog::showNextActivity()
{
    int currentRow = ui->listWidget->currentRow();
    int totalActi = this->actiList.size();

    currentRow = (currentRow + 1 + totalActi) % totalActi;
    ui->listWidget->setCurrentRow(currentRow);
}
