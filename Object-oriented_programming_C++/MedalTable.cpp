#include <iostream>
#include "MedalTable.h"

MedalTable::MedalTable(int initialCapacity)
    : size(0), capacity(initialCapacity), medalRows(new MedalRow[initialCapacity]) {}

MedalTable::~MedalTable()
{
    delete[] medalRows;
}

MedalTable::MedalTable(const MedalTable& other)
    : size(other.size), capacity(other.capacity), medalRows(new MedalRow[other.capacity]) 
{
    for (int i = 0; i < size; ++i) 
    {
        medalRows[i] = other.medalRows[i];
    }
}

MedalTable& MedalTable::operator=(const MedalTable& other)
{
    if (this != &other)
    {
        delete[] medalRows;
        size = other.size;
        capacity = other.capacity;
        medalRows = new MedalRow[capacity];
        for (int i = 0; i < size; ++i) 
        {
            medalRows[i] = other.medalRows[i];
        }
    }
    return *this;
}

MedalTable::MedalTable(MedalTable&& other) noexcept
    : size(other.size), capacity(other.capacity), medalRows(other.medalRows)
{
    other.medalRows = nullptr;
    other.size = 0;
    other.capacity = 0;
}

MedalTable& MedalTable::operator=(MedalTable&& other) noexcept
{
    if (this != &other)
    {
        delete[] medalRows;
        medalRows = other.medalRows;
        size = other.size;
        capacity = other.capacity;
        other.medalRows = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

int MedalTable::findCountry(const char* country) const
{
    for (int i = 0; i < size; ++i)
    {
        if (strcmp(medalRows[i].getCountry(), country) == 0)
            return i;
    }
    return -1;
}

MedalRow& MedalTable::operator[](const char* country)
{
    int index = findCountry(country);
    if (index == -1)
    {
        if (size >= capacity)
        {
            capacity *= 2;
            MedalRow* newMedalRows = new MedalRow[capacity];
            for (int i = 0; i < size; ++i)
                newMedalRows[i] = std::move(medalRows[i]);
            delete[] medalRows;
            medalRows = newMedalRows;
        }
        index = size++;
        medalRows[index].setCountry(country);
    }
    return medalRows[index];
}

MedalRow MedalTable::operator[](const char* country) const
{
    int index = findCountry(country);
    if (index == -1)
        throw std::out_of_range("Country not found");
    return medalRows[index];
}

void MedalTable::print() const
{
    for (int i = 0; i < size; ++i)
        medalRows[i].print();
}
