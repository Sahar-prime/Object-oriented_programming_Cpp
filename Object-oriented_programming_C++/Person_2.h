#pragma once
#include "Date.h"

class Person_2
{
    char* name;
    Date birthday;
public:
    Person_2();
    Person_2(const char* uname);
    Person_2(const Date& ubirthday); 
    Person_2(const char* uname, const Date& ubirthday);
    Person_2(const Person_2& p);
    Person_2(Person_2&& p) noexcept;
    ~Person_2();

    void show();
};
