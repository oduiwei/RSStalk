#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_addfolder.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("RSStalk");
    setWindowIcon(QIcon(":/new/prefix/image/RSStalk.png"));

    ui->webView->load(QUrl("http://sw.scu.edu.cn")); //设置界面中的网页加载的网页

    ui->splitter->setStretchFactor(0, 2);//优化界面中的分裂窗口
    ui->splitter->setStretchFactor(1, 6);
    ui->splitter->setStretchFactor(2, 4);
    ui->treeWidget->setHeaderLabel(QStringLiteral("订阅分类"));

    ui->toolBox->removeItem(0);

    ui->tabWidget->setTabText(0, QStringLiteral("软件学院"));

    createToolBar();//创建工具栏
    setWindowFont();//初始化所有部件的字体
    showParseResultExample();//显示解析的结果主要是treewidget和toolbox中内容的显示
    //downloadTest();

    /*槽函数的连接*/
    connect(ui->newFolderAction, SIGNAL(triggered()), this, SLOT(addFolderActionTriggered()));//新建分类触发
    connect(ui->newSubscriptionAcion, SIGNAL(triggered()), this, SLOT(addSubcriptionActionTriggered()));//新建推送触发
    connect(ui->aheadToolBtn, SIGNAL(clicked(bool)), this, SLOT(lineEditUrlEntered()));
    connect(ui->webEditLine, SIGNAL(editingFinished()), this, SLOT(lineEditUrlEntered()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::downloadTest()
{
    Feed feed("http://www.ruanyifeng.com/blog/atom.xml");
    qDebug() << feed.getReadMark();
}

void MainWindow::showParseResultExample()
{
    QString AtomFileName = "C:\\Users\\19843\\Desktop\\test\\ATOM\\atom.xml";
    QString RssFileName = "C:\\Users\\19843\\Desktop\\test\\RSS\\feed.xml";
    QString newsFileName = "C:\\Users\\19843\\Desktop\\test\\RSS\\ns.xml";

    QStringList feedTitleText_0;
    QStringList feedTitleText_1;
    QStringList feedTitleText_2;

    Rss rssfile(RssFileName);
    feedTitleText_0 << rssfile.getRssTitle();
    //rssList = qobject_cast<QList<article> >(rssfile.getArtList());

    Atom atomfile(AtomFileName);
    feedTitleText_1 << atomfile.getAtomTitle();
    //atomList = qobject_cast<QList<article> >(atomfile.getArtList());

    Rss newsfile(newsFileName);
    feedTitleText_2 << newsfile.getRssTitle();

    QTreeWidgetItem *item0 = new QTreeWidgetItem(feedTitleText_0, 0);//添加两个treewidget
    QTreeWidgetItem *item1 = new QTreeWidgetItem(feedTitleText_1, 0);
    QTreeWidgetItem *item2 = new QTreeWidgetItem(feedTitleText_2, 0);
    //qDebug() << ui->treeWidget->topLevelItem(0)->text(0);打印出界面中treewidget的第0列，第0个子item
    ui->treeWidget->topLevelItem(0)->addChild(item0);
    ui->treeWidget->topLevelItem(0)->addChild(item1);
    ui->treeWidget->topLevelItem(1)->addChild(item2);

    treeWidgetList.insert(feedTitleText_0.at(0), RssFileName);
    treeWidgetList.insert(feedTitleText_1.at(0), AtomFileName);
    treeWidgetList.insert(feedTitleText_2.at(0), newsFileName);

    connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(on_treeWidget_title_clicked(QTreeWidgetItem*, int)));

}

void MainWindow::on_treeWidget_title_clicked(QTreeWidgetItem* item, int column)
{
    if (item->parent())//判断点击的item是否是子Items
    {
        QString titleClicked;
        //titleClicked = ui->treeWidget->currentItem()->text(0);//获取当前点击的文章的标题
        titleClicked = item->text(column);//获取当前点击的文章的标题

        QString fileName = treeWidgetList[titleClicked];

        QFile feedfile(fileName);
        if (!feedfile.open(QIODevice::ReadOnly))
        {
            qDebug() << "open file failed";
        }

        XmlParser parser(&feedfile);           //用来判断点击的文章是属于rss还是atom

        if (parser.getFeedKind() == "rss")
        {
            Rss rss(fileName);

            QGroupBox *artBox = new QGroupBox;
            QVBoxLayout *vLayout = new QVBoxLayout(artBox);
            //vLayout->addStretch(1);

            QList<rssArticle> rssList = rss.getArtList();

            for (int posi = 0; posi < rssList.size(); posi++)
            {
                MyToolButton *titleButton = new MyToolButton;
                titleButton->feedtitle = titleClicked;
                titleButton->pos = posi;
                titleButton->setAutoRaise(true);
                titleButton->setText(rssList[posi].title);

                vLayout->addWidget(titleButton);

                connect(titleButton, SIGNAL(myclicked(QString,int)), this, SLOT(showArticleContent(QString,int)));
            }

            if (toolBoxHasRepeatChild(titleClicked))//当点击的订阅在toolbox中存在的时候获取存在的index并设置当前index为index
            {
                int index = childItemIndexInToolBox(titleClicked);
                ui->toolBox->setCurrentIndex(index);
            }
            else
            {
                ui->toolBox->addItem(artBox, titleClicked);
                ui->toolBox->setCurrentWidget(artBox);//把用户点击的推送设为当前显示
            }
        }
        else if (parser.getFeedKind() == "atom")
        {
            Atom atom(fileName);

            QGroupBox *artBox = new QGroupBox;
            QVBoxLayout *vLayout = new QVBoxLayout(artBox);

            QList<atomArticle> atomList = atom.getArtList();

            for (int posi = 0; posi < atomList.size(); posi++)
            {
                MyToolButton *titleButton = new MyToolButton;
                titleButton->feedtitle = titleClicked;
                titleButton->pos = posi;
                titleButton->setAutoRaise(true);
                titleButton->setText(atomList[posi].title);

                vLayout->addWidget(titleButton);

                connect(titleButton, SIGNAL(myclicked(QString,int)), this, SLOT(showArticleContent(QString,int)));
            }

            if (toolBoxHasRepeatChild(titleClicked))
            {
                int index = childItemIndexInToolBox(titleClicked);
                ui->toolBox->setCurrentIndex(index);
            }
            else
            {
                ui->toolBox->addItem(artBox, titleClicked);
                ui->toolBox->setCurrentWidget(artBox);//把用户点击的推送设为当前显示
            }
        }

        feedfile.close();
    }
}

bool MainWindow::toolBoxHasRepeatChild(QString title)//判断新建的item是否已经存在toolbox中
{
    int childNum = ui->toolBox->count();
    for (int i = 0; i < childNum; i++)
    {
        if (ui->toolBox->itemText(i) == title)
            return true;
    }

    return false;
}

int MainWindow::childItemIndexInToolBox(QString title)//获取重复Item的index
{
    int childNum = ui->toolBox->count();
    for (int i = 0; i < childNum; i++)
    {
        if (ui->toolBox->itemText(i) == title)
            return i;
    }
    return 0;
}

void MyToolButton::mousePressEvent(QMouseEvent * event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit myclicked(feedtitle, pos);
    }
    QToolButton::mousePressEvent(event);
}

