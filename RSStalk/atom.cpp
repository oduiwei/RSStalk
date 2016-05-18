#include "atom.h"

Atom::Atom()
{
    QString fileName = "C:\\Users\\19843\\Desktop\\test\\ATOM\\atom.xml";
    this->parseAtom(fileName);
}

Atom::Atom(QString urlt)
{
    //this->url = urlt;
    QString fileName = urlt;
    this->parseAtom(fileName);
}

QString Atom::getAtomTitle()
{
    return this->title;
}

QString Atom::getAtomLink()
{
    return this->getUrl();
}

QString Atom::getArticleTitle()
{
    QString s = "111";
    return s;
}

QStringList Atom::getArticleLink()
{
    QStringList sl;
    QList<QString> l;
    l.append("111");
    l.append("222");
    sl.append(l);

    return sl;
}

QStringList Atom::getArticleSummary()
{
    QStringList sl;
    QList<QString> l;
    l.append("111");
    l.append("222");
    sl.append(l);

    return sl;
}

QString Atom::getUpdatedTime()
{
    return this->updatedTime;
}

void Atom::setAtomTitle(QString title)
{

}

void Atom::setArticleTitle(QString childTitle)
{

}

void Atom::update(QString url)
{

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

