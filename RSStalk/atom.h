#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef ATOM_H
#define ATOM_H

#include "feed.h"

/*Atom类继承于Feed类，负责通过XmlParser类解析atom文件并提供获取解析结果的接口*/
class Atom : public Feed
{
public:
    Atom();
    Atom(QString addr);

    QString getAtomTitle();//获取atom文件的标题
    QString getAtomLink();//获取atom文件的网址
    QStringList getArticleTitle();//获取atom文件中所有文章的标题
    QStringList getArticleLink();//获取atom文件中所有文章的网址
    QStringList getArticleSummary();//获取atom文件中所有文章的内容
    QString getUpdatedTime();//获取atom文件的最新更新时间

    QList<atomArticle> getArtList();//获取atom文件的文件链表
    int getArtNum();//获取atom文件中文章的数目

    void parseAtom(QString fileName);//解析这个atom文件，初始化所有属性

private:
    QStringList articleTitle;//一个atom文件中所有文章的标题
    QStringList articleLink;//一个atom文件中所有文章的网址
    QStringList articleSummary;//一个atom文件中所有文章的内容
    QString updatedTime;//一个atom文件的最新更新时间

    QList<atomArticle> articleList;//atom文件的文章的链表
};

#endif // ATOM_H
