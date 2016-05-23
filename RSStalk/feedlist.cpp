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

}

void FeedList::deleteFeed(int index)
{

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
