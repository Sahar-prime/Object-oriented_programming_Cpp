#define _CRT_SECURE_NO_WARNINGS
#include "Overcoat.h"
#include <iostream>

Overcoat::Overcoat() : type(nullptr), price(0.0)
{
    type = new char[1];
    type[0] = '\0';
}

Overcoat::Overcoat(const char* type, double price) : price(price)
{
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);
}

Overcoat::~Overcoat() 
{
    delete[] type;
}

bool Overcoat::operator==(const Overcoat& other) const
{
    return strcmp(this->type, other.type) == 0;
}

Overcoat& Overcoat::operator=(const Overcoat& other) 
{
    if (this == &other) 
    {
        return *this;
    }
    delete[] type;
    type = new char[strlen(other.type) + 1];
    strcpy(type, other.type);
    price = other.price;
    return *this;
}

bool Overcoat::operator>(const Overcoat& other) const 
{
    if (strcmp(this->type, other.type) != 0) 
    {
        return false; // Разные типы, сравнение по цене не имеет смысла
    }
    return this->price > other.price;
}

const char* Overcoat::getType() const 
{
    return type;
}
double Overcoat::getPrice() const 
{
    return price;
}