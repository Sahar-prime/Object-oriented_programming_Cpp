#include "Point_2.h"
#include <iostream>

Point_2::Point_2(): x(0), y(0) {}
Point_2::Point_2(float x, float y) : x(x), y(y) {}

void Point_2::init() 
{
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter y: ";
    std::cin >> y;
}
void Point_2::show() const
{
    std::cout << "Point coordinates: ( " << x << ", " << y << " )" << std::endl;
}

bool Point_2::isEqual(const Point_2& p1, const Point_2& p2)
{
    return (p1.x == p2.x) && (p1.y == p2.y);
}

Point_2 Point_2::add(const Point_2& p1, const Point_2& p2)
{
    return Point_2(p1.x + p2.x, p1.y + p2.y);
}
Point_2 Point_2::mult(const Point_2& p1, float value)
{
    return Point_2(p1.x * value, p1.y * value);
}

float Point_2::distance(const Point_2& p1, const Point_2& p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
float Point_2::lenght() const
{
    return sqrt(pow(x, 2) + pow(y, 2));
}