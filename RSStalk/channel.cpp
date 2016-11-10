#include "channel.h"
#include<QTextBrowser>
#include"QList"
#include"channel_user.h"
#include<QException>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include<QDebug>
channel::channel()
{
    wg=new QWidget();
    qhl=new QHBoxLayout(wg);
    tb=new QTextBrowser();
    lw=new QListWidget();
    qhl->addWidget(tb);
    qhl->addWidget(lw);
    qhl->setStretchFactor(tb,5);
    qhl->setStretchFactor(lw,2);
    user_list.clear();
}

QTextBrowser& channel::get_textbroswer()
{
    return *tb;
}

QWidget& channel::get_widget()
{
    return *wg;
}

QHBoxLayout& channel::get_layout()
{
    return *qhl;
}

QListWidget& channel::get_listwidget()
{
    return *lw;
}

channel::~channel()
{
    delete tb;
    delete lw;
    delete qhl;
}

int channel::get_channel_id()
{
    return channel_id;
}

QString& channel::get_channel_name()
{
    return channel_name;
}

QString& channel::get_channel_theme()
{
    return channel_theme;
}

QString& channel::get_channel_operator()
{
    return channel_operator;
}

QString& channel::get_channel_keyword1()
{
    return key_word1;
}

QString& channel::get_channel_keyword2()
{
    return key_word2;
}

QString& channel::get_channel_keyword3()
{
    return key_word3;
}

QTextBrowser& channel::get_TextBroswer()
{
    return *tb;
}

void channel::set_channel_id(int id)
{
    channel_id=id;
}

void channel::set_channel_name(QString name)
{
    channel_name=name;
}

void channel::set_channel_theme(QString theme)
{
    channel_theme=theme;
}

void channel::set_channel_operator(QString op_name)
{
    channel_operator=op_name;
}

void channel::set_channel_keyword1(QString k1)
{
    key_word1=k1;
}

void channel::set_channel_keyword2(QString k2)
{
    key_word2=k2;
}

void channel::set_channel_keyword3(QString k3)
{
    key_word3=k3;
}

void channel::add_user(channel_user* u)
{
    user_list.push_back(u);
}

void channel::del_user(channel_user* u)
{
    for(int i=0;i<user_list.size();i++)
    {
        if((*user_list[i]).get_user_id()==u->get_user_id())
        {
            //channel_user& tmp=user_list.removeAt(i);//memery leak
            user_list.removeAt(i);
            //delete tmp;
            return;
        }
    }
}

void channel::update_view()
{
    lw->clear();
    for(int i=0;i<user_list.size();i++)
    {
        lw->addItem(user_list[i]->get_user_name());
        qDebug()<<__LINE__<< user_list.size();
    }
}

int channel::get_tab_index()
{
    return tab_index;
}

void channel::set_tab_index(int i)
{
    tab_index=i;
}

void channel::show_msg(QString msg)
{
    tb->append(msg);
}
