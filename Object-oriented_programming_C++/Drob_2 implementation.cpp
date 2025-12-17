#include <iostream>
#include "Drob_2.h"

//#define MAIN

#ifdef MAIN
int main() 
{
	setlocale(LC_ALL, "");
	Drob_2 d1{ 100, 50};
	Drob_2 d2{ 10, 5 };
	d1.show();
	d2.show();
	if (d1 == d2) 
	{
		std::cout << "==" << std::endl;
	}
	else
	{
		std::cout << "!=" << std::endl;
	}
	std::cout << std::endl;

	Drob_2 d3{ 5, 50 };
	Drob_2 d4{ 10, 5 };
	d3.show();
	d4.show();
	if (d3 <= d4)
	{
		std::cout << "<=" << std::endl;
	}
	else
	{
		std::cout << "-" << std::endl;
	}
	std::cout << std::endl;

	Drob_2 d5{ 22, 8 };
	Drob_2 d6{ 50, 2 };
	d5.show();
	d6.show();
	if (d5 >= d6)
	{
		std::cout << ">=" << std::endl;
	}
	else
	{
		std::cout << "-" << std::endl;
	}
	std::cout << std::endl;

	Drob_2 d7{ 5, 50 };
	Drob_2 d8{ 10, 5 };
	d7.show();
	d8.show();
	if (d7 < d8)
	{
		std::cout << "<" << std::endl;
	}
	else
	{
		std::cout << ">" << std::endl;
	}
	std::cout << std::endl;

	Drob_2 d9{ 22, 8 };
	Drob_2 d10{ 50, 2 };
	d9.show();
	d10.show();
	if (d9 > d10)
	{
		std::cout << ">" << std::endl;
	}
	else
	{
		std::cout << "<" << std::endl;
	}
	std::cout << std::endl;
}
#endif //MAIN