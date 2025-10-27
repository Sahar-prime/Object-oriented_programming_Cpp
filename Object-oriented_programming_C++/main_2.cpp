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
		std::cout << day << "." << month << "." << year;
	}
};

#ifdef MAIN_2
int main() 
{
	setlocale(LC_ALL, "");

	Date d;
	d.setDay(5);
	d.setMonth(10);
	d.setYear(1995);
	d.show();
	std::cout << d.getDay() << std::endl;

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