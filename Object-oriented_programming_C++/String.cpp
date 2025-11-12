#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <iostream>

// Конструктор по умолчанию
String::String() : length(80) 
{
    str = new char[length + 1];
    for (size_t i = 0; i < length; ++i)
    {
        str[i] = '.';
    }
    str[length] = '\0';
    std::cout << "Отработал конструктор: " << this << std::endl;
}

// Конструктор с указанием размера
String::String(size_t size) : length(size)
{
    str = new char[length + 1];
    for (size_t i = 0; i < length; ++i)
    {
        str[i] = '.';
    }
    str[length] = '\0';
    std::cout << "Отработал конструктор: " << this << std::endl;
}

String::String(const char* str) 
{
    length = strlen(str);
    this->str = new char[length + 1];
    strcpy(this->str, str);
    std::cout << "Отработал конструктор: " << this << std::endl;
}

// Конструктор копирования
String::String(const String& s) 
{
    length = s.length;
    str = new char[length + 1];
    strcpy(str, s.str);
    std::cout << "Отработал конструктор: " << this << std::endl;
}

// Деструктор
String::~String() 
{
    delete[] this->str;
    std::cout << "Отработал конструктор: " << this << std::endl;
}

// Метод для вывода строки
void String::print() const
{
    std::cout << str << std::endl;
}