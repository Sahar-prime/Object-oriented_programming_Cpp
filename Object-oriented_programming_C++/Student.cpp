#include "Student.h"
#include <iostream>

void Student::init()
{
	std::cout << "������� ��� ��������: ";
	std::cin.getline(name, 20);
	std::cout << "������� ������ �������� (3 ������): ";
	for (int i = 0; i < 3; i++)
	{
		std::cin >> marks[i];
	}
}

void Student::show()
{
	std::cout << "���: " << name << std::endl;
	std::cout << "������: ";
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