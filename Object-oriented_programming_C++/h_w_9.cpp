#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//#define H_W_9

class Person
{
protected:
    char* name;
    int age;
public:
    Person(const char* name, int age) :
        name{ new char[strlen(name) + 1] },
        age{ age }
    {
        strcpy(this->name, name);
    }
    void set_name(const char* n)
    {
        delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    const char* get_name() const 
    {
        return name; 
    }
    void set_age(int age) 
    {
        this->age = age; 
    }
    int get_age() const 
    {
        return age; 
    }
    virtual ~Person()
    { 
        delete[] name; 
    }
    virtual void show() const
    {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};
class Employer : public Person
{
    char* position;
public:
    Employer(const char* name, int age, const char* position) :
        Person(name, age),
        position{ new char[strlen(position) + 1] }
    {
        strcpy(this->position, position);
    }
    Employer() : Person("", 0), position{ nullptr } {}
    void set_position(const char* p) 
    {
        delete[] position;
        position = new char[strlen(p) + 1];
        strcpy(position, p);
    }
    const char* get_position() const
    {
        return position;
    }
    virtual ~Employer()
    {
        delete[] position;
    }
    virtual void show() const 
    {
        Person::show();
        std::cout << "Position: " << position << std::endl;
    }
};
class Company
{
    char* company_name;
    Employer* employees;
    int count;
public:
    Company(const char* company_name, const Employer* emps, int count) :
        company_name{ new char[strlen(company_name) + 1] },
        employees{ new Employer[count] },
        count{ count }
    {
        strcpy(this->company_name, company_name);
        for (int i = 0; i < count; ++i)
        {
            employees[i] = Employer(emps[i].get_name(), emps[i].get_age(), emps[i].get_position());
        }
    }
    virtual ~Company()
    {
        delete[] company_name;
        delete[] employees;
    }
    virtual void show() const 
    {
        std::cout << "Company: " << company_name << "\nEmployees:\n";
        for (int i = 0; i < count; ++i) {
            employees[i].show();
        }
    }
};

#ifdef H_W_9
int main() 
{
    setlocale(LC_ALL, "");

    Employer emps[2] = 
    {
        Employer("Ivan", 30, "Manager"),
        Employer("Petr", 25, "Developer")
    };
    Company company("MyCompany", emps, 2);
    company.show();
}
#endif //H_W_9