#ifndef ATOM_H
#define ATOM_H

#include "feed.h"

class Atom : public Feed
{
public:
    Atom();
    Atom(QString url);

    QString getAtomTitle();
    QString getAtomLink();
    QString getArticleTitle();
    QStringList getArticleLink();
    QStringList getArticleSummary();
    QString getUpdatedTime();

    QList<atomArticle> getArtList();
    int getArtNum();

    void setAtomTitle(QString title);
    void setArticleTitle(QString childTitle);

    void parseAtom(QString fileName);
    void downLoadAtomFile(QString url);
    void update(QString url);

private:
    QStringList articleTitle;
    QStringList articleLink;
    QStringList aritcleSummary;
    QString updatedTime;

    QList<atomArticle> articleList;
};

#endif // ATOM_H
