#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef USER_H
#define USER_H
#include<QString>

class user
{
public:
    user();
    ~user();
    int get_user_id();
    QString& get_user_name();
    void set_user_id(int);
    void set_user_name(QString);
    int user_id;
    QString user_name;
};

#endif // USER_H
