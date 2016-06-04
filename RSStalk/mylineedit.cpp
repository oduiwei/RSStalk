#include "mylineedit.h"


/*重载QLineEdit的KeyEvent函数，用来监听键盘操作*/
void MyLineEdit::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Enter)
    {
        qDebug() << "the enter key is pressed.";
    }
}
