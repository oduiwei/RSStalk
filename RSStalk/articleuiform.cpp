#include "articleuiform.h"
#include "ui_articleuiform.h"

ArticleUIForm::ArticleUIForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ArticleUIForm)
{
    ui->setupUi(this);
    setWhetherReadIcon(false);
    setWhetherLikeIcon(false);

    connect(ui->whetherLikeBtn, SIGNAL(clicked(bool)), this, SLOT(slot_favoriteBtn_clicked()));
}

ArticleUIForm::~ArticleUIForm()
{
    delete ui;
}

void ArticleUIForm::setWhetherReadIcon(bool state)
{
    if (state == true)
        ui->whetherReadBtn->setIcon(QIcon(ALREADY_READ_ICON));
    else
        ui->whetherReadBtn->setIcon(QIcon(NOT_READ_ICON));
}

void ArticleUIForm::setWhetherLikeIcon(bool state)
{
    this->likeState = state;
    if (state == true)
        ui->whetherLikeBtn->setIcon(QIcon(LIKE_ICON));
    else
        ui->whetherLikeBtn->setIcon(QIcon(DISLIKE_ICON));
}

void ArticleUIForm::setArticleLabelText(QString text)
{
    ui->articleNameLabel->setText(text);
}

bool ArticleUIForm::getWhetherReadIcon()
{
    return false;
}

bool ArticleUIForm::getWhetherLikeIcon()
{
    return false;
}

QString ArticleUIForm::getArticleLabelText()
{
    return ui->articleNameLabel->text();
}

void ArticleUIForm::slot_favoriteBtn_clicked()
{
    if (this->likeState == false)
    {
        setWhetherLikeIcon(true);
        emit signal_FavoriteStateChange(pos, true);
    }
    else if (this->likeState == true)
    {
        setWhetherLikeIcon(false);
        emit signal_FavoriteStateChange(pos, false);
    }
}
