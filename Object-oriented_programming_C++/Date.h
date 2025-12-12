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
	Date(Date&& obj)noexcept;
	Date& setDay(int day);
	Date& setMonth(int month);
	Date& setYear(int year);
	//геттеры (аксессоры, инспекторы)
	int getDay();
	int getMonth();
	int getYear();
	void show();

	Date& operator=(const Date& other) 
	{
		if (this != &other)
		{
			day = other.day;
			month = other.month;
			year = other.year;
		}
		return *this;
	}
	Date& operator=(Date&& other) noexcept
	{
		if (this != &other) 
		{
			day = other.day;
			month = other.month;
			year = other.year;
			other.day = 0;
			other.month = 0;
			other.year = 0;
		}
		return *this;
	}

	Date& operator+=(int days)
	{
		day += days;
		while (day > 31) 
		{
			day -= 31;
			month++;
			if (month > 12) 
			{
				month = 1;
				year++;
			}
		}
		return *this;
	}
	Date& operator-=(int days) 
	{
		day -= days;
		while (day < 1)
		{
			month--;
			if (month < 1) 
			{
				month = 12;
				year--;
			}
			day += 31;
		}
		return *this;
	}

	friend Date& operator++(Date& date);    // Префиксный ++
	friend Date operator++(Date& date, int);  // Постфиксный ++
	friend Date& operator--(Date& date);    // Префиксный --
	friend Date operator--(Date& date, int);  // Постфиксный --
	friend int operator-(const Date& date1, const Date& date2);
	friend bool operator==(const Date& date1, const Date& date2);
	friend bool operator!=(const Date& date1, const Date& date2);
	friend bool operator>(const Date& date1, const Date& date2);
	friend bool operator<(const Date& date1, const Date& date2);
	friend std::ostream& operator<<(std::ostream& os, const Date& date);
	friend std::istream& operator>>(std::istream& is, Date& date);

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

inline bool operator==(const Date& date1, const Date& date2) 
{
	return date1.day == date2.day && date1.month == date2.month && date1.year == date2.year;
}
inline bool operator!=(const Date& date1, const Date& date2) 
{
	return !(date1 == date2);
}
inline bool operator>(const Date& date1, const Date& date2) 
{
	if (date1.year != date2.year) return date1.year > date2.year;
	if (date1.month != date2.month) return date1.month > date2.month;
	return date1.day > date2.day;
}
inline bool operator<(const Date& date1, const Date& date2)
{
	return !(date1 > date2) && !(date1 == date2);
}

inline std::ostream& operator<<(std::ostream& os, const Date& date) 
{
	os << date.day << "." << date.month << "." << date.year;
	return os;
}
inline std::istream& operator>>(std::istream& is, Date& date) 
{
	is >> date.day >> date.month >> date.year;
	return is;
}