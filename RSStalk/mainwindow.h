#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QAction>
#include <QMenuBar>
#include <QPushButton>
#include <QToolBar>
#include <QWebEngineView>
#include <QUrl>
#include <QSplitter>
#include <QDialog>
#include <QWizard>
#include <QLineEdit>
#include <QTreeWidget>
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
#include <QMap>
#include <QToolButton>
#include <QTime>
#include <QMovie>
#include <QRegExp>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QDir>
#include "ui_addfolder.h"
#include "feed.h"
#include "rss.h"
#include "atom.h"
#include "dbmanager.h"
#include "ui_renamedialog.h"

namespace Ui {
class MainWindow;
}

class MyWizard;//一定要先声明这个类，不然编译器会报错
class MyToolButton;
class MyAbstractionBtn;
class MyWizardPage;
class MyLineEdit;
class MyDialog;

//template<class T>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initGUI();//初始化某些界面部件
    void createToolBar();//创建工具栏
    void setWindowFont();//初始化所有部件的字体
    void initWindowIcon();

    void showParseResultExample();//渲染RSS源示例

    void downloadTest();//测试downloadManager

    void refreshFolderTreeWidget();
    void clearFolderTreeWidget();

    bool toolBoxHasRepeatChild(QString);
    bool treeWidgetHasRepeatChild(QTreeWidget*, QString);
    bool treeWidgetFolderHasRepeatChild(int, QString);
    int childItemIndexInToolBox(QString);

    int getCurrentToplevelItemIndex(QString);

    void showDefaultFromDB();//界面中显示数据库中存在的数据

private:
    Ui::MainWindow *ui;
    Ui::AddFolderDialog folderUi;
    Ui::renameDialog renameUi;

    DBManager *dbManager;
    QDialog *renameDialog;

    QMenu *treeWidgetBlankMenu;
    QMenu *treeWidgetMenu;
    QMenu *treeWidgetSubMenu;
    QMenu *toolBoxTitleMenu;

    QToolBar *fileTool;      //工具栏
    QToolBar *editTool;
    QToolBar *doToolBar;

    MyWizard* wizard;
    MyWizardPage *page1;
    MyWizardPage *page2;
    MyWizardPage *page3;
    //MyWizardPage *page4;

    QString urlFrInput;//从向导中获取出的字符串
    QString subsNameFrInput;
    QString folderNameFrInput;

    QLabel *urlLabel;//page1控件
    QLabel *tipsLabel;
    QLabel *pixLabel;
    QLineEdit *urlLineEdit;

    QLabel *nameLabel;//page2控件
    QLineEdit *nameLineEdit;
    QLabel *chooseLabel;
    QTreeWidget *folderTreeWidget;
    QPushButton *newFolderBtn;
    QLabel *pixLabelInPage2;

    QLabel *finishLabel;//page3控件
    QLabel *pixLabelInPage3;

//    QLabel *pixLabelInPage4;//page4控件
//    QLabel *downloadLabel;
//    QMovie *waitMovie;

    MyDialog *waitDialog;
    QLabel *waitGifLabel;
    QLabel *waitWordsLabel;
    QMovie *waitMovie;

    QDialog *dialog;//添加文件夹的对话框

    Feed *newFeed;//新建推送的feed

    QMap<QString, QString> treeWidgetList;

private slots:
    void addFolderActionTriggered();
    void addFolderToTreeWidget();
    void addSubcriptionActionTriggered();
    void renameActionTriggered();
    void renameDBRefresh();
    void lineEditUrlEntered();
    void on_treeWidget_title_clicked(QTreeWidgetItem*, int);//当点击treewidget中的文章标题后
    void on_toolBox_rightbtn_clicked(QPoint);
    void on_treeWidget_rightbtn_clicked(QPoint);
    void on_deleteAction_triggered();
    void on_deleteToolBox_triggered();
    void subsUrlEdited();

    void showHasNotFinishedInfo();

public slots:
    void addSubcription();
    void showArticleContent(QString, int);

signals:
    void downloadFinish();
    void wrongUrl();
    void noChoice();

};

class MyToolButton : public QToolButton//自定义一个toolbutton，里面自己添加想要的方法和属性
{
    Q_OBJECT

public:
    int pos;
    QString feedtitle;

    MyToolButton() { }
    ~MyToolButton() { }
    void mousePressEvent(QMouseEvent *);

signals:
    void myclicked(QString, int);
};

class MyAbstractionBtn : public QAbstractButton
{
    Q_OBJECT
public:
    MyAbstractionBtn();
    ~MyAbstractionBtn();

    void mousePressEvent(QMouseEvent *event);

signals:
    void myclicked();
};

class MyWizard : public QWizard
{
    Q_OBJECT
public:
    MyWizard() {}
    ~MyWizard(){}

    //bool downloaded = false;//判断是否下载成功

    bool validateCurrentPage();
};

class MyWizardPage : public QWizardPage
{
    Q_OBJECT
public:
    MyWizardPage() {}
    ~MyWizardPage() {}
};

class MyDialog : public QDialog
{
    Q_OBJECT
public:
    MyDialog() {}
    ~MyDialog() {}

    void closeEvent(QCloseEvent *);

public:
    bool isQuit = false;
    bool fromUserClicked = false;
};

#endif // MAINWINDOW_H
