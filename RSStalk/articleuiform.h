#ifndef ARTICLEUIFORM_H
#define ARTICLEUIFORM_H

#include <QWidget>
#include <QMouseEvent>
#include <QAbstractButton>

#define ALREADY_READ_ICON "://ico//image//already_read.png"
#define NOT_READ_ICON "://ico//image//not_read.png"
#define LIKE_ICON "://ico//image//like.png"
#define DISLIKE_ICON "://ico//image//dislike.png"

namespace Ui {
class ArticleUIForm;
}

class ArticleUIForm : public QWidget
{
    Q_OBJECT

public:
    int pos;
    QString feedtitle;

public:
    explicit ArticleUIForm(QWidget *parent = 0);
    ~ArticleUIForm();

    void setWhetherReadIcon(bool);
    void setWhetherLikeIcon(bool);
    void setArticleLabelText(QString);
    bool getWhetherReadIcon();
    bool getWhetherLikeIcon();
    QString getArticleLabelText();

private:
    Ui::ArticleUIForm *ui;
    bool likeState = false;

public slots:
    void slot_favoriteBtn_clicked();
signals:
    void signal_FavoriteStateChange(int, bool);
};

#endif // ARTICLEUIFORM_H
