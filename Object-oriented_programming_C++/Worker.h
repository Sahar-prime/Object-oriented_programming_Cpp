#pragma once
class Worker
{

};

//ПРОТОТИП
/*
#include <iostream>

// Определение текущего года для расчета стажа
const int CURRENT_YEAR = 2025;
const int MAX_NAME_LENGTH = 50;
const int MAX_POSITION_LENGTH = 30;

class Worker {
private:
    char fullName[MAX_NAME_LENGTH];
    char position[MAX_POSITION_LENGTH];
    int startYear;
    double salary;

public:
    // Explicit конструктор
    explicit Worker(const char* name, const char* pos, int year, double sal) {
        // Копирование строк с использованием strcpy
        strncpy(fullName, name, MAX_NAME_LENGTH - 1);
        fullName[MAX_NAME_LENGTH - 1] = '\0'; // Гарантируем завершающий нулевой символ

        strncpy(position, pos, MAX_POSITION_LENGTH - 1);
        position[MAX_POSITION_LENGTH - 1] = '\0';

        startYear = year;
        salary = sal;
    }

    // Константная функция для расчета стажа
    int getExperience() const {
        return CURRENT_YEAR - startYear;
    }

    // Константная функция для получения зарплаты
    double getSalary() const {
        return salary;
    }

    // Константная функция для получения должности (возвращаем указатель на строку C-стиля)
    const char* getPosition() const {
        return position;
    }

    // Константная функция для отображения данных о работнике
    void display() const {
        std::cout << "ФИО: " << fullName
            << ", Должность: " << position
            << ", Год поступления: " << startYear
            << ", Зарплата: " << salary
            << ", Стаж: " << getExperience() << " лет" << std::endl;
    }
};
*/