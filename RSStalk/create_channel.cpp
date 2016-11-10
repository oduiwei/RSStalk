#include "create_channel.h"
#include "ui_create_channel.h"

create_channel::create_channel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::create_channel)
{
    ui->setupUi(this);
    server_addr="119.29.111.145";
    //server_addr="192.168.56.102";
    port=8008;
    socket=new QUdpSocket(this);
    socket->bind(port,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);

    connect(ui->pushButton,SIGNAL(clicked(bool)), this, SLOT(create_c_clicked()));
}

void create_channel::create_c_clicked()
{

    QString smsg("/creat ");
    if(ui->channel_name_lineEdit->text().length()>20)
    {
        ui->tipnamelabel->setText("名字长度不能超过20个中文！");
        return;
    }
    if(ui->theme_textEdit->toPlainText().length()>64)
    {
        ui->tipnamelabel->setText("主题长度不能超过64个中文！");
        return;
    }
    if(ui->key1_lineEdit->text().length()>10)
    {
        ui->tip1label->setText("关键字长度不能超过10个字节");
        return;
    }
    if(ui->key2_lineEdit->text().length()>10)
    {
        ui->tip1label->setText("关键字长度不能超过10个字节");
        return;
    }
    if(ui->key3_lineEdit->text().length()>10)
    {
        ui->tip1label->setText("关键字长度不能超过10个字节");
        return;
    }
    smsg+=ui->channel_name_lineEdit->text();
    int length=0;
    //QTextCodec*code=QTextCodec::codecForName("GBK");
    qDebug() << __LINE__ <<"sent "<<smsg;
    if((length=socket->writeDatagram(smsg.toUtf8(),smsg.toUtf8().length(),QHostAddress(server_addr),port))!=smsg.toUtf8().length())
    {
        qDebug() << __LINE__ <<"error";
        return;
    }

    QString s2msg("/key ");
    s2msg+=ui->channel_name_lineEdit->text();
    s2msg+=" ";
    if(ui->key1_lineEdit->text()=="")
    {
        ui->key1_lineEdit->setText("null");
    }
    if(ui->key2_lineEdit->text()=="")
    {
        ui->key2_lineEdit->setText("null");
    }
    if(ui->key3_lineEdit->text()=="")
    {
        ui->key3_lineEdit->setText("null");
    }
    s2msg+=ui->key1_lineEdit->text();
    s2msg+=" ";
    s2msg+=ui->key2_lineEdit->text();
    s2msg+=" ";
    s2msg+=ui->key3_lineEdit->text();

    qDebug() << __LINE__ <<"sent "<<s2msg;
    if((length=socket->writeDatagram(s2msg.toUtf8(),s2msg.toUtf8().length(),QHostAddress(server_addr),port))!=s2msg.toUtf8().length())
    {
        qDebug() << __LINE__ <<"error";
        return;
    }

    QString s3msg("/topic ");
    s3msg+=ui->channel_name_lineEdit->text();
    s3msg+=" ";
    s3msg+=ui->theme_textEdit->toPlainText();

    qDebug() << __LINE__ <<"sent "<<s3msg;
    if((length=socket->writeDatagram(s3msg.toUtf8(),s3msg.toUtf8().length(),QHostAddress(server_addr),port))!=s3msg.toUtf8().length())
    {
        qDebug() << __LINE__ <<"error";
        return;
    }

    ui->channel_name_lineEdit->clear();
    ui->key1_lineEdit->clear();
    ui->key2_lineEdit->clear();
    ui->key3_lineEdit->clear();
    ui->theme_textEdit->clear();
    this->hide();
    //qDebug() << __LINE__ <<myself.get_user_id();
    //this->ui->send_msg_text_edit->cut();
    //this->ui->send_msg_text_edit->clear();
}

create_channel::~create_channel()
{
    delete ui;
}
