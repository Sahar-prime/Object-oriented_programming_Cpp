#define _CRT_SECURE_NO_WARNINGS
#include "Reservoir.h"
#include <iostream>

Reservoir::Reservoir(const char* name, float l, float w, float h) :
    l{ l },
    w{ w },
    h{ h }
{
    this->name = new char[std::strlen(name) + 1];
    std::strcpy(this->name, name);
    std::cout << "Конструктор с параметрами: " << this << std::endl;
}
Reservoir::Reservoir() : Reservoir{ "NO_NAME", 0, 0, 0 } {}
Reservoir::Reservoir(const Reservoir& r) : Reservoir{ r.name, r.l, r.w, r.h } {}
Reservoir::~Reservoir() 
{ 
    delete[] name;
    std::cout << "Деструктор: " << this << std::endl;
}

float Reservoir::S() const
{
    return l * w;
}
float Reservoir::V() const
{
    return S() * h;
}

bool Reservoir::equal(const Reservoir& r1, const Reservoir& r2)
{
    return r1.S() == r2.S();
}
void Reservoir::copy(const Reservoir& r)
{
    delete[] name; 
    this->name = new char[std::strlen(r.name) + 1];
    std::strcpy(this->name, r.name);
    this->l = r.l;
    this->w = r.w;
    this->h = r.h;
}
char* Reservoir::type() 
{
    if (V() < 120)
    {
        std::cout << "Бассейн";
    }

    else if (V() >= 120 and V() < 300)
    {
        std::cout << "Пруд";
    }
    else
    {
        std::cout << "Море";
    }
    return 0;
}