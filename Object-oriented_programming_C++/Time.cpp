#include "Time.h"

Time::Time() : hours(0), minutes(0), seconds(0) {}
Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s)
{
    normalize();
}
Time::Time(const Time& other) : hours(other.hours), minutes(other.minutes), seconds(other.seconds) {}


// Функция для приращения времени на 1 секунду
void Time::incrementSecond()
{
    seconds++;
    normalize();
}