#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
class Date
{
	int day;
	int month;
	int year;

public:
	//сеттеры (мутаторы, модификаторы)
	Date();
	Date(int d, int m, int y);
	Date(const Date& obj);
	Date& setDay(int day);
	Date& setMonth(int month);
	Date& setYear(int year);
	//геттеры (аксессоры, инспекторы)
	int getDay();
	int getMonth();
	int getYear();
	void show();

	friend Date& operator++(Date& date);    // Префиксный ++
	friend Date operator++(Date& date, int);  // Постфиксный ++
	friend Date& operator--(Date& date);    // Префиксный --
	friend Date operator--(Date& date, int);  // Постфиксный --
	friend int operator-(const Date& date1, const Date& date2);

	//Диструктор
	~Date();
};

inline Date& operator++(Date& date)
{
	date.day++;
	// Проверка на переход к следующему месяцу
	if (date.day > 31)
	{
		date.day = 1;
		date.month++;
		if (date.month > 12)
		{
			date.month = 1;
			date.year++;
		}
	}
	return date;
}

inline Date operator++(Date& date, int)
{
	Date temp = date;
	++date;
	return temp;
}

inline Date& operator--(Date& date)
{
	date.day--;
	if (date.day < 1) 
	{
		date.month--;
		if (date.month < 1) 
		{
			date.month = 12;
			date.year--;
		}
		date.day = 31;
	}
	return date;
}

inline Date operator--(Date& date, int)
{
	Date temp = date;
	--date;
	return temp;
}

inline int operator-(const Date& date1, const Date& date2)
{
	// Упрощённая логика: считаем разницу в днях без учёта месяцев и лет
	int days1 = date1.year * 365 + date1.month * 31 + date1.day;
	int days2 = date2.year * 365 + date2.month * 31 + date2.day;
	return days1 - days2;
}