void MainWindow::showArticleContent(QString title, int pos)
{
    //qDebug() << title << " " << pos;//测试成功
    QString fileName = treeWidgetList[title];

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
        qDebug() << "open file failed in showArticleContent";

    XmlParser parser(&file);
    if(parser.getFeedKind() == "rss")
    {
        Rss rss(fileName);

        QList<rssArticle> rssList = rss.getArtList();
        //qDebug() << rssList[pos].description;//获取内容成功，但是还需要解析

        if (rssList[pos].link == NULL)
            qDebug() << "there is no link info";
        else
        {
            QUrl articleUrl(rssList[pos].link); //让界面中的webview加载网页
            ui->webView->load(articleUrl);
            ui->tabWidget->setTabText(0, rssList[pos].title);
        }
    }
    else if (parser.getFeedKind() == "atom")
    {
        Atom atom(fileName);

        QList<atomArticle> atomList = atom.getArtList();
        //qDebug() << atomList[pos].content;//获取内容成功，但是还需要解析

        if (atomList[pos].link == NULL)
        {
            qDebug() << "there is no link info";
        }
        else
        {
            QUrl articleUrl(atomList[pos].link);//界面中的webview加载网页
            ui->webView->load(articleUrl);
            ui->tabWidget->setTabText(0, atomList[pos].title);
        }
    }

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

    /*设置QToolBox字体*/
    QFont toolBoxFont("宋体", 10);
    ui->toolBox->setFont(toolBoxFont);

    /*设置QToolBar字体*/
    QFont toolBarFont("宋体", 10);
    fileTool->setFont(toolBarFont);
    editTool->setFont(toolBarFont);
    doToolBar->setFont(toolBarFont);

    /*设置左下角QToolButton字体*/
    QFont toolBtnFont("宋体", 10);
    ui->IRCToolBtn->setFont(toolBtnFont);
    ui->feedbackToolBtn->setFont(toolBtnFont);
    ui->releaseToolBtn->setFont(toolBtnFont);
    ui->shareToolBtn->setFont(toolBtnFont);
    ui->webToolBtn->setFont(toolBtnFont);

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
    QFont wizardFont("宋体", 10);

    wizard = new QWizard;
    wizard->setWindowTitle(QStringLiteral("新建推送"));
    wizard->setFont(wizardFont);
    wizard->setWizardStyle(QWizard::ModernStyle);
    //wizard->setOption(QWizard::HaveHelpButton, true);//显示帮助按钮


    /*初始化新建推送向导的第一页*/
    page1 = new QWizardPage;
    page1->setTitle(QStringLiteral("新建一个推送"));

    urlLabel = new QLabel;
    urlLabel->setText(QStringLiteral("请输入推送的URL地址，我们会对其进行解析"));
    urlLabel->setWordWrap(true);

    tipsLabel = new QLabel;
    tipsLabel->setText(QStringLiteral("温馨提示：提供RSS服务的网页往往有个类似左边图片的图标，点击后复制网址就OK啦！"));
    tipsLabel->setWordWrap(true);

    pixLabel = new QLabel;
    QPixmap pix("F:\\Qt_workplace\\RSStalk\\RSStalk\\RSStalk\\image\\RSS.png");
    pixLabel->setPixmap(pix);
    pixLabel->resize(QSize(pix.width(), pix.height()));

    urlLineEdit = new QLineEdit;
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
    page2 = new QWizardPage;
    page2->setTitle(QStringLiteral("给新的订阅取个名字吧"));

    nameLabel = new QLabel;
    nameLabel->setText(QStringLiteral("请输入这个订阅的标题："));

    nameLineEdit = new QLineEdit;

    chooseLabel = new QLabel;
    chooseLabel->setText(QStringLiteral("请选择一个分类文件夹："));

    /*将这个treewidget与主界面的treewidget内容同步*/
    folderTreeWidget = new QTreeWidget;
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

    newFolderBtn = new QPushButton;
    newFolderBtn->setText(QStringLiteral("新建文件夹"));

    QPixmap pixInPage2("F:\\Qt_workplace\\RSStalk\\RSStalk\\RSStalk\\image\\RSS.png");
    pixLabelInPage2 = new QLabel;
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

    /*初始化新建推送向导的第三页*/
    page3 = new QWizardPage;
    page3->setTitle(QStringLiteral("完成"));

    finishLabel = new QLabel;
    finishLabel->setText(QStringLiteral("点击finish完成新建订阅，我们将为您更新您的订阅列表"));
    //finishLabel->setWordWrap(true);

    QPixmap pixInPage3("F:\\Qt_workplace\\RSStalk\\RSStalk\\RSStalk\\image\\RSS.png");
    pixLabelInPage3 = new QLabel;
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

    wizard->setButtonText(QWizard::BackButton, QStringLiteral("上一步"));//设置向导中按钮的文字
    wizard->setButtonText(QWizard::NextButton, QStringLiteral("下一步"));
    wizard->setButtonText(QWizard::CancelButton, QStringLiteral("取消"));


    if (this->wizard->currentPage()->nextId() == 0)
    {
        //qDebug() << this->wizard->currentPage()->nextId();
        QAbstractButton *nextBtn = this->wizard->button(QWizard::NextButton);//获取QWizard向导中的下一步按钮
        if (this->urlLineEdit->text() != NULL)
        {
            connect(nextBtn, SIGNAL(clicked(bool)), this, SLOT(addSubcription()));
        }
    }

    /*连接新建推送的槽函数*/
    connect(newFolderBtn, SIGNAL(clicked()), this, SLOT(addFolderActionTriggered()));//在向导中新建文件夹

}

void MainWindow::addSubcription()
{
    qDebug() << "successful access to addSubcription";

    urlFrInput = "http://blog.zhaojie.me/rss";

    DownloadManager manager;
    manager.doDownload(urlFrInput);
}

void MainWindow::lineEditUrlEntered()
{
    QString url;
    if (ui->webEditLine->text() != NULL)
    {
        url = "https://" + ui->webEditLine->text();
    }
    else
        url = "http://sw.scu.edu.cn";

    ui->webView->load(url);
}



