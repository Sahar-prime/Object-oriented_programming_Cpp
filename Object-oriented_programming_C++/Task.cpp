﻿#include <iostream>
#include "Task.h"

void Task::input()
{
    std::cout << "Введи название: ";
    std::cin.getline(title , 50);
    std::cout << "Введи описание: ";
    std::cin.getline(description, 150);
    std::cout << "Введи статус (1 - выполнена, 0 - не выполнена): ";
    std::cin >> status;
}

void Task::print()
{
    std::cout << "Название: " << title << std::endl;
    std::cout << "Описание: " <<description << std::endl;
    std::cout << "Статус: " << (status ? "выполнена" : "не выполнена") << std::endl;
}