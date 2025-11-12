#include "String.h"
#include <iostream>

//#define TEST

#ifdef TEST
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

}

#endif //TEST