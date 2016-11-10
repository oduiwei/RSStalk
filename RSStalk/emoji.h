#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef EMOJI_H
#define EMOJI_H
#include<QFile>

#include <QWidget>
#include<QUdpSocket>

namespace Ui {
class emoji;
}

class emoji : public QWidget
{
    Q_OBJECT

public:
    explicit emoji(QWidget *parent = 0);
    ~emoji();

private:
    Ui::emoji *ui;
    QString server_addr;
    qint16 port;
    QUdpSocket *socket;
private slots:
    void set_nick();
};

#endif // EMOJI_H
