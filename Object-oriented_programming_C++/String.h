#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
class String
{
    char* str; // Указатель на динамический массив символов
    size_t length; // Длина строки

public:
    // Конструктор по умолчанию: создаёт строку длиной 80 символов
    String();

    // Конструктор, позволяющий создавать строку произвольного размера
    String(size_t size);

    // Конструктор, создающий строку и инициализирующий её строкой от пользователя
    String(const char* userStr);

    // Конструктор копирования
    String(const String& s);

    // Деструктор для освобождения памяти
    ~String();

    // Метод для вывода строки (для проверки)
    String& print();

    friend String operator+(const String& left, const String& right);
    friend String operator*(const String& s, unsigned int multiplier);
    friend String operator-(const String& s);
};

inline String operator+(const String& left, const String& right)
{
    size_t newLength = left.length + right.length;
    char* tempStr = new char[newLength + 1];

    strcpy(tempStr, left.str);
    strcat(tempStr, right.str);

    String result(tempStr);
    delete[] tempStr;

    return result;
}

inline String operator*(const String& s, unsigned int multiplier)
{
    size_t newLength = s.length * multiplier;
    char* tempStr = new char[newLength + 1];
    tempStr[0] = '\0';

    for (unsigned int i = 0; i < multiplier; ++i)
    {
        strcat(tempStr, s.str);
    }

    String result(tempStr);
    delete[] tempStr;

    return result;
}

inline String operator-(const String& s)
{
    String reversedStr(s); 

    size_t start = 0;
    size_t end = s.length - 1; 

    while (start < end)
    {
        char temp = reversedStr.str[start];
        reversedStr.str[start] = reversedStr.str[end];
        reversedStr.str[end] = temp;

        start++;
        end--;
    }

    return reversedStr;
}
