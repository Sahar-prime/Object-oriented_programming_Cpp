#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Worker.h"

Worker::Worker(const char* name, const char* pos, int year, double sal): yearOfEmployment(year), salary(sal)
{
    strncpy(fullName, name, sizeof(fullName) - 1);
    fullName[sizeof(fullName) - 1] = '\0';
    strncpy(position, pos, sizeof(position) - 1);
    position[sizeof(position) - 1] = '\0';
}

const char* Worker::getFullName() const
{
    return fullName;
}
const char* Worker::getPosition() const 
{
    return position;
}
int Worker::getYearOfEmployment() const 
{
    return yearOfEmployment;
}
double Worker::getSalary() const 
{
    return salary;
}

void Worker::displayInfo() const 
{
    std::cout << "ФИО: " << fullName
        << ", Должность: " << position
        << ", Год поступления: " << yearOfEmployment
        << ", Зарплата: " << salary << std::endl << std::endl;
}

void Worker::displayWorkersWithExperience(const Worker workers[], int size, int minYears, int currentYear)
{
    std::cout << "Список работников со стажем более " << minYears << " лет:" << std::endl;
    for (int i = 0; i < size; ++i)
    {
        if (currentYear - workers[i].getYearOfEmployment() > minYears)
        {
            workers[i].displayInfo();
        }
    }
}

void Worker::displayWorkersWithSalary(const Worker workers[], int size, double minSalary) 
{
    std::cout << "Список работников с зарплатой более " << minSalary << ":" << std::endl;
    for (int i = 0; i < size; ++i) 
    {
        if (workers[i].getSalary() > minSalary) 
        {
            workers[i].displayInfo();
        }
    }
}

void Worker::displayWorkersByPosition(const Worker workers[], int size, const char* position)
{
    std::cout << "Список работников на должности \"" << position << "\":" << std::endl;
    for (int i = 0; i < size; ++i)
    {
        if (strcmp(workers[i].getPosition(), position) == 0)
        {
            workers[i].displayInfo();
        }
    }
}
