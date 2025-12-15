#include "Rect.h"
#include <iostream>
#include "Point_2.h"

Rect::Rect() : start(Point_2()), a(0), b(0) {}


Rect::Rect(const Rect& r) : start(r.start), a(r.a), b(r.b) {}

Rect::Rect(Rect&& r) noexcept: start(std::move(r.start)), a(r.a), b(r.b)
{
    r.a = 0;
    r.b = 0;
}

void Rect::init() 
{
    start.init();
    a = 23;
    b = 55;
}

void Rect::show() 
{
    std::cout << "Прямоугольник:" << std::endl;
    start.show();
    std::cout << "Ширина: " << a << ", Высота: " << b << std::endl;
}
