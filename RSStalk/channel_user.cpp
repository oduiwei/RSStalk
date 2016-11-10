#include "channel_user.h"

channel_user::channel_user()
{

}

channel_user::~channel_user()
{

}

bool channel_user::is_user_away()
{
    return is_away;
}

bool channel_user::is_user_operator()
{
    return is_operator;
}


void channel_user::set_user_away(bool away)
{
    is_away=away;
}

void channel_user::set_user_operator(bool op)
{
    is_operator=op;
}

bool channel_user::is_user_alive()
{
    return is_alive;
}

void channel_user::set_user_alive(bool b)
{
    is_alive=b;
}
