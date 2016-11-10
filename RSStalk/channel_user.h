#ifndef CHANNEL_USER_H
#define CHANNEL_USER_H
#include "user.h"

class channel_user : public user
{
public:
    channel_user();
    ~channel_user();
    bool is_user_away();
    bool is_user_operator();
    bool is_user_alive();
    void set_user_alive(bool);
    void set_user_away(bool);
    void set_user_operator(bool);
private:
    bool is_operator;
    bool is_away;
    bool is_alive;
};

#endif // CHANNEL_USER_H
