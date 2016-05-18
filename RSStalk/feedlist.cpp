#include "feedlist.h"

FeedList::FeedList()
{

}

QList<Feed *> FeedList::getFeedList()
{
    return this->feedList;
}

void FeedList::addNewFeed(QString name)
{

}

void FeedList::deleteFeed()
{

}

void FeedList::renameFeed(QString newName)
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
