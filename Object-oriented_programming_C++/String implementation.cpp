#include "String.h"
#include <iostream>

//#define MAIN

#ifdef MAIN
int main() 
{
    setlocale(LC_ALL, "");
    String defaultString;
    std::cout << "Строка по умолчанию: ";
    defaultString.print();

    // Создаём строку с указанием размера
    String sizedString(10);
    std::cout << "Строка с размером 10: ";
    sizedString.print();

    // Создаём строку
    String cString("Привет, мир!");
    cString.print();

    // Создаём копию строки
    String copiedString = cString;
    std::cout << "Копия строки: ";
    copiedString.print();

    // Выводим строку несколько раз по цепочке
    String t("hello world");
    t.print().print().print();

    String a("FFF"), b("DDD");
    String c{ a + b };
    c.print();

    String m("fffds");
    String s6 = -m;
    s6.print();

    String s5 = cString * 3;
    s5.print();
}

#endif //MAIN