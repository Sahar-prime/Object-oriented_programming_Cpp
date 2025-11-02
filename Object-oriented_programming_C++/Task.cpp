#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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
    std::cout << "Статус: " << (status ? "выполнена" : "не выполнена") << std::endl << std::endl;
}

void Task::setTitle(const char* newTitle)
{
    strcpy(title, newTitle);
}

void Task::setDescription(const char* newDescription)
{
    strcpy(description, newDescription);
}

void Task::setStatus(bool newStatus)
{
    status = newStatus;
}

const char* Task::getTitle() const
{
    return title;
}

const char* Task::getDescription() const
{
    return description;
}

bool Task::getStatus() const
{
    return status;
}