#include "user.h"

user::user()
{

}

user::~user()
{

}

int user::get_user_id()
{
    return user_id;
}

QString& user::get_user_name()
{
    return user_name;
}

void user::set_user_id(int id)
{
    user_id=id;
}

void user::set_user_name(QString name)
{
    user_name=name;
}
