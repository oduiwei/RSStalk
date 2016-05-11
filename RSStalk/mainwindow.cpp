#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("RSStalk");
    setWindowIcon(QIcon(":/new/prefix/image/RSStalk.png"));

    createToolBar();//创建工具栏

    ui->webView1->load(QUrl("http://www.baidu.com")); //设置界面中的网页加载的网页
    ui->webView2->load(QUrl("http://sw.scu.edu.cn"));

    ui->splitter->setStretchFactor(0, 2);//优化界面中的分裂窗口
    ui->splitter->setStretchFactor(1, 6);
    ui->splitter->setStretchFactor(2, 4);

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
