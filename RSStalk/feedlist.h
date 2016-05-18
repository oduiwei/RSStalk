#ifndef FEEDLIST_H
#define FEEDLIST_H

#include <QList>
#include "feed.h"

class FeedList
{
public:
    FeedList();

    QList<Feed *> getFeedList();

    void addNewFeed(QString name);
    void deleteFeed();
    void renameFeed(QString newName);

    bool getFavoriteMark();
    void setFavoriteMark(bool favorite);

private:
    QList<Feed *> feedList;
    bool favoriteMark;
};

#endif // FEEDLIST_H
