#include <iostream>
#include "Lift.h"

//#define MAIN_2

class Date
{
	int day;
	int month;
	int year;

public:
	//сеттеры (мутаторы, модификаторы)
	Date()
	{
		day = 1;
		month = 05;
		year = 1999;
		std::cout << "Отработал без параметров";
	}
	Date(int d, int m, int y) 
	{
		day = d;
		month = m;
		year = y;
		std::cout << "Отработал с параметрами";
	}

	void setDay(int d)
	{
		day = d;
	}
	void setMonth(int m)
	{
		month = m;
	}
	void setYear(int y)
	{
		year = y;
	}
	//геттеры (аксессоры, инспекторы)
	int getDay()
	{
		return day;
	}
	int getMonth()
	{
		return month;
	}
	int getYear()
	{
		return year;
	}
	void show()
	{
		std::cout << day << "." << month << "." << year << std::endl;
	}
};

#ifdef MAIN_2
int main() 
{
	setlocale(LC_ALL, "");

	Date d{1,1,1999};
	d.show();
	d.setDay(5);
	d.setMonth(10);
	d.setYear(1995);
	d.show();
	std::cout << d.getDay() << std::endl;

	Date d2;
	d2.show();

	Lift l;
	l.setDown(1);
	l.setUp(9);
	l.setCurrent(1);
	l.show();
	l.setOn_Off();
	l.show();
	l.setCurrent(7);
	l.show();
	l.setUp(6);
	l.show();

	std::cout << "Текущее состояние лифта: " << (l.getOn_Off() ? "работает" : "не работает") << std::endl;
	std::cout << "Текущий этаж: " << l.getCurrent() << std::endl;
}
#endif //MAIN_2