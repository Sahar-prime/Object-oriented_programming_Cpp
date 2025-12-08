#include <iostream>
#include "Circle.h"

// Конструктор
Circle::Circle(double r) : radius(r) {}
Circle::Circle() : Circle(0) {}
Circle::Circle(const Circle& b) : Circle{b.radius} {}

// Получение радиуса
double Circle::getRadius() const
{
    return radius;
}

// Установка радиуса
void Circle::setRadius(double r)
{
    radius = r;
}

// Вычисление длины окружности
double Circle::circumference() const
{
    const double PI = 3.14159265358979323846;
    return 2 * PI * radius;
}