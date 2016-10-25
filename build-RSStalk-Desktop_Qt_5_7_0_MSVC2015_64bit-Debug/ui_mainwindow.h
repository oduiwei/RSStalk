/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qwebengineview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *newSubscriptionAcion;
    QAction *newFolderAction;
    QAction *manageCacheAction;
    QAction *exitAction;
    QAction *markAllReadAction;
    QAction *importFileAction;
    QAction *exportFileAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *cutAction;
    QAction *zoomInAction;
    QAction *zoomOutAction;
    QAction *undoAction;
    QAction *doAction;
    QAction *deleteFolderAction;
    QAction *deleteSubAction;
    QAction *deleteToolBoxAction;
    QAction *renameAction;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *leftVLayout;
    QTreeWidget *treeWidget;
    QVBoxLayout *leftBottomVLayout;
    QToolButton *IRCToolBtn;
    QToolButton *webToolBtn;
    QToolButton *releaseToolBtn;
    QToolButton *shareToolBtn;
    QToolButton *feedbackToolBtn;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QToolBox *toolBox;
    QWidget *page1;
    QWidget *layoutWidget2;
    QVBoxLayout *RightVLayout;
    QHBoxLayout *rightUpHLayout;
    QSpacerItem *horizontalSpacer;
    QLineEdit *webEditLine;
    QToolButton *aheadToolBtn;
    QToolButton *backToolBtn;
    QToolButton *refreshToolBtn;
    QToolButton *newTabToolBtn;
    QTabWidget *tabWidget;
    QWebEngineView *webView;
    QMenuBar *menuBar;
    QMenu *file_menu;
    QMenu *importOrExport_2;
    QMenu *edit_menu;
    QMenu *view_menu;
    QMenu *browse_menu;
    QMenu *favorite_menu;
    QMenu *tool_menu;
    QMenu *help_menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1215, 806);
        newSubscriptionAcion = new QAction(MainWindow);
        newSubscriptionAcion->setObjectName(QStringLiteral("newSubscriptionAcion"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ico/image/RSS.png"), QSize(), QIcon::Normal, QIcon::Off);
        newSubscriptionAcion->setIcon(icon);
        newFolderAction = new QAction(MainWindow);
        newFolderAction->setObjectName(QStringLiteral("newFolderAction"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/ico/image/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        newFolderAction->setIcon(icon1);
        manageCacheAction = new QAction(MainWindow);
        manageCacheAction->setObjectName(QStringLiteral("manageCacheAction"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/ico/image/ManageCache (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        manageCacheAction->setIcon(icon2);
        exitAction = new QAction(MainWindow);
        exitAction->setObjectName(QStringLiteral("exitAction"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/ico/image/sign_out (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        exitAction->setIcon(icon3);
        markAllReadAction = new QAction(MainWindow);
        markAllReadAction->setObjectName(QStringLiteral("markAllReadAction"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/ico/image/mark_read (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        markAllReadAction->setIcon(icon4);
        importFileAction = new QAction(MainWindow);
        importFileAction->setObjectName(QStringLiteral("importFileAction"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/ico/image/in (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        importFileAction->setIcon(icon5);
        exportFileAction = new QAction(MainWindow);
        exportFileAction->setObjectName(QStringLiteral("exportFileAction"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/ico/image/sing_out (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        exportFileAction->setIcon(icon6);
        copyAction = new QAction(MainWindow);
        copyAction->setObjectName(QStringLiteral("copyAction"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/ico/image/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        copyAction->setIcon(icon7);
        pasteAction = new QAction(MainWindow);
        pasteAction->setObjectName(QStringLiteral("pasteAction"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/ico/image/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        pasteAction->setIcon(icon8);
        cutAction = new QAction(MainWindow);
        cutAction->setObjectName(QStringLiteral("cutAction"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/ico/image/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        cutAction->setIcon(icon9);
        zoomInAction = new QAction(MainWindow);
        zoomInAction->setObjectName(QStringLiteral("zoomInAction"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/ico/image/zoomin.png"), QSize(), QIcon::Normal, QIcon::Off);
        zoomInAction->setIcon(icon10);
        zoomOutAction = new QAction(MainWindow);
        zoomOutAction->setObjectName(QStringLiteral("zoomOutAction"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/ico/image/zoomout.png"), QSize(), QIcon::Normal, QIcon::Off);
        zoomOutAction->setIcon(icon11);
        undoAction = new QAction(MainWindow);
        undoAction->setObjectName(QStringLiteral("undoAction"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/ico/image/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        undoAction->setIcon(icon12);
        doAction = new QAction(MainWindow);
        doAction->setObjectName(QStringLiteral("doAction"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/ico/image/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        doAction->setIcon(icon13);
        deleteFolderAction = new QAction(MainWindow);
        deleteFolderAction->setObjectName(QStringLiteral("deleteFolderAction"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/ico/image/delete_fileFolder (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteFolderAction->setIcon(icon14);
        deleteSubAction = new QAction(MainWindow);
        deleteSubAction->setObjectName(QStringLiteral("deleteSubAction"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/ico/image/delete_Sub (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteSubAction->setIcon(icon15);
        deleteToolBoxAction = new QAction(MainWindow);
        deleteToolBoxAction->setObjectName(QStringLiteral("deleteToolBoxAction"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/ico/image/delete_filelist (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteToolBoxAction->setIcon(icon16);
        renameAction = new QAction(MainWindow);
        renameAction->setObjectName(QStringLiteral("renameAction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setAutoFillBackground(false);
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        leftVLayout = new QVBoxLayout(layoutWidget);
        leftVLayout->setSpacing(0);
        leftVLayout->setContentsMargins(11, 11, 11, 11);
        leftVLayout->setObjectName(QStringLiteral("leftVLayout"));
        leftVLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(layoutWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignCenter);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        sizePolicy.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy);
        treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);

        leftVLayout->addWidget(treeWidget);

        leftBottomVLayout = new QVBoxLayout();
        leftBottomVLayout->setSpacing(0);
        leftBottomVLayout->setObjectName(QStringLiteral("leftBottomVLayout"));
        IRCToolBtn = new QToolButton(layoutWidget);
        IRCToolBtn->setObjectName(QStringLiteral("IRCToolBtn"));
        IRCToolBtn->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(IRCToolBtn->sizePolicy().hasHeightForWidth());
        IRCToolBtn->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        IRCToolBtn->setFont(font);

        leftBottomVLayout->addWidget(IRCToolBtn);

        webToolBtn = new QToolButton(layoutWidget);
        webToolBtn->setObjectName(QStringLiteral("webToolBtn"));
        sizePolicy1.setHeightForWidth(webToolBtn->sizePolicy().hasHeightForWidth());
        webToolBtn->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        webToolBtn->setFont(font1);

        leftBottomVLayout->addWidget(webToolBtn);

        releaseToolBtn = new QToolButton(layoutWidget);
        releaseToolBtn->setObjectName(QStringLiteral("releaseToolBtn"));
        sizePolicy1.setHeightForWidth(releaseToolBtn->sizePolicy().hasHeightForWidth());
        releaseToolBtn->setSizePolicy(sizePolicy1);
        releaseToolBtn->setFont(font1);

        leftBottomVLayout->addWidget(releaseToolBtn);

        shareToolBtn = new QToolButton(layoutWidget);
        shareToolBtn->setObjectName(QStringLiteral("shareToolBtn"));
        sizePolicy1.setHeightForWidth(shareToolBtn->sizePolicy().hasHeightForWidth());
        shareToolBtn->setSizePolicy(sizePolicy1);
        shareToolBtn->setFont(font1);

        leftBottomVLayout->addWidget(shareToolBtn);

        feedbackToolBtn = new QToolButton(layoutWidget);
        feedbackToolBtn->setObjectName(QStringLiteral("feedbackToolBtn"));
        sizePolicy1.setHeightForWidth(feedbackToolBtn->sizePolicy().hasHeightForWidth());
        feedbackToolBtn->setSizePolicy(sizePolicy1);
        feedbackToolBtn->setFont(font1);

        leftBottomVLayout->addWidget(feedbackToolBtn);


        leftVLayout->addLayout(leftBottomVLayout);

        leftVLayout->setStretch(0, 7);
        leftVLayout->setStretch(1, 3);
        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setPointSize(12);
        label->setFont(font2);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        toolBox = new QToolBox(layoutWidget1);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        sizePolicy.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setUnderline(true);
        toolBox->setFont(font3);
        toolBox->setContextMenuPolicy(Qt::CustomContextMenu);
        page1 = new QWidget();
        page1->setObjectName(QStringLiteral("page1"));
        page1->setGeometry(QRect(0, 0, 260, 692));
        toolBox->addItem(page1, QStringLiteral(""));

        verticalLayout->addWidget(toolBox);

        verticalLayout->setStretch(1, 1);
        splitter->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(splitter);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        RightVLayout = new QVBoxLayout(layoutWidget2);
        RightVLayout->setSpacing(6);
        RightVLayout->setContentsMargins(11, 11, 11, 11);
        RightVLayout->setObjectName(QStringLiteral("RightVLayout"));
        RightVLayout->setContentsMargins(0, 0, 0, 0);
        rightUpHLayout = new QHBoxLayout();
        rightUpHLayout->setSpacing(6);
        rightUpHLayout->setObjectName(QStringLiteral("rightUpHLayout"));
        horizontalSpacer = new QSpacerItem(118, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        rightUpHLayout->addItem(horizontalSpacer);

        webEditLine = new QLineEdit(layoutWidget2);
        webEditLine->setObjectName(QStringLiteral("webEditLine"));
        sizePolicy.setHeightForWidth(webEditLine->sizePolicy().hasHeightForWidth());
        webEditLine->setSizePolicy(sizePolicy);
        webEditLine->setMaxLength(32782);

        rightUpHLayout->addWidget(webEditLine);

        aheadToolBtn = new QToolButton(layoutWidget2);
        aheadToolBtn->setObjectName(QStringLiteral("aheadToolBtn"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(aheadToolBtn->sizePolicy().hasHeightForWidth());
        aheadToolBtn->setSizePolicy(sizePolicy3);
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/ico/image/forward (2) - \345\211\257\346\234\254.png"), QSize(), QIcon::Selected, QIcon::On);
        aheadToolBtn->setIcon(icon17);

        rightUpHLayout->addWidget(aheadToolBtn);

        backToolBtn = new QToolButton(layoutWidget2);
        backToolBtn->setObjectName(QStringLiteral("backToolBtn"));
        sizePolicy3.setHeightForWidth(backToolBtn->sizePolicy().hasHeightForWidth());
        backToolBtn->setSizePolicy(sizePolicy3);
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/ico/image/forward (2).png"), QSize(), QIcon::Selected, QIcon::On);
        backToolBtn->setIcon(icon18);

        rightUpHLayout->addWidget(backToolBtn);

        refreshToolBtn = new QToolButton(layoutWidget2);
        refreshToolBtn->setObjectName(QStringLiteral("refreshToolBtn"));
        sizePolicy3.setHeightForWidth(refreshToolBtn->sizePolicy().hasHeightForWidth());
        refreshToolBtn->setSizePolicy(sizePolicy3);
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/ico/image/rotate90.png"), QSize(), QIcon::Selected, QIcon::On);
        refreshToolBtn->setIcon(icon19);

        rightUpHLayout->addWidget(refreshToolBtn);

        newTabToolBtn = new QToolButton(layoutWidget2);
        newTabToolBtn->setObjectName(QStringLiteral("newTabToolBtn"));
        sizePolicy3.setHeightForWidth(newTabToolBtn->sizePolicy().hasHeightForWidth());
        newTabToolBtn->setSizePolicy(sizePolicy3);
        QIcon icon20;
        icon20.addFile(QStringLiteral(":/ico/image/create_new page (2).png"), QSize(), QIcon::Selected, QIcon::On);
        newTabToolBtn->setIcon(icon20);

        rightUpHLayout->addWidget(newTabToolBtn);

        rightUpHLayout->setStretch(0, 2);
        rightUpHLayout->setStretch(1, 3);

        RightVLayout->addLayout(rightUpHLayout);

        tabWidget = new QTabWidget(layoutWidget2);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        webView = new QWebEngineView();
        webView->setObjectName(QStringLiteral("webView"));
        tabWidget->addTab(webView, QString());

        RightVLayout->addWidget(tabWidget);

        RightVLayout->setStretch(1, 1);
        splitter->addWidget(layoutWidget2);

        horizontalLayout_3->addWidget(splitter);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1215, 26));
        file_menu = new QMenu(menuBar);
        file_menu->setObjectName(QStringLiteral("file_menu"));
        importOrExport_2 = new QMenu(file_menu);
        importOrExport_2->setObjectName(QStringLiteral("importOrExport_2"));
        edit_menu = new QMenu(menuBar);
        edit_menu->setObjectName(QStringLiteral("edit_menu"));
        view_menu = new QMenu(menuBar);
        view_menu->setObjectName(QStringLiteral("view_menu"));
        browse_menu = new QMenu(menuBar);
        browse_menu->setObjectName(QStringLiteral("browse_menu"));
        favorite_menu = new QMenu(menuBar);
        favorite_menu->setObjectName(QStringLiteral("favorite_menu"));
        tool_menu = new QMenu(menuBar);
        tool_menu->setObjectName(QStringLiteral("tool_menu"));
        help_menu = new QMenu(menuBar);
        help_menu->setObjectName(QStringLiteral("help_menu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(file_menu->menuAction());
        menuBar->addAction(edit_menu->menuAction());
        menuBar->addAction(view_menu->menuAction());
        menuBar->addAction(browse_menu->menuAction());
        menuBar->addAction(favorite_menu->menuAction());
        menuBar->addAction(tool_menu->menuAction());
        menuBar->addAction(help_menu->menuAction());
        file_menu->addAction(newSubscriptionAcion);
        file_menu->addAction(newFolderAction);
        file_menu->addAction(deleteFolderAction);
        file_menu->addAction(deleteSubAction);
        file_menu->addAction(deleteToolBoxAction);
        file_menu->addSeparator();
        file_menu->addAction(importOrExport_2->menuAction());
        file_menu->addSeparator();
        file_menu->addAction(manageCacheAction);
        file_menu->addSeparator();
        file_menu->addAction(exitAction);
        importOrExport_2->addAction(importFileAction);
        importOrExport_2->addAction(exportFileAction);
        edit_menu->addAction(markAllReadAction);
        edit_menu->addAction(renameAction);
        edit_menu->addSeparator();
        edit_menu->addAction(copyAction);
        edit_menu->addAction(pasteAction);
        edit_menu->addAction(cutAction);
        edit_menu->addAction(zoomInAction);
        edit_menu->addAction(zoomOutAction);
        edit_menu->addSeparator();
        edit_menu->addAction(undoAction);
        edit_menu->addAction(doAction);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        newSubscriptionAcion->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\216\250\351\200\201", 0));
        newSubscriptionAcion->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0));
        newFolderAction->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266\345\244\271", 0));
        newFolderAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+N", 0));
        manageCacheAction->setText(QApplication::translate("MainWindow", "\347\256\241\347\220\206\347\274\223\345\255\230", 0));
        exitAction->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        markAllReadAction->setText(QApplication::translate("MainWindow", "\346\240\207\350\256\260\346\211\200\346\234\211\346\226\207\347\253\240\344\270\272\345\267\262\350\257\273", 0));
        importFileAction->setText(QApplication::translate("MainWindow", "\344\273\216\346\234\254\345\234\260\345\257\274\345\205\245", 0));
        exportFileAction->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272\345\210\260\346\234\254\345\234\260", 0));
        copyAction->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266", 0));
        pasteAction->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264", 0));
        cutAction->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207", 0));
        zoomInAction->setText(QApplication::translate("MainWindow", "\346\224\276\345\244\247", 0));
        zoomOutAction->setText(QApplication::translate("MainWindow", "\347\274\251\345\260\217", 0));
        undoAction->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200", 0));
        doAction->setText(QApplication::translate("MainWindow", "\351\207\215\345\201\232", 0));
        deleteFolderAction->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\346\226\207\344\273\266\345\244\271", 0));
        deleteSubAction->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\350\256\242\351\230\205", 0));
        deleteToolBoxAction->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\346\226\207\347\253\240\345\210\227\350\241\250", 0));
        renameAction->setText(QApplication::translate("MainWindow", "\351\207\215\345\221\275\345\220\215", 0));
        renameAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+M", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "\350\256\242\351\230\205\345\206\205\345\256\271", 0));
        IRCToolBtn->setText(QApplication::translate("MainWindow", "\350\275\254\345\210\260IRC", 0));
        webToolBtn->setText(QApplication::translate("MainWindow", "\350\275\254\345\210\260\347\275\221\351\241\265", 0));
        releaseToolBtn->setText(QApplication::translate("MainWindow", "\346\210\221\350\246\201\345\217\221\345\270\203", 0));
        shareToolBtn->setText(QApplication::translate("MainWindow", "\345\210\206\344\272\253\345\210\260", 0));
        feedbackToolBtn->setText(QApplication::translate("MainWindow", "\346\210\221\350\246\201\345\217\215\351\246\210", 0));
        label->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", 0));
        toolBox->setItemText(toolBox->indexOf(page1), QString());
        aheadToolBtn->setText(QApplication::translate("MainWindow", ">>", 0));
        backToolBtn->setText(QApplication::translate("MainWindow", "<<", 0));
        refreshToolBtn->setText(QApplication::translate("MainWindow", "<<", 0));
        newTabToolBtn->setText(QApplication::translate("MainWindow", "+", 0));
        tabWidget->setTabText(tabWidget->indexOf(webView), QApplication::translate("MainWindow", "Tab 1", 0));
        file_menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", 0));
        importOrExport_2->setTitle(QApplication::translate("MainWindow", "\345\257\274\345\205\245/\345\257\274\345\207\272", 0));
        edit_menu->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", 0));
        view_menu->setTitle(QApplication::translate("MainWindow", "\346\237\245\347\234\213(&V)", 0));
        browse_menu->setTitle(QApplication::translate("MainWindow", "\346\265\217\350\247\210(&B)", 0));
        favorite_menu->setTitle(QApplication::translate("MainWindow", "\346\224\266\350\227\217(&A)", 0));
        tool_menu->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267(&T)", 0));
        help_menu->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
