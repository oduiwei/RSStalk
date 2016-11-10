#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <QWidget>
#include<QUdpSocket>

namespace Ui {
class feedback;
}

class feedback : public QWidget
{
    Q_OBJECT

public:
    explicit feedback(QWidget *parent = 0);
    ~feedback();

private:
    Ui::feedback *ui;
    QString server_addr;
    qint16 port;
    QUdpSocket *socket;
private slots:
    void send_btn_clicked();
};

#endif // FEEDBACK_H
