#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "folderlistmanager.h"

FolderListManager::FolderListManager()
{

}

void FolderListManager::addNewFolder(FeedList newList)
{

}

void FolderListManager::deleteFolder(int index)
{

}

void FolderListManager::renameFolder(int index, QString name)
{

}

QList<FeedList *> FolderListManager::getFolderList()
{
    return this->folderList;
}
