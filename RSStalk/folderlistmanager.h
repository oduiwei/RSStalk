#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef FOLDERLISTMANAGER_H
#define FOLDERLISTMANAGER_H

#include <QList>
#include "feedlist.h"

/*FolderListManager类负责管理文件夹*/
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
