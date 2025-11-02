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

Student::Student()
{
	creatStr("NoName");
	count = 3;
	marks = new int[count];
	for (int i = 0; i < count; i++)
	{
		marks[i] = 0;
	}
}
Student::Student(const char* uname)
{
	creatStr(uname);
	count = 3;
	marks = new int[count];
	for (int i = 0; i < count; i++)
	{
		marks[i] = 0;
	}
}
Student::Student(int* umarks, int ucount)
{
	creatStr("NoName");
	count = ucount;
	marks = new int[ucount];
	for (int i = 0; i < ucount; i++)
	{
		marks[i] = umarks[i];
	}
}
Student::Student(const char* uname, int* umarks, int ucount)
{
	creatStr(uname);
	count = ucount;
	marks = new int[ucount];
	for (int i = 0; i < ucount; i++)
	{
		marks[i] = umarks[i];
	}
};
Student::~Student() 
{
	delete[]name;
	delete[]marks;
	std::cout << "Отработал деструктор\n";
}

void Student::creatStr(const char* uname)
{
	name = new char[strlen(uname) + 1];
	strcpy(name, uname);
}

void Student::setName(const char* uname)
{
	delete[]name;
	name = new char[strlen(uname) + 1];
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