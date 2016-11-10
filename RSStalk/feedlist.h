#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef FEEDLIST_H
#define FEEDLIST_H

#include <QList>
#include "feed.h"

/*FeedList类负责管理一个文件夹中的订阅*/
class FeedList
{
public:
    FeedList();

    QList<Feed *> getFeedList();

    void addNewFeed(Feed);
    void deleteFeed(int);
    void renameFeed(int, QString);

    bool getFavoriteMark();
    void setFavoriteMark(bool favorite);

private:
    QString listName;
    QList<Feed *> feedList;
    bool favoriteMark;
};

#endif // FEEDLIST_H
