#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "xmlinfodialog.h"
#include "ui_xmlinfodialog.h"

//#define PrintXML

XMLInfoDialog::XMLInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::XMLInfoDialog)
{
    ui->setupUi(this);

    setWindowTitle(tr("选择订阅"));
    setMinimumWidth(400);
    setMinimumHeight(450);
    setMaximumWidth(400);
    setMaximumHeight(450);

    QAbstractButton *okBtn = ui->buttonBox->button(QDialogButtonBox::Ok);
    QAbstractButton *cancelBtn = ui->buttonBox->button(QDialogButtonBox::Cancel);
    okBtn->setText(tr("确定"));
    cancelBtn->setText(tr("取消"));
    connect(cancelBtn, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(okBtn, SIGNAL(clicked(bool)), this, SLOT(subscriptionSelectedFinished()));

    QHeaderView *header = new QHeaderView(Qt::Horizontal, ui->treeWidget);
    header->setSectionResizeMode(QHeaderView::Stretch);
    header->setDefaultAlignment(Qt::AlignCenter);
    ui->treeWidget->setHeader(header);

    connect(ui->treeWidget, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(treeItemChanged(QTreeWidgetItem*,int)));

}

XMLInfoDialog::~XMLInfoDialog()
{
    delete ui;
}

void XMLInfoDialog::setContent(QList<Univ_Info> list)
{
    ui->treeWidget->clear();//必须先清空，否则每次进入函数会增加重复选项
    this->univList = list;
#ifdef PrintXML
    for (int i = 0; i < list.size(); i++)
    {
        Univ_Info tmp_univ = list.at(i);
        qDebug() << tmp_univ.getName();
        QList<College_Info> college_list = tmp_univ.getCollegeInfoList();
        //qDebug() << tmp2.size();
        for (int j = 0; j < college_list.size(); j++)
        {
            College_Info tmp_college = college_list.at(j);
            qDebug() << "  -->" + tmp_college.getName();
            QList<Feed_Info> feed_list = tmp_college.getFeedInfoList();
            for (int m = 0; m < feed_list.size(); m++)
            {
                Feed_Info temp_feed = feed_list.at(m);
                qDebug() << "    -->" + temp_feed.getDescription();
            }
        }
    }
#endif
    for (int i = 0; i < list.size(); i++)
    {
        Univ_Info temp_univ = list.at(i);

        //向treewidget中添加学校名称
        QTreeWidgetItem* univ_item = new QTreeWidgetItem(ui->treeWidget);
        univ_item->setText(0, temp_univ.getName());
        univ_item->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);

        QList<College_Info> college_list = temp_univ.getCollegeInfoList();
        for (int j = 0; j < college_list.size(); j++)
        {
            College_Info temp_college = college_list.at(j);

            //向当前学校项中添加学院名称
            QTreeWidgetItem* college_item = new QTreeWidgetItem(univ_item);
            college_item->setText(0, temp_college.getName());
            college_item->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
            college_item->setCheckState(0, Qt::Unchecked);

            QList<Feed_Info> feed_list = temp_college.getFeedInfoList();
            for (int m = 0; m < feed_list.size(); m++)
            {
                Feed_Info temp_feed = feed_list.at(m);

                //向当前学院选项中添加订阅名称
                QTreeWidgetItem* feed_item = new QTreeWidgetItem(college_item);
                feed_item->setText(0, temp_feed.getName());
                feed_item->setToolTip(0, temp_feed.getDescription());
                feed_item->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
                feed_item->setCheckState(0, Qt::Unchecked);
            }
        }
    }
}

//向下递归判断
void XMLInfoDialog::treeItemChanged(QTreeWidgetItem *item, int column)
{
    //选中的时候
    if (Qt::Checked == item->checkState(0))
    {
        int count = item->childCount();
        if (count > 0)
        {
            for (int i = 0; i < count; i++)
            {
                //将子节点全部选中
                item->child(i)->setCheckState(0, Qt::Checked);
                treeItemChanged(item->child(i), column);
            }
        }

        updateParentItem(item);
    }
    else if (Qt::Unchecked == item->checkState(0))//取消选中的时候
    {
        int count = item->childCount();
        if (count > 0)
        {
            for (int i = 0; i < count; i++)
            {
                item->child(i)->setCheckState(0, Qt::Unchecked);
                treeItemChanged(item->child(i), column);
            }
        }

        updateParentItem(item);
    }
}

//向上递归判断
void XMLInfoDialog::updateParentItem(QTreeWidgetItem *item)
{
    QTreeWidgetItem* parent = item->parent();
    if (parent == NULL)
        return;

    //选中的子节点个数
    int selectedCount = 0;
    int childCount = parent->childCount();
    for (int i = 0; i < childCount; i++)
    {
        QTreeWidgetItem* childItem = parent->child(i);
        if (childItem->checkState(0) == Qt::Checked)
            selectedCount++;
    }

    if (selectedCount <= 0)
    {
        parent->setCheckState(0, Qt::Unchecked);//全没选状态
    }
    else if (selectedCount > 0 && selectedCount < childCount)
    {
        parent->setCheckState(0, Qt::PartiallyChecked);//设置为部分选中状态
        updateParentItem(parent);
    }
    else if (selectedCount == childCount)
    {
        parent->setCheckState(0, Qt::Checked);//全选中状态
    }
}

void XMLInfoDialog::subscriptionSelectedFinished()
{
    //QList<QList<int>> list = getSelectedTuple();
//    for (int i = 0; i < list.size(); i++)
//        qDebug() << list.at(i).at(0) << "-" << list.at(i).at(1) << "-" << list.at(i).at(2);
    this->whetherConfirm = true;
    close();
}

QList<QList<int>> XMLInfoDialog::getSelectedTuple()
{
    QList<QList<int>> list;

    int topLevelCount = ui->treeWidget->topLevelItemCount();
    for (int i = 0; i < topLevelCount; i++)
    {
        //如果顶层item没有被选中（即其子节点都未被选中），直接跳过这个节点
        if (ui->treeWidget->topLevelItem(i)->checkState(0) == Qt::Unchecked)
            continue;

        QTreeWidgetItem* topLevelItem = ui->treeWidget->topLevelItem(i);
        int secLevelCount = topLevelItem->childCount();
        for (int j = 0; j < secLevelCount; j++)
        {
            //如果第二层item没有被选中（即第三层的节点都未被选中）， 直接跳过这个节点
            if (topLevelItem->child(j)->checkState(0) == Qt::Unchecked)
                continue;

            QTreeWidgetItem* secLevelItem = topLevelItem->child(j);
            int thirLevelCount = secLevelItem->childCount();
            for (int k = 0; k < thirLevelCount; k++)
            {
                if (secLevelItem->child(k)->checkState(0) ==  Qt::Checked)
                {
                    QList<int> subList;
                    subList << i << j << k;
                    list.append(subList);
                }
            }
        }
    }

    return list;
}
