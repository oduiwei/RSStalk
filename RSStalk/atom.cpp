#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "atom.h"

Atom::Atom()
{
}

Atom::Atom(QString addr)
{
    QString fileName = addr;
    this->parseAtom(fileName);
}

QString Atom::getAtomTitle()
{
    return this->title;
}

QString Atom::getAtomLink()
{
    return this->url;
}

QStringList Atom::getArticleTitle()
{
    return this->articleTitle;
}

QStringList Atom::getArticleLink()
{
    return this->articleLink;
}

QStringList Atom::getArticleSummary()
{
    return this->articleSummary;
}

QString Atom::getUpdatedTime()
{
    return this->updatedTime;
}

void Atom::parseAtom(QString fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "open file failed";
    }

    XmlParser atomParser(&file);
    this->title = atomParser.getFeedTitle();
    this->articleList = atomParser.getAtomArtList();

    file.close();
}

QList<atomArticle> Atom::getArtList()
{
    return this->articleList;
}

int Atom::getArtNum()
{
    return this->articleList.size();
}

