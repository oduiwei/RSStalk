#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "feedlist.h"

FeedList::FeedList()
{

}

QList<Feed *> FeedList::getFeedList()
{
    return this->feedList;
}

void FeedList::addNewFeed(Feed newFeed)
{
    //this->feedList.append(newFeed);
}

void FeedList::deleteFeed(int index)
{
    //this->feedList.
}

void FeedList::renameFeed(int index, QString name)
{

}

bool FeedList::getFavoriteMark()
{
    return this->favoriteMark;
}

void FeedList::setFavoriteMark(bool favorite)
{
    favoriteMark = favorite;
}
