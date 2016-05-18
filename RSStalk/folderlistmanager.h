#ifndef FOLDERLISTMANAGER_H
#define FOLDERLISTMANAGER_H

#include <QList>
#include "feedlist.h"

class FolderListManager
{
public:
    FolderListManager();

    QList<FeedList *> getFolderList();

    void addNewFolder(QString folderName);
    void deleteFolder();
    void renameFolder(QString newName);

private:
    QList<FeedList *> folderList;
};

#endif // FOLDERLISTMANAGER_H
