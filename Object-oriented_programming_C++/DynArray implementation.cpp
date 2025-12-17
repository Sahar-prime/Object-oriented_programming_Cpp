#include <iostream>
#include "DynArray.h"

//#define MAIN

class Date_2
{
	int day, month, year;
public:
	void print()
	{
		std::cout << day << "." << month << "." << year << std::endl;
	}
	void operator()()
	{
		day++;
	}
	void operator()(int user)
	{
		day += user;
	}
	void operator()(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}
};

#ifdef MAIN
int main() 
{
	setlocale(LC_ALL, "");

	//Date_2
	Date_2 date;
	date(10, 5, 2025);
	std::cout << "Начальная дата: ";
	date.print();
	date();
	std::cout << "После date(): ";
	date.print();
	date(5);
	std::cout << "После date(5): ";
	date.print();
	std::cout << std::endl;

	//DynArray
	DynArray d_Arr(5, 3);
	d_Arr.randomize();
	d_Arr.print();
}
#endif //MAIN