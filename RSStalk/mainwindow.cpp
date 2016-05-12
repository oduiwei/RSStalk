#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_addfolder.h"
#include <QIcon>
#include <QtWidgets>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QPixmap>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSize>
#include <QListWidget>
#include <QTreeWidgetItemIterator>
#include <qDebug>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("RSStalk");
    setWindowIcon(QIcon(":/new/prefix/image/RSStalk.png"));

    createToolBar();//创建工具栏

    setWindowFont();//初始化所有部件的字体

    ui->webView1->load(QUrl("http://www.baidu.com")); //设置界面中的网页加载的网页
    ui->webView2->load(QUrl("http://sw.scu.edu.cn"));

    ui->splitter->setStretchFactor(0, 2);//优化界面中的分裂窗口
    ui->splitter->setStretchFactor(1, 6);
    ui->splitter->setStretchFactor(2, 4);

    ui->treeWidget->setHeaderLabel(QStringLiteral("订阅分类"));

    /*槽函数的连接*/
    connect(ui->newFolderAction, SIGNAL(triggered()), this, SLOT(addFolderActionTriggered()));//新建分类触发
    connect(ui->newSubscriptionAcion, SIGNAL(triggered()), this, SLOT(addSubcriptionActionTriggered()));//新建推送触发

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createToolBar()
{
    //文件工具栏
    fileTool = addToolBar("File");
    fileTool->addAction(ui->importFileAction);
    fileTool->addAction(ui->newSubscriptionAcion);
    fileTool->addAction(ui->newFolderAction);

    //编辑工具栏
    editTool = addToolBar("Edit");
    editTool->addAction(ui->copyAction);
    editTool->addAction(ui->pasteAction);
    editTool->addAction(ui->cutAction);
    editTool->addSeparator();
    editTool->addAction(ui->zoomInAction);
    editTool->addAction(ui->zoomOutAction);

    //撤销和重做工具栏
    doToolBar = addToolBar("DoEdit");
    doToolBar->addAction(ui->doAction);
    doToolBar->addAction(ui->undoAction);
}

void MainWindow::setWindowFont()
{
    /*设置界面左边treewidget的字体*/
    QFont treeWidgetFont("宋体", 10);
    ui->treeWidget->setFont(treeWidgetFont);
}

void MainWindow::addFolderActionTriggered()
{
    QDialog *dialog = new QDialog;
    Ui::AddFolderDialog ui;
    ui.setupUi(dialog);
    dialog->setWindowTitle(QStringLiteral("新建分类"));
    dialog->show();
}

