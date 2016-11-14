#include "emoji.h"
#include "ui_emoji.h"

emoji::emoji(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::emoji)
{
    ui->setupUi(this);
    server_addr="119.29.111.145";
    setMaximumWidth(316);
    setMaximumHeight(168);
    setMinimumWidth(316);
    setMinimumHeight(168);
    //server_addr="192.168.56.102";
    port=8008;
    socket=new QUdpSocket(this);
    socket->bind(port,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);

    connect(ui->pushButton,SIGNAL(clicked(bool)), this, SLOT(set_nick()));

    QFile file("nick");
    if(file.exists())
    {
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             qDebug()<< __LINE__ <<"open failed";

        QTextStream in(&file);
        QString line;
        line=in.readLine();
        ui->nicklabel->setText(line);
    }
}

emoji::~emoji()
{
    delete ui;
}

void emoji::set_nick()
{
    QString smsg("/nick ");
    if(ui->newlineEdit->text().length()>10)
    {
        ui->tiplabel->setText("昵称长度不能超过10个中文！");
        return;
    }
    smsg+=ui->newlineEdit->text();

    QFile file("nick");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << ui->newlineEdit->text().toUtf8();

    int length=0;
    //QTextCodec*code=QTextCodec::codecForName("GBK");
    qDebug() << __LINE__ <<"sent "<<smsg;
    if((length=socket->writeDatagram(smsg.toUtf8(),smsg.toUtf8().length(),QHostAddress(server_addr),port))!=smsg.toUtf8().length())
    {
        qDebug() << __LINE__ <<"error";
        return;
    }
    ui->nicklabel->setText(ui->newlineEdit->text());
    ui->newlineEdit->clear();
    this->hide();
}
