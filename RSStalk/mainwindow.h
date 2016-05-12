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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createToolBar();//创建工具栏
    void setWindowFont();//初始化所有部件的字体

private:
    Ui::MainWindow *ui;

    QToolBar *fileTool;      //工具栏
    QToolBar *editTool;
    QToolBar *doToolBar;

private slots:
    void addFolderActionTriggered();
    void addSubcriptionActionTriggered();

};

#endif // MAINWINDOW_H
