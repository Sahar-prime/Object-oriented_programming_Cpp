#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <iostream>

Date::Date(int d, int m, int y) : day{ d }, month{ m }, year{ y }
{
	std::cout << "Отработал конструктор: " << this << "\n";
}
Date::Date():Date{ 1,1,1970 } {}

Date::Date(const Date& obj) // Поверхностное копирование
	: day{ obj.day }, month{ obj.month }, year{ obj.year }
{
	std::cout << "Отработал конструктор копирования: " << this << "\n";
}
Date::Date(Date&& obj)noexcept : day{obj.day}, month{ obj.month }, year{ obj.year }
{
	obj.day = 0;
	obj.month = 0;
	obj.year = 0;
	std::cout << "Отработал конструктор перемещения: " << this << std::endl;
}

Date& Date::setDay(int day)
{
	this->day = day; //1 - конфликт имён переменных
	return *this;
}
Date& Date::setMonth(int month)
{
	this->month = month;
	return *this;
}
Date& Date::setYear(int year)
{
	this->year = year;
	return *this;
}

int Date::getDay()
{
	return day;
}
int Date::getMonth()
{
	return month;
}
int Date::getYear()
{
	return year;
}

void Date::show()
{
	std::cout << this->day << "." << month << "." << year << std::endl;
}

Date::~Date()
{
	std::cout << "Отработал деструктор: " << this << "\n";
}