#include <iostream>
#include "Drob.h"

//#define MAIN_4

#ifdef MAIN_4
int main() 
{
    setlocale(LC_ALL, "");
    
    std::cout << "Дробь по умолчанию: ";
    Drob def;
    def.show();

    Drob a(3, 4);
    Drob b(1, 2);

    std::cout << "\nСложение: ";
    a.add(b);
    a.show(); // Должен вывести 10/8

    a.setNum(3);
    a.setDenom(4);

    std::cout << "\nВычитание: ";
    a.subtract(b);
    a.show(); // Должен вывести 2/8

    a.setNum(3);
    a.setDenom(4);

    std::cout << "\nУмножение: ";
    a.multiply(b);
    a.show(); // Должен вывести 3/8

    a.setNum(3);
    a.setDenom(4);

    std::cout << "\nДеление: ";
    a.divide(b);
    a.show(); // Должен вывести 6/4
}
#endif //MAIN_4