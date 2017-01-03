#include "irc_window.h"
#include "ui_irc_window.h"
#include<QTime>
#include<QString>
#include<QUdpSocket>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include<QList>
#include"channel.h"
#include"user.h"
#include"channel_user.h"

Irc_window::Irc_window(QWidget *parent,QToolButton*btn) :
    QWidget(parent),mybtn(btn),
    ui(new Ui::Irc_window)
{
    ui->setupUi(this);
    ui->irc_chat_body->removeTab(1);
    ui->irc_chat_body->tabBarAutoHide();
    QFont ft("Microsoft YaHei",  12,   75);
    ui->irc_chat_body->setFont(ft);
    ui->irc_chat_body->setStyleSheet("QTabWidget {"
                                    "background-color: rgb(230,237,249);"
                                "}"
                                );
    myself.set_user_id(-1);
    myself.set_user_name("guest");
    setMinimumWidth(861);
    setMinimumHeight(568);
    /*QWidget*tmpaa=new QWidget();
    QHBoxLayout*newql=new QHBoxLayout(tmpaa);
    QTextBrowser*tmp=new QTextBrowser();
    QListWidget*tmpp=new QListWidget();
    newql->addWidget(tmp);
    newql->addWidget(tmpp);
    newql->setStretchFactor(tmp,7);
    newql->setStretchFactor(tmpp,2);
    ui->irc_chat_body->addTab(tmpaa,"test");*/


    server_addr="119.29.111.145";
    //server_addr="192.168.56.102";
    port=8008;
    socket=new QUdpSocket(this);
    socket->bind(port,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    connect(socket,SIGNAL(readyRead()),this,SLOT(process_pending_datagrams()));

    emoji_window=new emoji();
    emoji_window->hide();

    channel_creator_window=new create_channel();
    channel_creator_window->hide();

    channel_finder_window=new find_channel();
    channel_finder_window->hide();

    feedback_window=new feedback();
    feedback_window->hide();

    join_window=new join_channel();
    join_window->hide();

    connect(ui->emoji_btn, SIGNAL(clicked(bool)), this, SLOT(emoji_clicked()));
    connect(ui->create_c_btn, SIGNAL(clicked(bool)), this, SLOT(create_c_clicked()));
    connect(ui->find_c_btn, SIGNAL(clicked(bool)), this, SLOT(find_c_clicked()));
    connect(ui->send_btn,SIGNAL(clicked(bool)),this,SLOT(send_msg()));
    connect(ui->join_btn,SIGNAL(clicked(bool)),this,SLOT(join()));
    connect(ui->hide_btn,SIGNAL(clicked(bool)),this,SLOT(hideme()));
    connect(ui->feedback_btn,SIGNAL(clicked(bool)),this,SLOT(feedback_f()));
    connect(ui->part_btn,SIGNAL(clicked(bool)),this,SLOT(part()));

    ui->emoji_btn->setStyleSheet(    "QPushButton{border-image: url(Resources/images/BreadCrumbNavigation/navigation_more_normal.png);}"
                                     "QPushButton:hover{border-image: url(Resources/images/BreadCrumbNavigation/navigation_more_hover.png);}"
                                     "QPushButton:pressed{border-image: url(Resources/images/BreadCrumbNavigation/navigation_more_pressed.png);}");

    QString welcome="欢迎使用迷你irc聊天室v1.0。在这里，您可以尽情享受与陌生人聊天交流的乐趣；在这里，您可以随心讨论任何合乎国家法律法规的题目；在这里，即来即聊，聊完即走的特性使得您无需当心隐私的安全:)";
    ui->welcome_text_broswer->setFont(ft);
    ui->welcome_text_broswer->setText("["+qt.currentTime().toString()+"]"+"系统消息");
    ui->welcome_text_broswer->append(welcome);

    qDebug() << __LINE__ <<qt.currentTime().toString();

    int length=0;
    //QTextCodec*code=QTextCodec::codecForName("GBK");
    qDebug() << __LINE__ <<"sent "<<this->ui->send_msg_text_edit->toPlainText();
    if((length=socket->writeDatagram("/hello",6,QHostAddress(server_addr),port))!=6)
    {
        qDebug() << __LINE__ <<"error";
        return;
    }



    QFile file("nick");
    if(file.exists())
    {
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             qDebug()<< __LINE__ <<"open failed";

        QTextStream in(&file);
        QString line("/nick ");
        QString tmp;
        tmp=in.readLine();
        line+=tmp;
        if((length=socket->writeDatagram(line.toUtf8(),line.toUtf8().length(),QHostAddress(server_addr),port))!=line.toUtf8().length())
        {
            qDebug() << __LINE__ <<"error";
            return;
        }
        ui->nick_label->setText(tmp);
    }
    else
    {

        QString line("/nick ");
        QString nick("guest");
        char tmp[7];
        sprintf(tmp,"%d%d",qt.currentTime().second(),qt.currentTime().msec());
        QString tmps(tmp);
        nick+=tmp;
        line+=nick;

        if((length=socket->writeDatagram(line.toUtf8(),line.toUtf8().length(),QHostAddress(server_addr),port))!=line.toUtf8().length())
        {
            qDebug() << __LINE__ <<"error";
            return;
        }
        QFile file("nick");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream out(&file);
        out << nick.toUtf8();

    }



    QString localhostName = QHostInfo::localHostName();
    ui->hostname_label->setText(localhostName);

    QHostInfo info = QHostInfo::fromName(localhostName);

    foreach(QHostAddress address,info.addresses())
    {
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
           ui->ip_label->setText(address.toString());
    }

    /*if(myself.get_user_id()!=-1)
    {
        QString id(myself.get_user_id());
        ui->id_label->setText(id);
    }
    else
    {
        QErrorMessage box(this);
        box.setWindowTitle(tr("错误提示框"));
        box.showMessage(tr("网络忙，请重启应用！"));
        box.exec();
    }
    QErrorMessage box(this);
    box.setWindowTitle(tr("错误提示框"));
    box.showMessage(tr("网络忙，请重启应用！"));
    box.exec();*/
    //qDebug() << __LINE__ <<myself.get_user_id();
    //this->ui->send_msg_text_edit->cut();
    //this->ui->send_msg_text_edit->clear();

    //channel_list=new QList<channel>();
}

Irc_window::~Irc_window()
{
    //~emoji_window();
    //~channel_finder_window();
    //~channel_creator_window();
    //~feedback_window();
    //delete channel_list;
    delete ui;
}

void Irc_window::join()
{
    join_window->show();
}

void Irc_window::insert_channel(channel*c)
{
    channel_list.push_back(c);
    qDebug() << __LINE__ <<"new channel added:"<<c->get_channel_name();
}

channel_user* Irc_window::get_user(int id,QString name)
{
    if(id>=0)
    {
        for(int i=0;i<channel_list.size();i++)
        {
            for(int j=0;j<channel_list[i]->user_list.size();j++)
            {
                if((*channel_list[i]->user_list[j]).get_user_id() ==id)
                    return channel_list[i]->user_list[j];
            }
        }
    }
    else
    {
        for(int i=0;i<channel_list.size();i++)
        {
            for(int j=0;j<channel_list[i]->user_list.size();j++)
            {
                if((*channel_list[i]->user_list[j]).get_user_name()==name)
                    return channel_list[i]->user_list[j];
            }
        }
    }

    return NULL;
}

channel* Irc_window::get_channel(int id,QString name)
{
    if(id>=0)
    {
        for(int i=0;i<channel_list.size();i++)
        {
            if(channel_list[i]->get_channel_id()==id)
                return channel_list[i];
        }
    }
    else
    {
        for(int i=0;i<channel_list.size();i++)
        {
            if(channel_list[i]->get_channel_name()==name)
                return channel_list[i];
        }
    }
    return NULL;
}

bool Irc_window::user_exist(channel_user&u)
{
    for(int i=0;i<channel_list.size();i++)
    {

        for(int j=0;j<channel_list[i]->user_list.size();j++)
        {
            if(u.get_user_id()==(*channel_list[i]->user_list[j]).get_user_id())
                return true;
        }
    }
    return false;
}

void Irc_window::process_pending_datagrams()
{
    while(socket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(socket->pendingDatagramSize());
        socket->readDatagram(datagram.data(),datagram.size());

        if(0==strncmp(datagram.data(),"/hello",6))//tested
        {
            qDebug() << __LINE__ <<"/hello entered";
            char num[10];
            get_content(num,datagram.data());
            int user_id=atoi(num);
            myself.set_user_id(user_id);
            ui->id_label->setText(num);
            qDebug() << __LINE__ << "myself.id set:" <<num;
        }
        else if(0==strncmp(datagram.data(),"/nick",5))
        {
            qDebug() << __LINE__ <<"/nick entered";
            char tmp[64];
            char num[10];
            char name[21];
            get_content(tmp,datagram.data());
            get_content(name,tmp);
            get_content0(num,tmp);
            int id=atoi(num);
            if(id==myself.get_user_id())//tested
            {
                QString tmpname(name);
                tmpname.toUtf8();
                myself.set_user_name(tmpname);
                ui->nick_label->setText(name);
                channel_user *u=get_user(myself.get_user_id(),NULL);
                if(u==NULL)return;
                u->set_user_name(name);
                for(int i=0;i<channel_list.size();i++)
                {
                    channel_list[i]->update_view();
                }
                qDebug() << __LINE__ << "myself.name set:" <<tmpname;
            }
            else
            {
                qDebug() << __LINE__ <<"begin";
                channel_user* u=get_user(id,NULL);

                if(u==NULL)return;
                u->set_user_name(name);
                for(int i=0;i<channel_list.size();i++)
                {
                    channel_list[i]->update_view();
                }
                QString message("[");
                message+=qt.currentTime().toString();
                message+="]系统消息";
                ui->welcome_text_broswer->append(message);
                message.clear();
                message+="用户:";
                message+=num;
                message+=" 更名为";
                message+=name;
                ui->welcome_text_broswer->append(message);
            }
        }
        else if(0==strncmp(datagram.data(),"/quit",5))
        {
            qDebug() << __LINE__ <<"/quit entered";
            char tmp[64];
            char num[10];
            char msg[1024];
            get_content(tmp,datagram.data());
            get_content(msg,tmp);
            get_content0(num,tmp);
            int id=atoi(num);
            channel_user *u=get_user(id,NULL);
            if(u==NULL)return;
            QString message("[");
            message+=qt.currentTime().toString();
            message+="]系统消息";
            ui->welcome_text_broswer->append(message);
            message.clear();
            message+="用户:";
            message+=u->get_user_name();
            message+=" 下线了并留了留言:";
            message+=msg;
            ui->welcome_text_broswer->append(message);
            u->set_user_alive(false);
            for(int i=0;i<channel_list.size();i++)
            {
                channel_list[i]->update_view();
            }
        }
        else if(0==strncmp(datagram.data(),"/die",4))
        {
            qDebug() << __LINE__ <<"/die entered";
            char num[10];
            get_content(num,datagram.data());
            int userid=atoi(num);
            for(int i=1;i<channel_list.size();i++)
            {
                for(int j=0;j<channel_list[i]->user_list.size();j++)
                {
                    if(channel_list[i]->user_list[j]->get_user_id()==userid)
                    {
                        channel_list[i]->del_user(channel_list[i]->user_list[j]);
						channel_list[i]->update_view();
						break;
                    }
                }
                
            }
        }
        else if(0==strncmp(datagram.data(),"/heart",6))
        {
            qDebug() << __LINE__ <<"/heart entered";
            QString tmp("/heart");
            int length=0;
            qDebug() << __LINE__ <<"sent "<<tmp;
            if((length=socket->writeDatagram(tmp.toUtf8(),tmp.toUtf8().length(),QHostAddress(server_addr),port))!=tmp.toUtf8().length())
            {
                qDebug() << __LINE__ <<"error";
                return;
            }
        }
        else if(0==strncmp(datagram.data(),"/part",5))
        {
            qDebug() << __LINE__ <<"/part entered"<<datagram.data();
            char tmp[64];
            char userid[10];
            char channelid[10];
            get_content(tmp,datagram.data());
            get_content(channelid,tmp);
            get_content0(userid,tmp);
            int uid=atoi(userid);
            int cid=atoi(channelid);
            channel_user*u=get_user(uid,NULL);
            if(u==NULL)
            {
                qDebug() << __LINE__ <<"error accur";
                return;
            }
            channel*c=get_channel(cid,NULL);
            if(c==NULL)
            {
                qDebug() << __LINE__ <<"error accur";
                return;
            }
            QString message("[");
            message+=qt.currentTime().toString();
            message+="]系统消息";
            ui->welcome_text_broswer->append(message);
            message.clear();
            message+="用户:";
            message+=u->get_user_name();
            message+=" 离开了";
            message+=c->get_channel_name();
            ui->welcome_text_broswer->append(message);
            c->del_user(u);
            c->update_view();
        }
        else if(0==strncmp(datagram.data(),"/creat",6))//tested
        {
            qDebug() << __LINE__ <<"/creat entered";
            char tmp[64];
            char channelid[10];
            char channelname[21];
            get_content(tmp,datagram.data());
            get_content(channelname,tmp);
            get_content0(channelid,tmp);
            int cid=atoi(channelid);
            channel*new_channel=new channel();
            new_channel->set_channel_id(cid);
            new_channel->set_channel_name(channelname);
            channel_list.push_back(new_channel);
            qDebug() << __LINE__ <<"new channel added:"<<channelname;
            QWidget&wg=new_channel->get_widget();
            int index=this->ui->irc_chat_body->addTab(&wg,channelname);
            new_channel->set_tab_index(index);
            this->ui->irc_chat_body->setCurrentWidget(this->ui->irc_chat_body->widget(index));
            //this->ui->irc_chat_body->setTabsClosable(true);
            channel_user*tmpuser=new channel_user();
            tmpuser->set_user_alive(true);
            tmpuser->set_user_id(myself.get_user_id());
            tmpuser->set_user_name(myself.get_user_name());
            tmpuser->set_user_operator(true);
            new_channel->add_user(tmpuser);
            //tmp.setTabsClosable(true);
            qDebug() << __LINE__ <<"channel name:"<<channelname<<"channel id:"<<channelid;
            new_channel->update_view();
        }
        else if(0==strncmp(datagram.data(),"/topic",6))//tested
        {
            qDebug() << __LINE__ <<"/topic entered recv:"<<datagram.data();
            char tmp[64];
            char channelid[10];
            char channeltheme[21];
            get_content(tmp,datagram.data());
            get_content(channeltheme,tmp);
            get_content0(channelid,tmp);
            int cid=atoi(channelid);
            channel* u=get_channel(cid,NULL);
            if(u==NULL)return;
            u->set_channel_theme(channeltheme);

            //char tmpa[64];
            //QString message;
            //sprintf(tmpa,"[%s]系统消息",qt.currentTime().toString().toLatin1());
            QString message("[");
            message+=qt.currentTime().toString();
            message+="]系统消息";
            //strcat(message,"[");
            //strcat(message,qt.currentTime().toString().data());
            //strcat(message,"]");
            //strcat(message,"系统消息");
            //QString tmpb(message);
            qDebug() << __LINE__ <<"message"<<message;
            //this->ui->welcome_text_broswer->append(message);
            u->tb->append(message);
            QString message2("此频道主题:");
            message2+=channeltheme;
            qDebug() << __LINE__ <<message2;
            u->tb->append(message2);
            //this->ui->welcome_text_broswer->append(message2);
            //u->show_msg(message2);
            //qDebug() << __LINE__ <<"/topic entered";
        }
        else if(0==strncmp(datagram.data(),"/key",4))
        {
            qDebug() << __LINE__ <<"/key entered";
            char tmp[128];
            char channelid[10];
            char key1[21];
            char key2[21];
            char key3[21];
            char tmp2[128];
            get_content(tmp,datagram.data());
            get_content0(channelid,tmp);
            get_content(tmp2,tmp);
            get_content0(key1,tmp2);
            get_content(tmp,tmp2);
            get_content0(key2,tmp);
            get_content(key3,tmp);
            int cid=atoi(channelid);
            channel*u=get_channel(cid,NULL);
            if(u==NULL)return;
            u->set_channel_keyword1(key1);
            u->set_channel_keyword2(key2);
            u->set_channel_keyword3(key3);
        }
        else if(0==strncmp(datagram.data(),"/join",5))
        {
            qDebug() << __LINE__ <<"/join entered"<<datagram.data();
            char usernum[10];
            char username[31];
            char channelnum[10];
            char channelname[31];
            char tmp[128];
            char tmp2[128];
            get_content(tmp,datagram.data());
            get_content0(usernum,tmp);
            get_content(tmp2,tmp);
            get_content0(username,tmp2);
            get_content(tmp,tmp2);
            get_content0(channelnum,tmp);
            get_content(channelname,tmp);
            int user_id=atoi(usernum);
            int channel_id=atoi(channelnum);
            channel*tmp_c=get_channel(channel_id,NULL);

            if(tmp_c==NULL)
            {
                if(user_id==myself.get_user_id())
                {
                    channel*new_channel=new channel();
                    new_channel->set_channel_id(channel_id);
                    new_channel->set_channel_name(channelname);
                    channel_list.push_back(new_channel);
                    qDebug() << __LINE__ <<"new channel added:"<<channelname;
                    QWidget&wg=new_channel->get_widget();
                    int index=this->ui->irc_chat_body->addTab(&wg,channelname);
                    new_channel->set_tab_index(index);
                    this->ui->irc_chat_body->setCurrentWidget(this->ui->irc_chat_body->widget(index));
                    //this->ui->irc_chat_body->setTabsClosable(true);
                    channel_user*tmpuser=new channel_user();
                    tmpuser->set_user_alive(true);
                    tmpuser->set_user_id(myself.get_user_id());
                    tmpuser->set_user_name(myself.get_user_name());
                    tmpuser->set_user_operator(false);
                    new_channel->add_user(tmpuser);
                    //tmp.setTabsClosable(true);
                    qDebug() << __LINE__ <<"channel name:"<<channelname<<"channel id:"<<channelnum;
                    new_channel->update_view();

                    QString sm("/name ");
                    sm+=channelnum;
                    int length=0;
                    //QTextCodec*code=QTextCodec::codecForName("GBK");
                    qDebug() << __LINE__ <<"sent "<<sm;
                    if((length=socket->writeDatagram(sm.toUtf8(),sm.toUtf8().length(),QHostAddress(server_addr),port))!=sm.toUtf8().length())
                    {
                        qDebug() << __LINE__ <<"error";
                        return;
                    }
                    QString sm2("/topic ");
                    sm2+=channelnum;
                    length=0;
                    //QTextCodec*code=QTextCodec::codecForName("GBK");
                    qDebug() << __LINE__ <<"sent "<<sm;
                    if((length=socket->writeDatagram(sm2.toUtf8(),sm2.toUtf8().length(),QHostAddress(server_addr),port))!=sm2.toUtf8().length())
                    {
                        qDebug() << __LINE__ <<"error";
                        return;
                    }
                }
                return;
            }
            else
            {
                qDebug()<< __LINE__ <<tmp_c->user_list.size();
                for(int i=0;i<tmp_c->user_list.size();i++)
                {
                    if(tmp_c->user_list[i]->get_user_id()==user_id)return;
                }
                channel_user*newu=new channel_user();
                newu->set_user_alive(true);
                newu->set_user_id(atoi(usernum));
                newu->set_user_name(username);
                tmp_c->add_user(newu);
                qDebug()<< __LINE__ <<tmp_c->user_list.size();
                tmp_c->update_view();
                return;
            }

            /*
            if(user_id==myself.get_user_id())
            {
                channel*new_channel=new channel();
                new_channel->set_channel_id(channel_id);
                new_channel->set_channel_name(channelname);
                channel_list.push_back(*new_channel);
                QWidget&wg=new_channel->get_widget();
                int index=this->ui->irc_chat_body->addTab(&wg,channelname);
                new_channel->set_tab_index(index);
                this->ui->irc_chat_body->setCurrentWidget(this->ui->irc_chat_body->widget(index));
                this->ui->irc_chat_body->setTabsClosable(true);
                channel_user*tmpuser=new channel_user();
                tmpuser->set_user_alive(true);
                tmpuser->set_user_id(myself.get_user_id());
                tmpuser->set_user_name(myself.get_user_name());
                tmpuser->set_user_operator(false);
                new_channel->add_user(*tmpuser);
                //tmp.setTabsClosable(true);
                qDebug() << __LINE__ <<"channel name:"<<channelname<<"channel id:"<<channelnum;
                new_channel->update_view();

                QString sm("/name ");
                sm+=channelnum;
                int length=0;
                //QTextCodec*code=QTextCodec::codecForName("GBK");
                qDebug() << __LINE__ <<"sent "<<sm;
                if((length=socket->writeDatagram(sm.toUtf8(),sm.toUtf8().length(),QHostAddress(server_addr),port))!=sm.toUtf8().length())
                {
                    qDebug() << __LINE__ <<"error";
                    return;
                }
            }
            else
            {
                int channelid=atoi(channelnum);
                channel*tmp_c=get_channel(channelid,NULL);
                if(tmp_c!=NULL)
                {
                    channel_user*newu=new channel_user();
                    newu->set_user_alive(true);
                    newu->set_user_id(atoi(usernum));
                    newu->set_user_name(username);
                    tmp_c->add_user(*newu);
                    tmp_c->update_view();
                    return;
                }
                QString message("[");
                message+=qt.currentTime().toString();
                message+="]系统消息";
                this->ui->welcome_text_broswer->append(message);
                QString ms;
                ms+="用户 ";
                ms+=username;
                ms+=" 加入了 ";
                ms+=channelname;
                ms+=" 频道";
            }
            */
        }
        else if(0==strncmp(datagram.data(),"/name",5))
        {
            qDebug() << __LINE__ <<"/name entered";
            char channelnum[10];
            char usernum[10];
            char username[31];
            char tmp[1024];
            char tmp2[1024];
            get_content(tmp2,datagram.data());
            get_content0(channelnum,tmp2);
            get_content(tmp,tmp2);
            channel*tmp_c;
            tmp_c=get_channel(atoi(channelnum),NULL);
            if(tmp_c==NULL)
            {
                //error handle
            }
            while(0!=strcmp(tmp,"EOF"))
            {
                get_content0(usernum,tmp);
                get_content(tmp2,tmp);
                get_content0(username,tmp2);
                get_content(tmp,tmp2);
                if(atoi(usernum)==myself.get_user_id())continue;
                channel_user*tmpuser=new channel_user();
                tmpuser->set_user_alive(true);
                tmpuser->set_user_id(atoi(usernum));
                tmpuser->set_user_name(username);
                //tmpuser->set_user_operator(false);
                tmp_c->add_user(tmpuser);
                //tmp.setTabsClosable(true);
                qDebug() << __LINE__ <<"channel id:"<<channelnum;
            }
            tmp_c->update_view();
        }
        else if(0==strncmp(datagram.data(),"/list",5))//tested
        {
            qDebug() << __LINE__ <<"/list entered";
            char tmp[1024];
            char tmp2[1024];
            char tmp3[1024];
            get_content(tmp,datagram.data());
            QString message("[");
            message+=qt.currentTime().toString();
            message+="]系统消息";
            bool has_no_data=true;
            this->ui->welcome_text_broswer->append(message);
            while(0!=strcmp(tmp,"EOF"))
            {
                has_no_data=false;
                QString message2("频道ID:");
                get_content0(tmp2,tmp);
                message2+=tmp2;
                get_content(tmp3,tmp);
                get_content0(tmp2,tmp3);
                get_content(tmp,tmp3);
                message2+="  频道名:";
                message2+=tmp2;
                qDebug() << __LINE__ <<message2;
                this->ui->welcome_text_broswer->append(message2);
                this->ui->irc_chat_body->setCurrentWidget(this->ui->irc_chat_body->widget(0));
            }
            if(has_no_data)
            {
                QString message2("没有找到相应的频道");
                qDebug() << __LINE__ <<message2;
                this->ui->welcome_text_broswer->append(message2);
                this->ui->irc_chat_body->setCurrentWidget(this->ui->irc_chat_body->widget(0));
            }
        }
        else if(0==strncmp(datagram.data(),"/private",6))
        {
            qDebug() << __LINE__ <<"/private entered";
            char tmp[64];
            char num[10];
            char msg[1024];
            get_content(tmp,datagram.data());
            get_content(msg,tmp);
            get_content0(num,tmp);
            int id=atoi(num);
            QString message("[");
            message+=qt.currentTime().toString();
            message+="]系统消息";
            ui->welcome_text_broswer->append(message);
            message.clear();
            message+="用户:";
            message+=num;
            message+=" 私信你:";
            message+=msg;
            ui->welcome_text_broswer->append(message);
        }
        else//other msg
        {
            qDebug() << __LINE__ <<"/other msg entered" <<datagram.data();
            if(0==strcmp(datagram.data(),"USER_INVALID"))
            {
                int length=0;
                //QTextCodec*code=QTextCodec::codecForName("GBK");
                //qDebug() << __LINE__ <<"sent "<<this->ui->send_msg_text_edit->toPlainText();
                if((length=socket->writeDatagram("/hello",6,QHostAddress(server_addr),port))!=6)
                {
                    qDebug() << __LINE__ <<"error";
                    return;
                }



                QFile file("nick");
                if(file.exists())
                {
                    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                         qDebug()<< __LINE__ <<"open failed";

                    QTextStream in(&file);
                    QString line("/nick ");
                    QString tmp;
                    tmp=in.readLine();
                    line+=tmp;
                    if((length=socket->writeDatagram(line.toUtf8(),line.toUtf8().length(),QHostAddress(server_addr),port))!=line.toUtf8().length())
                    {
                        qDebug() << __LINE__ <<"error";
                        return;
                    }
                    ui->nick_label->setText(tmp);
                }
                else
                {
                    QString line("/nick guest");
                    if((length=socket->writeDatagram(line.toUtf8(),line.toUtf8().length(),QHostAddress(server_addr),port))!=line.toUtf8().length())
                    {
                        qDebug() << __LINE__ <<"error";
                        return;
                    }
                }
            }
            char tmp[2048];
            get_content0(tmp,datagram.data());
            if(tmp[0]>'9'||tmp[0]<'0')
            {
                QString message("[");
                message+=qt.currentTime().toString();
                message+="]系统消息";
                this->ui->welcome_text_broswer->append(message);
                QString tmpt;
                tmpt.fromUtf8(datagram.data());
                this->ui->welcome_text_broswer->append(tmpt);
                return;
            }
            int userid=atoi(tmp);
            char tmp2[2048];
            char channelnum[10];
            get_content(tmp2,datagram.data());
            get_content0(channelnum,tmp2);
            get_content(tmp,tmp2);
            int channelid=atoi(channelnum);
            QString msg(tmp);
            channel*tmp_c=get_channel(channelid,NULL);
            channel_user*tmp_u=get_user(userid,NULL);
            QString message("[");
            message+=qt.currentTime().toString();
            message+="]";
            message+=tmp_u->get_user_name();
            tmp_c->tb->append(message);
            tmp_c->tb->append(msg);
        }
    }
}

void Irc_window::get_content0(char*des, char*src)//tested
{
    int len = strlen(src);
    int i = 0;
    while (src[i] != ' '&&i<len)
    {
        i++;
    }
    strncpy(des, src, i);
    des[i] = '\0';
}

void Irc_window::get_content(char *des,char *src)//tested
{
    int len=strlen(src);
    int i=0;
    char tmp[2048];
    for(;i<len;i++)
    {
        if(src[i]==' ')
        {
repeat:
            i++;
            if(src[i]==' ') goto repeat;
            strncpy(tmp,src+i,len-i);
            tmp[len-i]='\0';
            strncpy(des, tmp, strlen(tmp)+1);
            break;
        }
    }
    return ;
}

void Irc_window::emoji_clicked()//tested
{
    emoji_window->show();
}

void Irc_window::create_c_clicked()//tested
{
    channel_creator_window->show();
}

void Irc_window::find_c_clicked()//tested
{
    channel_finder_window->show();
}

void Irc_window::send_msg()
{
    int index=this->ui->irc_chat_body->currentIndex();
    QString tmp;
    if(index!=0)
    {
        int id=get_channel_id(index);
        if(id==0)
        {
            //error handle
        }
        tmp=QString::number(id);
        tmp+=" ";
    }
    tmp+=this->ui->send_msg_text_edit->toPlainText();
    int length=0;
    //QTextCodec*code=QTextCodec::codecForName("GBK");
    qDebug() << __LINE__ <<"sent "<<tmp;
    if((length=socket->writeDatagram(tmp.toUtf8(),tmp.toUtf8().length(),QHostAddress(server_addr),port))!=tmp.toUtf8().length())
    {
        qDebug() << __LINE__ <<"error";
        return;
    }
    //qDebug() << __LINE__ <<this->ui->send_msg_text_edit->toPlainText().toUtf8().length();
    //this->ui->send_msg_text_edit->cut();
    this->ui->send_msg_text_edit->clear();
}

int Irc_window::get_channel_id(int id)
{
    for(int i=0;i<channel_list.size();i++)
    {
        if(channel_list[i]->get_tab_index()==id)
            return channel_list[i]->get_channel_id();
    }
    return 0;
}

void Irc_window::hideme()//tested
{
    this->hide();
    mybtn->setText("打开聊天窗口");
}

void Irc_window::feedback_f()//tested
{
    feedback_window->show();
}

void Irc_window::part()
{
    QString tmp("/part ");
    int index=this->ui->irc_chat_body->currentIndex();
    if(index==0)return;
    int id=get_channel_id(index);
    tmp+=QString::number(id);
    int length=0;
    //QTextCodec*code=QTextCodec::codecForName("GBK");
    qDebug() << __LINE__ <<"sent "<<tmp;
    if((length=socket->writeDatagram(tmp.toUtf8(),tmp.toUtf8().length(),QHostAddress(server_addr),port))!=tmp.toUtf8().length())
    {
        qDebug() << __LINE__ <<"error";
        return;
    }
    this->ui->irc_chat_body->setCurrentWidget(this->ui->irc_chat_body->widget(0));
    this->ui->irc_chat_body->removeTab(index);
    for(int i=0;i<channel_list.size();i++)
    {
        if(channel_list[i]->get_channel_id()==id)
            channel_list.removeAt(i);//leak
    }

}
