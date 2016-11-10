#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef IRC_WINDOW_H
#define IRC_WINDOW_H
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
#include <QWidget>
#include <QString>
#include <QUdpSocket>
#include<QList>
#include<QFile>
#include <QHostInfo>
#include"find_channel.h"
#include"create_channel.h"
#include"emoji.h"
#include "channel.h"
#include"channel_user.h"
#include"user.h"
#include"feedback.h"
#include"join_channel.h"

namespace Ui {
class Irc_window;
}

class Irc_window : public QWidget
{
    Q_OBJECT

public:
    explicit Irc_window(QWidget *parent = 0);
    ~Irc_window();
    void get_content(char*,char*);
    void get_content0(char*,char*);
    void insert_channel(channel*);
    channel_user* get_user(int,QString);
    channel* get_channel(int,QString);
    bool user_exist(channel_user&);
    int get_channel_id(int);

    QList<channel*> channel_list;
    emoji *emoji_window;
    find_channel *channel_finder_window;
    create_channel *channel_creator_window;
    feedback *feedback_window;
    join_channel*join_window;
    QString server_addr;
    qint16 port;
    int my_id;
    QUdpSocket *socket;
    Ui::Irc_window *ui;
    user myself;
    QTime qt;
private:
private slots:
    void process_pending_datagrams();
    void emoji_clicked();
    void create_c_clicked();
    void find_c_clicked();
    void send_msg();
    void join();
    void hideme();
    void feedback_f();
    void part();

signals:

};

#endif // IRC_WINDOW_H
