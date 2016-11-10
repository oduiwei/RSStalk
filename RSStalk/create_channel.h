#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#ifndef CREATE_CHANNEL_H
#define CREATE_CHANNEL_H

#include <QWidget>
#include<QUdpSocket>

namespace Ui {
class create_channel;
}

class create_channel : public QWidget
{
    Q_OBJECT

public:
    explicit create_channel(QWidget *parent = 0);
    ~create_channel();

private:
    Ui::create_channel *ui;
    QString server_addr;
    qint16 port;
    QUdpSocket *socket;
private slots:
    void create_c_clicked();
};

#endif // CREATE_CHANNEL_H
