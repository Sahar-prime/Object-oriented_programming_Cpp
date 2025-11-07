#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Drob.h"
#include "Stor.h"

//#define MAIN_4

class Stud
{
    char name[20];
    static int group; //Общее для всех объектов
public:
    Stud(const char* uname) 
    {
        strcpy(name, uname);
    }
    void show() 
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Group: " << group << std::endl << std::endl;;
    }
    static void setGroup(int g) 
    {
        group = g;
    }
    static int getGroup() //Не привязываем к объекту
    {
        return group;
    }
};

int Stud::group{ 111 }; //Создается до создания объектов

#ifdef MAIN_4
int main() 
{
    setlocale(LC_ALL, "");
    
    std::cout << "Всего занято " << Stor::getUsedMemory() << std::endl;
    Stor f1{ 5 };
    Stor f2{ 3 };
    Stor f3{ 4 };
    f1.print();
    f2.print();
    f3.print();
    std::cout << std::endl;

    //Stud
    Stud s1{ "Mary" };
    s1.show();
    Stud s2{ "Jack" };
    s2.show();
    s1.setGroup(222);
    s1.show();
    s2.show();
    s2.setGroup(333);
    s1.show();
    s2.show();
    std::cout << s1.getGroup() << std::endl;
    std::cout << s2.getGroup() << std::endl;
    std::cout << Stud::getGroup() << std::endl;
    Stud::setGroup(555);
    std::cout << Stud::getGroup() << std::endl << std::endl;

    ////Drob
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
    std::cout << std::endl;
}
#endif //MAIN_4