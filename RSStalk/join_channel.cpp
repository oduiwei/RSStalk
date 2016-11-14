#include "join_channel.h"
#include "ui_join_channel.h"

join_channel::join_channel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::join_channel)
{
    ui->setupUi(this);
    setMaximumWidth(463);
    setMaximumHeight(186);
    setMinimumWidth(463);
    setMinimumHeight(186);
    server_addr="119.29.111.145";
    //server_addr="192.168.56.102";
    port=8008;
    socket=new QUdpSocket(this);
    socket->bind(port,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);

    connect(ui->pushButton,SIGNAL(clicked(bool)), this, SLOT(join_btn_clicked()));
}

join_channel::~join_channel()
{
    delete ui;
}

void join_channel::join_btn_clicked()
{
    QString smsg("/join ");
    if(!ui->id_lineEdit->text().isEmpty())
    {
        smsg+=ui->id_lineEdit->text();
    }
    else
    {
        if(ui->name_lineEdit->text().length()>20)
        {
            ui->tip_label->setText("频道名字不会超过20");
            return;
        }
        smsg+=ui->name_lineEdit->text();
    }

    int length=0;
    //QTextCodec*code=QTextCodec::codecForName("GBK");
    qDebug() << __LINE__ <<"sent "<<smsg;
    if((length=socket->writeDatagram(smsg.toUtf8(),smsg.toUtf8().length(),QHostAddress(server_addr),port))!=smsg.toUtf8().length())
    {
        qDebug() << __LINE__ <<"error";
        return;
    }

    ui->id_lineEdit->clear();
    ui->name_lineEdit->clear();
    this->hide();
}
