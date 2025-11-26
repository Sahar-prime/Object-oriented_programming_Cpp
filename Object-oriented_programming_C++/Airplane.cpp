#define _CRT_SECURE_NO_WARNINGS
#include "Airplane.h"
#include <iostream>

Airplane::Airplane(const char* airplane_type, int max_p)
    : current_passengers(0), max_passengers(max_p)
{
    strcpy(type, airplane_type);
}

// Методы для получения информации о самолете
const char* Airplane::getType() const
{ 
    return type;
}
int Airplane::getCurrentPassengers() const 
{
    return current_passengers; 
}
int Airplane::getMaxPassengers() const
{
    return max_passengers;
}