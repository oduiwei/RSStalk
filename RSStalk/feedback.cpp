#include "feedback.h"
#include "ui_feedback.h"

feedback::feedback(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::feedback)
{
    ui->setupUi(this);
    server_addr="119.29.111.145";
    //server_addr="192.168.56.102";
    port=8008;
    socket=new QUdpSocket(this);
    socket->bind(port,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);

    connect(ui->send_btn,SIGNAL(clicked(bool)), this, SLOT(send_btn_clicked()));
}

feedback::~feedback()
{
    delete ui;
}

void feedback::send_btn_clicked()
{
    ui->name_lineEdit->clear();
    ui->teletphone_lineEdit->clear();
    ui->feedback_textEdit->clear();
    this->hide();
}
