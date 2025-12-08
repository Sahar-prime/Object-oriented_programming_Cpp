#pragma once
#include <iostream>
class Circle 
{
	double radius;
public:
    // Конструкторы
    Circle(double r);
    Circle();
    Circle(const Circle& b);

    // Получение радиуса
    double getRadius()const;

    // Установка радиуса
    void setRadius(double r);

    // Вычисление длины окружности
    double circumference()const;

    // Перегрузка оператора == для проверки равенства радиусов
    bool operator==(const Circle& other) const
    {
        return radius == other.radius;
    }
    // Перегрузка оператора > для сравнения длин окружностей
    bool operator>(const Circle& other) const
    {
        return circumference() > other.circumference();
    }
    // Перегрузка оператора += для пропорционального увеличения радиуса
    Circle& operator+=(double factor)
    {
        radius += factor;
        return *this;
    }
    // Перегрузка оператора -= для пропорционального уменьшения радиуса
    Circle& operator-=(double factor)
    {
        radius -= factor;
        if (radius < 0) 
        {
            radius = 0;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Circle& r);
    friend std::istream& operator>>(std::istream& is, Circle& r);
};


inline std::ostream& operator<<(std::ostream& os, const Circle& r)
{
    os << r.radius;
    return os;
}
inline std::istream& operator>>(std::istream& is, Circle& r)
{
    is >> r.radius;
    return is;
}