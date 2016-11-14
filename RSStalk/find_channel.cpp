#include "find_channel.h"
#include "ui_find_channel.h"

find_channel::find_channel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::find_channel)
{
    ui->setupUi(this);
    setMaximumWidth(337);
    setMaximumHeight(221);
    setMinimumWidth(337);
    setMinimumHeight(221);
    server_addr="119.29.111.145";
    //server_addr="192.168.56.102";
    port=8008;
    socket=new QUdpSocket(this);
    socket->bind(port,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);

    connect(ui->pushButton,SIGNAL(clicked(bool)), this, SLOT(find_c_clicked()));
}

find_channel::~find_channel()
{
    delete ui;
}


void find_channel::find_c_clicked()
{
    QString smsg("/list :");
    if(ui->lineEdit1->text().length()>10)
    {
        ui->tiplabel->setText("关键字长度不会超过20个中文！");
        return;
    }
    if(!ui->lineEdit1->text().isEmpty())
    {
        smsg+=ui->lineEdit1->text();
        goto send;
    }
    if(ui->lineEdit2->text().length()>10)
    {
        ui->tiplabel->setText("关键字长度不会超过20个中文！");
        return;
    }
    if(!ui->lineEdit2->text().isEmpty())
    {
        smsg+=ui->lineEdit2->text();
        goto send;
    }
    if(ui->lineEdit3->text().length()>10)
    {
        ui->tiplabel->setText("关键字长度不会超过20个中文！");
        return;
    }
    if(!ui->lineEdit3->text().isEmpty())
    {
        smsg+=ui->lineEdit3->text();
        //goto send;
    }
send:
    int length=0;
    //QTextCodec*code=QTextCodec::codecForName("GBK");
    qDebug() << __LINE__ <<"sent "<<smsg;
    if((length=socket->writeDatagram(smsg.toUtf8(),smsg.toUtf8().length(),QHostAddress(server_addr),port))!=smsg.toUtf8().length())
    {
        qDebug() << __LINE__ <<"error";
        return;
    }

    ui->lineEdit1->clear();
    ui->lineEdit2->clear();
    ui->lineEdit3->clear();
    this->hide();
}
