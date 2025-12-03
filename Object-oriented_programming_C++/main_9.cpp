#include <iostream>
#include "Time.h"
#include "Complex.h"

//#define MAIN_9

#ifdef MAIN_9
int main() 
{
    setlocale(LC_ALL, "");

    //Time
    Time t1(10, 59, 59);
    Time t2(10, 0, 0);

    std::cout << "t1: " << t1 << std::endl;
    std::cout << "t2: " << t2 << std::endl;

    t1.incrementSecond();
    std::cout << "t1 + 1 second: " << t1 << std::endl;

    ++t1;
    std::cout << "++t1: " << t1 << std::endl;

    t1--;
    std::cout << "t1--: " << t1 << std::endl;

    if (t1 != t2) 
    {
        std::cout<< t1 << " != " << t2 << std::endl;
    }
    else
    {
        std::cout << t1 << " = " << t2 << std::endl;
    }

    Time t3 = t1 - t2;
    std::cout << t3 << std::endl;
    Time t4 = t1 + t2;
    std::cout << t4 << std::endl;

    Time t5;
    std::cin >> t5;
    std::cout << t5 << std::endl;
    t5 += t1;
    std::cout << t5 << std::endl;

    if (t5 > t2)
    {
        std::cout << t5 << " > " << t2 << std::endl;
    }
    else
    {
        std::cout << t5 << " < " << t2 << std::endl;
    }

    Time t6(t5);
    std::cout << t6 << std::endl << std::endl;
    

    //Complex
    Complex c1(3, 4); // 3 + 4i
    Complex c2(1, -2); // 1 - 2i

    // Пример использования перегруженных операторов
    Complex c3 = c1 + c2;
    std::cout << "c1 + c2 = " << c3 << std::endl;

    Complex c4 = c1 - c2;
    std::cout << "c1 - c2 = " << c4 << std::endl;

    Complex c4_2 = c1 * c2;
    std::cout << "c1 * c2 = " << c4_2 << std::endl;
    
    Complex c4_3 = c1 / c2;
    std::cout << "c1 / c2 = " << c4_3 << std::endl;

    if (c1 == c2) 
    {
        std::cout << c1 << " == " << c2 << std::endl;
    }
    else 
    {
        std::cout << c1 << " != " << c2 << std::endl;
    }

    // Пример ввода комплексного числа
    Complex c5;
    std::cout << "Введите комплексное число (например, 5 + 6i): ";
    std::cin >> c5;
    std::cout << "Вы ввели: " << c5 << std::endl;

    Complex c6;
    std::cout << c6 << std::endl;

    Complex c7(3);
    std::cout << c7 << std::endl;

    Complex c8(c4);
    std::cout << c8 << std::endl;
}
#endif //MAIN_9