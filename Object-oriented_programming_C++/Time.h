#pragma once
#include <iostream>
class Time 
{
    int hours, minutes, seconds;

    void normalize()
    {
        minutes += seconds / 60;
        seconds %= 60;
        hours += minutes / 60;
        minutes %= 60;
        hours %= 24;
    }

public:
    // Конструкторы
    Time();
    Time(int h, int m, int s);
    Time(const Time& other); // Конструктор копирования

    // Функция для приращения времени на 1 секунду
    void incrementSecond();

    // Перегрузка операторов (обычная)
    Time operator++()
    {
        incrementSecond();
        return *this;
    }
    Time operator++(int)
    {
        Time temp = *this;
        incrementSecond();
        return temp;
    }
    Time operator--()
    {
        seconds--;
        normalize();
        return *this;
    }
    Time operator--(int)
    {
        Time temp = *this;
        seconds--;
        normalize();
        return temp;
    }

    Time operator+(const Time& other) const 
    {
        return Time(hours + other.hours, minutes + other.minutes, seconds + other.seconds);
    }
    Time operator-(const Time& other) const
    {
        int total1 = hours * 3600 + minutes * 60 + seconds;
        int total2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
        int diff = total1 - total2;
        if (diff < 0) diff = 0;
        return Time(diff / 3600, (diff % 3600) / 60, diff % 60);
    }
    Time& operator+=(const Time& other) 
    {
        hours += other.hours;
        minutes += other.minutes;
        seconds += other.seconds;
        normalize();
        return *this;
    }
    Time& operator-=(const Time& other)
    {
        int total1 = hours * 3600 + minutes * 60 + seconds;
        int total2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
        int diff = total1 - total2;
        if (diff < 0) diff = 0;
        hours = diff / 3600;
        minutes = (diff % 3600) / 60;
        seconds = diff % 60;
        return *this;
    }

    // Перегрузка операторов сравнения
    bool operator==(const Time& other) const
    {
        return (hours == other.hours && minutes == other.minutes && seconds == other.seconds);
    }
    bool operator!=(const Time& other) const 
    {
        return !(*this == other);
    }
    bool operator>(const Time& other) const 
    {
        if (hours != other.hours) return hours > other.hours;
        if (minutes != other.minutes) return minutes > other.minutes;
        return seconds > other.seconds;
    }
    bool operator<(const Time& other) const
    {
        if (hours != other.hours) return hours < other.hours;
        if (minutes != other.minutes) return minutes < other.minutes;
        return seconds < other.seconds;
    }

    // Перегрузка операторов ввода/вывода (дружественная)
    friend std::ostream& operator<<(std::ostream& os, const Time& time);
    friend std::istream& operator>>(std::istream& is, Time& time);
};

inline std::ostream& operator<<(std::ostream& os, const Time& time)
{
    os << time.hours << ":" << time.minutes << ":" << time.seconds;
    return os;
}
inline std::istream& operator>>(std::istream& is, Time& time)
{
    is >> time.hours >> time.minutes >> time.seconds;
    time.normalize();
    return is;
}