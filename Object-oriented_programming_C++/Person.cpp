#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Person.h"

/*
Person::Person() : name{ new char[strlen("NoName") + 1] }, age{ 0 }
{
	strcpy(name, "NoName");
}//NoName 0 
Person::Person(const char* uname) :name{ new char[strlen(uname) + 1] }, age{ 0 }
{
	strcpy(name, uname);
}//uname 0
Person::Person(int uage) : age{ uage }
{
	strcpy(name, "NoName");
}//NoName uage
*/

//главный конструктор
Person::Person(const char* uname, int uage) :name{ new char[strlen(uname) + 1] }, age{ uage }
{
	strcpy(name, uname);
	std::cout << "Отработал конструктор: " << this << std::endl;
}//uname uage

//делегирование конструкторов
Person::Person() : Person{ "NoName", 0 } {};
Person::Person(const char* uname) : Person{ uname, 0 } {};
Person::Person(int uage) :Person{ "NoName", uage } {};
Person::Person(const Person& p) : //Глубокое копирование(динамика)
	name{ new char[strlen(p.name) + 1] }, age{p.age}
{
	strcpy(name, p.name);
	std::cout << "Отработал конструктор копирования: " << this << std::endl;
}

Person::~Person()
{
	delete[] name;
	std::cout << "Отработал деструктор: " << this << "\n";
};

void Person::show()
{
	std::cout << "Name:" << name << std::endl;
	std::cout << "Age:" << age << std::endl;
}