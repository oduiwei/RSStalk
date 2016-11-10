#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef FIND_CHANNEL_H
#define FIND_CHANNEL_H

#include <QWidget>
#include<QUdpSocket>

namespace Ui {
class find_channel;
}

class find_channel : public QWidget
{
    Q_OBJECT

public:
    explicit find_channel(QWidget *parent = 0);
    ~find_channel();

private:
    Ui::find_channel *ui;
    QString server_addr;
    qint16 port;
    QUdpSocket *socket;
private slots:
    void find_c_clicked();
};

#endif // FIND_CHANNEL_H
