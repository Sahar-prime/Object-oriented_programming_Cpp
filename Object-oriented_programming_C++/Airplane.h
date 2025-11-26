#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <iostream>

class Airplane
{
    char type[50]; // Тип самолета (массив char)
    int current_passengers; // Текущее количество пассажиров
    int max_passengers; // Максимальное количество пассажиров
public:
    Airplane(const char* airplane_type, int max_p);

    // Методы для получения информации о самолете
    const char* getType() const;
    int getCurrentPassengers() const;
    int getMaxPassengers() const;

    friend bool operator==(const Airplane& lhs, const Airplane& rhs);
    friend bool operator!=(const Airplane& lhs, const Airplane& rhs);
    friend bool operator>(const Airplane& lhs, const Airplane& rhs);

    Airplane& operator++()
    {
        current_passengers++;
        return *this;

    }

    Airplane& operator--()
    {
        current_passengers--;
        return *this;

    }
};

inline bool operator==(const Airplane& lhs, const Airplane& rhs) 
{
    return strcmp(lhs.type, rhs.type) == 0;
}
inline bool operator!=(const Airplane& lhs, const Airplane& rhs)
{
    return strcmp(lhs.type, rhs.type) != 0;
}
inline bool operator>(const Airplane& lhs, const Airplane& rhs) 
{
    return lhs.max_passengers > rhs.max_passengers;
}