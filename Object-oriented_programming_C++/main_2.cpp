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
	Date() :Date{ 1,5,1999 } {}
	Date(int d, int m, int y) : day{ d }, month{ m }, year{y}
	{
		std::cout << "Отработал конструктор: " << this << "\n";
	}

	Date& setDay(int day)
	{
		this->day = day; //1 - конфликт имён переменных
		return *this;
	}
	Date& setMonth(int month)
	{
		this->month = month;
		return *this;
	}
	Date& setYear(int year)
	{
		this->year = year;
		return *this;
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
		std::cout << this->day << "." << month << "." << year << std::endl;
	}

	~Date() 
	{
		//3 - отладочная информация
		std::cout << "Отработал деструктор: " << this << "\n";
	}
};

#ifdef MAIN_2
int main() 
{
	setlocale(LC_ALL, "");

	Date d{1,1,1999};
	d.show();
	/*d.setDay(5);
	d.setMonth(10);
	d.setYear(1995);
	d.show();
	std::cout << d.getDay() << std::endl;*/

	Date d2;
	d2.show();

	Date d3{ d2 };
	d3.show();

	Date d4;
	d4.setDay(20).setMonth(10).setYear(1954).show(); //2
	std::cout << std::endl;

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