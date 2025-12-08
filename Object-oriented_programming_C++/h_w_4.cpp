#include <iostream>
#include "Circle.h"

//#define H_W_4

#ifdef H_W_4
int main() 
{
    setlocale(LC_ALL, "");
    
    Circle c0;
    std::cout << c0 << std::endl;

    Circle c1(5.0);
    Circle c2(3.0);

    // Проверка на равенство радиусов
    if (c1 == c2) 
    {
        std::cout << c1 << " = " << c2 << std::endl;
    }
    else 
    {
        std::cout << c1 << " != " << c2 << std::endl;
    }

    // Сравнение длин окружностей
    if (c1 > c2)
    {
        std::cout << c1 << " > " << c2 << std::endl;
    }
    else
    {
        std::cout << c1 << " < " << c2 << std::endl;
    }

    // Пропорциональное изменение радиуса
    c1 += 2.0;
    std::cout << "Новый радиус первой окружности: " << c1.getRadius() << std::endl;

    c2 -= 1.0;
    std::cout << "Новый радиус второй окружности: " << c2.getRadius() << std::endl;

    Circle c3, c4;
    std::cin >> c3 >> c4;
    std::cout << c3 << std::endl << c4 << std::endl;
    std::cout << std::endl;

    Circle c5(c3);
    std::cout << c5 << std::endl;
}
#endif //H_W_4