#pragma once
#include "MedalRow.h"
class MedalTable
{
    MedalRow* medalRows;
    int size;
    int capacity;

    int findCountry(const char* country) const;

public:
    MedalTable(int initialCapacity = 10);
    ~MedalTable();

    // Конструктор копирования
    MedalTable(const MedalTable& other);
    // Оператор присваивания копированием
    MedalTable& operator=(const MedalTable& other);

    // Конструктор перемещения
    MedalTable(MedalTable&& other) noexcept;
    // Оператор присваивания перемещением
    MedalTable& operator=(MedalTable&& other) noexcept;

    MedalRow& operator[](const char* country);
    MedalRow operator[](const char* country) const;

    void print() const;
};