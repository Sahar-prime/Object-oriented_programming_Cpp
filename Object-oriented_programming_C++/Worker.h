#pragma once
class Worker
{
private:
    char fullName[100];
    char position[50];
    int yearOfEmployment;
    double salary;

public:
    explicit Worker(const char* name, const char* pos, int year, double sal);

    // Константные функции-члены
    const char* getFullName() const;
    const char* getPosition() const;
    int getYearOfEmployment() const;
    double getSalary() const;

    // Функция для вывода информации о работнике
    void displayInfo() const;

    // Статические функции для работы с массивом объектов Worker
    static void displayWorkersWithExperience(const Worker workers[], int size, int minYears, int currentYear);
    static void displayWorkersWithSalary(const Worker workers[], int size, double minSalary);
    static void displayWorkersByPosition(const Worker workers[], int size, const char* position);
};
