#include <iostream>
#include "Lift.h"

void Lift::setUp(int userMaxFloor)
{
    if (userMaxFloor >= currentFloor)
    {
        maxFloor = userMaxFloor;
    }
}

void Lift::setDown(int userMinFloor)
{
    if (userMinFloor <= currentFloor)
    minFloor = userMinFloor;
}

void Lift::setOn_Off() 
{
    isWorking = !isWorking;
}

bool Lift::getOn_Off() 
{
    return isWorking;
}

int Lift::getCurrent() 
{
    return currentFloor;
}

void Lift::setCurrent(int userFloor) 
{
    if (userFloor < minFloor || userFloor > maxFloor) 
    {
        std::cerr << "Ошибка: Некорректный этаж!" << std::endl;
        return;
    }
    currentFloor = userFloor;
}

void Lift::show() 
{
    std::cout << "Лифт ";
    if (!isWorking)
    {
        std::cout << "выключен";
    }
    else
    {
        std::cout << "включён";
    }
    std::cout << ", текущий этаж: " << currentFloor << std::endl;
}