void MainWindow::addSubcriptionActionTriggered()
{
    QWizard *wizard = new QWizard;
    wizard->setWindowTitle(QStringLiteral("新建推送"));

    /*初始化新建推送向导的第一页*/
    QWizardPage *page1 = new QWizardPage;
    page1->setTitle(QStringLiteral("新建一个推送"));

    QLabel *urlLabel = new QLabel;
    urlLabel->setText(QStringLiteral("请输入推送的URL地址，我们会对其进行解析"));
    urlLabel->setWordWrap(true);

    QLabel *tipsLabel = new QLabel;
    tipsLabel->setText(QStringLiteral("温馨提示：提供RSS服务的网页往往有个类似左边图片的图标，点击后复制网址就OK啦！"));
    tipsLabel->setWordWrap(true);

    QLabel *pixLabel = new QLabel;
    QPixmap pix("F:\\Qt_workplace\\RSStalk\\RSStalk\\RSStalk\\image\\RSS.png");
    pixLabel->setPixmap(pix);
    pixLabel->resize(QSize(pix.width(), pix.height()));

    QLineEdit *urlLineEdit = new QLineEdit;
    urlLineEdit->setText(QStringLiteral("http://"));

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(urlLabel);
    vLayout->addWidget(urlLineEdit);
    vLayout->addWidget(tipsLabel);

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(pixLabel);
    hLayout->addLayout(vLayout);

    page1->setLayout(hLayout);//设置page1的布局

    /*初始化新建推送向导的第二页*/
    QWizardPage *page2 = new QWizardPage;
    page2->setTitle(QStringLiteral("给新的订阅取个名字吧"));

    QLabel *nameLabel = new QLabel;
    nameLabel->setText(QStringLiteral("请输入这个订阅的标题："));

    QLineEdit *nameLineEdit = new QLineEdit;

    QLabel *chooseLabel = new QLabel;
    chooseLabel->setText(QStringLiteral("请选择一个分类文件夹："));

    /*将这个treewidget与主界面的treewidget内容同步*/
    QTreeWidget *folderTreeWidget = new QTreeWidget;
    folderTreeWidget->setHeaderLabel(QStringLiteral("订阅列表"));
    folderTreeWidget->setColumnCount(1);
    QHeaderView *header = new QHeaderView(Qt::Horizontal, folderTreeWidget);
    header->setDefaultAlignment(Qt::AlignCenter);
    folderTreeWidget->setHeader(header);

    int i = ui->treeWidget->topLevelItemCount();
    for (int j = 0; j < i; j++)
    {
        QStringList columnList;
        QString folderNameString = ui->treeWidget->topLevelItem(j)->text(0);
        columnList << folderNameString;
        QTreeWidgetItem *item = new QTreeWidgetItem(columnList);

        int childNum = ui->treeWidget->topLevelItem(j)->childCount();
        //qDebug() << childNum;
        if (childNum > 0)
        {
            for(int m = 0; m < childNum; m++)
            {
                QString childFolderNameString;
                QStringList childColumnList;

                childFolderNameString = ui->treeWidget->topLevelItem(j)->child(m)->text(0);
                childColumnList << childFolderNameString;
                QTreeWidgetItem *childItem = new QTreeWidgetItem(childColumnList);

                item->addChild(childItem);
            }
        }

        folderTreeWidget->addTopLevelItem(item);
    }

    QPushButton *newFolderBtn = new QPushButton;
    newFolderBtn->setText(QStringLiteral("新建文件夹"));

    QPixmap pixInPage2("F:\\Qt_workplace\\RSStalk\\RSStalk\\RSStalk\\image\\RSS.png");
    QLabel *pixLabelInPage2 = new QLabel;
    pixLabelInPage2->setPixmap(pixInPage2);

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch();
    bottomLayout->addWidget(newFolderBtn);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(nameLabel);
    rightLayout->addWidget(nameLineEdit);
    rightLayout->addStretch();
    rightLayout->addWidget(chooseLabel);
    rightLayout->addWidget(folderTreeWidget);
    rightLayout->addLayout(bottomLayout);
    rightLayout->setStretchFactor(nameLabel, 1);
    rightLayout->setStretchFactor(nameLineEdit, 1);
    rightLayout->setStretchFactor(chooseLabel, 1);
    rightLayout->setStretchFactor(folderTreeWidget, 3);
    rightLayout->setStretchFactor(bottomLayout, 0);

    QHBoxLayout *mainHLayout = new QHBoxLayout;
    mainHLayout->addWidget(pixLabelInPage2);
    mainHLayout->addLayout(rightLayout);

    page2->setLayout(mainHLayout);

    /*初始化新建推送向导的第二页*/
    QWizardPage *page3 = new QWizardPage;
    page3->setTitle(QStringLiteral("完成"));

    QLabel *finishLabel = new QLabel;
    finishLabel->setText(QStringLiteral("点击finish完成新建订阅，我们将为您更新您的订阅列表"));
    finishLabel->setWordWrap(true);

    QPixmap pixInPage3("F:\\Qt_workplace\\RSStalk\\RSStalk\\RSStalk\\image\\RSS.png");
    QLabel *pixLabelInPage3 = new QLabel;
    pixLabelInPage3->setPixmap(pixInPage3);

    QHBoxLayout *finishLayout = new QHBoxLayout;
    finishLayout->addWidget(pixLabelInPage3);
    finishLayout->addWidget(finishLabel);

    page3->setLayout(finishLayout);

    wizard->addPage(page1);
    wizard->addPage(page2);
    wizard->addPage(page3);
    wizard->resize(QSize(750, 450));
    wizard->show();

}
