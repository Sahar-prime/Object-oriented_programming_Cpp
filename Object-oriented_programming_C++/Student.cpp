#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <iostream>

void Student::init()
{
	std::cout << "Введите имя студента: ";
	std::cin.getline(name, 20);
	std::cout << "Введите оценки студента (3 оценки): ";
	for (int i = 0; i < 3; i++)
	{
		std::cin >> marks[i];
	}
}

void Student::setName(const char* uname)
{
	strcpy(name, uname);
}
char* Student::getName()
{
	return name;
}

void Student::setMark(int mark, int index)
{
	marks[index] = mark;
}
int Student::getMark(int index)
{
	return marks[index];
}

void Student::show()
{
	std::cout << "Имя: " << name << std::endl;
	std::cout << "Оценки: ";
	for (int i = 0; i < 3; i++)
	{
		std::cout << marks[i] << " ";
	}
	std::cout << std::endl;
}

double Student::aver()
{
	double sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += marks[i];
	}
	return sum / 3.0;
}