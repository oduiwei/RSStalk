#ifndef FOLDERLISTMANAGER_H
#define FOLDERLISTMANAGER_H

#include <QList>
#include "feedlist.h"

class FolderListManager
{
public:
    FolderListManager();

    QList<FeedList *> getFolderList();

    void addNewFolder(FeedList);
    void deleteFolder(int);
    void renameFolder(int, QString);

private:
    QList<FeedList *> folderList;
};

#endif // FOLDERLISTMANAGER_H
