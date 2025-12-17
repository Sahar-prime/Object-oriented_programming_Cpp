#include <iostream>
#include "DynArray.h"
#include "DynArray_2d.h"

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

	//DynArray_2d
	DynArray_2d array(3, 3);
	std::cout << "Введите элементы массива 3x3 (построчно):" << std::endl;
	array.init();
	std::cout << "\nВывод массива:" << std::endl;
	array.print();
	array(1, 1) = 9;
	std::cout << "\nМассив после изменения элемента [1][1] на 9:" << std::endl;
	array.print();
	std::cout << "\nЗначение элемента [0][1]: " << array(0, 1) << std::endl;
}
#endif //MAIN