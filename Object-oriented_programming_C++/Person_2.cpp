#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Person_2.h"
#include "Date.h"

Person_2::Person_2(const char* uname, const Date& ubirthday)
    : name{ new char[strlen(uname) + 1] }, birthday{ ubirthday }
{
    strcpy(name, uname);
    std::cout << "Отработал конструктор: " << this << std::endl;
}

Person_2::Person_2() : Person_2{ "NoName", Date{} } {}; 
Person_2::Person_2(const char* uname) : Person_2{ uname, Date{} } {}; 
Person_2::Person_2(const Date& ubirthday) : Person_2{ "NoName", ubirthday } {};

Person_2::Person_2(const Person_2& p)
    : name{ new char[strlen(p.name) + 1] }, birthday{ p.birthday }
{
    strcpy(name, p.name);
    std::cout << "Отработал конструктор копирования: " << this << std::endl;
}
Person_2::Person_2(Person_2&& p) noexcept
    : name{ p.name }, birthday{ std::move(p.birthday) }
{
    p.name = nullptr;
    std::cout << "Отработал конструктор перемещения: " << this << std::endl;
}

Person_2::~Person_2()
{
    delete[] name;
    std::cout << "Отработал деструктор: " << this << "\n";
}

void Person_2::show()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Birthday: ";
    birthday.show();
}