#ifndef CHANNEL_H
#define CHANNEL_H
#include<QString>
#include<QList>
#include"user.h"
#include<QTextBrowser>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include<QListWidget>
#include"channel_user.h"

class channel
{
public:
    channel();
    ~channel();
    int get_channel_id();
    QString& get_channel_name();
    QString& get_channel_theme();
    QString& get_channel_operator();
    QString& get_channel_keyword1();
    QString& get_channel_keyword2();
    QString& get_channel_keyword3();
    QTextBrowser& get_textbroswer();
    QHBoxLayout& get_layout();
    QListWidget& get_listwidget();
    QTextBrowser& get_TextBroswer();
    QWidget& get_widget();
    void set_channel_id(int);
    void set_channel_name(QString);
    void set_channel_theme(QString);
    void set_channel_operator(QString);
    void set_channel_keyword1(QString);
    void set_channel_keyword2(QString);
    void set_channel_keyword3(QString);
    void add_user(channel_user*);
    void del_user(channel_user*);
    void update_view();
    void show_msg(QString);
    int get_tab_index();
    void set_tab_index(int);


    QWidget*wg;
    QTextBrowser*tb;
    QList<channel_user*> user_list;
    QListWidget*lw;
    QHBoxLayout*qhl;
private:
    int channel_id;
    int tab_index;
    QString channel_name;
    QString channel_theme;
    QString channel_operator;
    QString key_word1;
    QString key_word2;
    QString key_word3;


};

#endif // CHANNEL_H
