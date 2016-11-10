#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef JOIN_CHANNEL_H
#define JOIN_CHANNEL_H

#include <QWidget>
#include<QUdpSocket>

namespace Ui {
class join_channel;
}

class join_channel : public QWidget
{
    Q_OBJECT

public:
    explicit join_channel(QWidget *parent = 0);
    ~join_channel();

private:
    Ui::join_channel *ui;
    QString server_addr;
    qint16 port;
    QUdpSocket *socket;
private slots:
    void join_btn_clicked();
};

#endif // JOIN_CHANNEL_H
