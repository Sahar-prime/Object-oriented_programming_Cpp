#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Task.h"

Task::Task()
{
    strcpy(title, "Без названия");
    strcpy(description, "Без описания");
    status = false;
    std::cout << "Отработал конструктор: " << this << std::endl;
}

Task::Task(const char* newTitle, const char* newDescription, bool newStatus)
{
    strcpy(title, newTitle);
    strcpy(description, newDescription);
    status = newStatus;
    std::cout << "Отработал конструктор: " << this << std::endl;
}

Task::Task(const Task& other)
{
    strcpy(title, other.title);
    strcpy(description, other.description);
    status = other.status;
    std::cout << "Отработал конструктор копирования: " << this << std::endl;
}

Task::~Task()
{
    std::cout << "Отработал конструктор: " << this << std::endl;
}

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

Task& Task::setTitle(const char* title)
{
    strcpy(this->title, title);
    return *this;
}

Task& Task::setDescription(const char* description)
{
    strcpy(this->description, description);
    return *this;
}

Task& Task::setStatus(bool status) 
{
    this->status = status;
    return *this;
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