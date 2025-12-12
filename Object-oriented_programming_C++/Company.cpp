#include "Company.h"
#include "Person_2.h"
#include <iostream>

Company::Company(const char* utitle, const Person_2& dir) :
    title{ new char[std::strlen(utitle) + 1] },
    director{ dir }
{
    std::strcpy(title, utitle);
    std::cout << "Отработал конструктор с параметрами: " << this << std::endl;
}

Company::Company() : Company("Без названия", Person_2{}) {}
Company::Company(const char* utitle) : Company(utitle, Person_2{}) {}
Company::Company(const Person_2& dir) : Company("Без названия", dir){}

Company::Company(const Company& p) : Company{p.title, p.director} {}

Company::Company(Company&& p) noexcept : title{ p.title }, director{p.director}
{
    p.title = nullptr;
    std::cout << "Отработал конструктор перемещения: " << this << std::endl;
}

Company::~Company()
{
    delete[] title;
    std::cout << "Отработал деструктор: " << this << std::endl;
}

void Company::show() 
{
    std::cout << "Компания: " << (title ? title : "Без названия") << std::endl;
    std::cout << "Директор: ";
    director.show();
}
