#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <iostream>

String::String() : length(80)
{
    str = new char[length + 1]; // +1 для терминирующего нуля
    str[0] = '\0'; // Инициализация пустой строки
}

String::String(size_t size) : length(size)
{
    str = new char[length + 1];
    str[0] = '\0';
}

String::String(const char* userStr)
{
    length = strlen(userStr);
    str = new char[length + 1];
    strcpy(str, userStr);
}

String::~String()
{
    delete[] str;
}

void String::print() const 
{
    std::cout << str << std::endl;
}