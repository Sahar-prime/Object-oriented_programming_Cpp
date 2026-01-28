#include <iostream>

//#define H_W_7

class Employer
{
public:
    virtual void Print() const 
    {
        std::cout << "Employer: Базовый служащий.\n";
    }
};
class President : public Employer
{
public:
    void Print() const
    {
        std::cout << "Президент: Руководит компанией, принимает стратегические решения.\n";
    }
};
class Manager : public Employer
{
public:
    void Print() const
    {
        std::cout << "Менеджер: Управляет отделом, координирует работу сотрудников.\n";
    }
};
class Worker : public Employer
{
public:
    void Print() const
    {
        std::cout << "Рабочий: Выполняет основные производственные задачи.\n";
    }
};

#ifdef H_W_7
int main()
{
    setlocale(LC_ALL, "");

    Employer* employees[] =
    {
        new President(),
        new Manager(),
        new Worker()
    };
    int user;
    std::cout << "Выбери служащего:\n1 - Президент\n2 - Менеджер\n3 - Рабочий\n";
    std::cout << "Ваш выбор: ";
    std::cin >> user;
    if (user >= 4 or user <= 0)
    {
        std::cout << "Такого рабочего нет!";
    }
    else
    {
        employees[user - 1]->Print();
    }
}
#endif //H_W_7