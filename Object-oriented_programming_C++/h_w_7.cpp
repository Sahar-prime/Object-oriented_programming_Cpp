#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//#define H_W_7

class Employer
{
protected:
    char* name;
public:
    Employer(const char* name)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    virtual void Print() const = 0;
    virtual ~Employer()
    {
        delete[] name;
    }
};
class President : public Employer
{
private:
    double profit;
public:
    President(const char* name, double profit)
        : Employer(name), profit(profit) {}
    void Print() const
    {
        std::cout << "Президент: " << name << "\n"
            << "Руководит компанией, принимает стратегические решения.\n"
            << "Прибыль компании: " << profit << " млн.\n";
    }
};
class Manager : public Employer
{
private:
    int subordinates;
public:
    Manager(const char* name, int subordinates)
        : Employer(name), subordinates(subordinates) {}
    void Print() const
    {
        std::cout << "Менеджер: " << name << "\n"
            << "Управляет отделом, координирует работу сотрудников.\n"
            << "Количество подчинённых: " << subordinates << "\n";
    }
};
class Worker : public Employer
{
private:
    int hours;
public:
    Worker(const char* name, int hours)
        : Employer(name), hours(hours) {}
    void Print() const
    {
        std::cout << "Рабочий: " << name << "\n"
            << "Выполняет основные производственные задачи.\n"
            << "Количество рабочих часов: " << hours << "\n";
    }
};

#ifdef H_W_7
int main()
{
    setlocale(LC_ALL, "");

    Employer* employees[] =
    {
        new President("Иванов Иван Иванович", 150.5),
        new Manager("Петров Петр Петрович", 10),
        new Worker("Сидоров Сидор Сидорович", 40)
    };
    int user;
    std::cout << "Выбери служащего:\n"
        << "1 - Президент\n"
        << "2 - Менеджер\n"
        << "3 - Рабочий\n"
        << "Ваш выбор: ";
    std::cin >> user;
    if (user >= 4 || user <= 0)
    {
        std::cout << "Такого рабочего нет!";
    }
    else
    {
        employees[user - 1]->Print();
    }
    for (int i = 0; i < 3; ++i)
    {
        delete employees[i];
    }
}
#endif //H_W_7