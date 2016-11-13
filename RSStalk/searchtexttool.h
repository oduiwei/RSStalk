#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef SEARCHTEXTTOOL_H
#define SEARCHTEXTTOOL_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QFile>
#include <QTextStream>
#include <QUrl>
#include <QFileInfo>
#include <QDir>
#include <QDialog>

class SearchTextTool : public QObject
{
    Q_OBJECT
private:
    QDialog* searchDialog;
    QNetworkAccessManager* manager;
    QNetworkReply* reply;
    QString path;

    QString saveFileName(QUrl url);

public:
    explicit SearchTextTool(QObject *parent = 0);

    void searchKeyWord(QUrl url, QString key);
    QString getPath();

signals:
    void signal_search_finished();

public slots:
    void slot_search_finished();
};

#endif // SEARCHTEXTTOOL_H
