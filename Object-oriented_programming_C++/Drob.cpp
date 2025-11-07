#include <iostream>
#include "Drob.h"

Drob::Drob(int n, int d) : num(n), den(d)
{
    if (den == 0)
    {
        std::cerr << "Ошибка: знаменатель не может быть нулем.\n";
        exit(1);
    }
}
Drob::Drob() : Drob{ 1, 1 } {}
Drob::Drob(int u) : Drob{ u, 1 } {}

void Drob::setNum(int u)
{
    num = u;
}
void Drob::setDenom(int u) 
{
    if (u == 0) 
    {
        std::cerr << "Ошибка: знаменатель не может быть нулем.\n";
        exit(1);
    }
    den = u;
}

int Drob::getNum() const
{
    return num;
}
int Drob::getDenom() const
{
    return den;
}

void Drob::init()
{
    std::cout << "Введите числитель: ";
    std::cin >> num;
    std::cout << "Введите знаменатель: ";
    std::cin >> den;
    if (den == 0)
    {
        std::cerr << "Ошибка: знаменатель не может быть нулем.\n";
        exit(1);
    }
}
void Drob::show() const
{
    std::cout << num << "/" << den << std::endl;
}

void Drob::add(const Drob& other) 
{
    num = num * other.den + other.num * den;
    den = den * other.den;
}
void Drob::subtract(const Drob& other) 
{
    num = num * other.den - other.num * den;
    den = den * other.den;
}
void Drob::multiply(const Drob& other)
{
    num = num * other.num;
    den = den * other.den;
}
void Drob::divide(const Drob& other)
{
    num = num * other.den;
    den = den * other.num;
}
