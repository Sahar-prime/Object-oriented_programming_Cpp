#include "Drob_2.h"
#include <iostream>

Drob_2::Drob_2(int n, int d) : num(n), den(d)
{
    if (den == 0)
    {
        std::cerr << "Ошибка: знаменатель не может быть нулем.\n";
        exit(1);
    }
}
Drob_2::Drob_2() : Drob_2{ 1, 1 } {}
Drob_2::Drob_2(int u) : Drob_2{ u, 1 } {}

void Drob_2::setNum(int u)
{
    num = u;
}
void Drob_2::setDenom(int u)
{
    if (u == 0)
    {
        std::cerr << "Ошибка: знаменатель не может быть нулем.\n";
        exit(1);
    }
    den = u;
}

int Drob_2::getNum() const
{
    return num;
}
int Drob_2::getDenom() const
{
    return den;
}

void Drob_2::init()
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
void Drob_2::show() const
{
    std::cout << num << "/" << den << std::endl;
}

//void Drob_2::add(const Drob_2& other)
//{
//    num = num * other.den + other.num * den;
//    den = den * other.den;
//}
//void Drob_2::subtract(const Drob_2& other)
//{
//    num = num * other.den - other.num * den;
//    den = den * other.den;
//}
//void Drob_2::multiply(const Drob_2& other)
//{
//    num = num * other.num;
//    den = den * other.den;
//}
//void Drob_2::divide(const Drob_2& other)
//{
//    num = num * other.den;
//    den = den * other.num;
//}