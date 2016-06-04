#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QKeyEvent>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    MyLineEdit() {}
    ~MyLineEdit() {}

    void keyPressEvent(QKeyEvent *);
};

#endif // MYLINEEDIT_H
