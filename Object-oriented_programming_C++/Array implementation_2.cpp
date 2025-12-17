#include <iostream>
#include "Array.h"

//#define MAIN

//void test(int& a, int b) 
//{
//	if (a != 0) 
//	{
//
//	}
//}

int max(int a, int b) 
{
	return a > b ? a : b;
}

#ifdef MAIN
int main() 
{
	setlocale(LC_ALL, "");
	int x = 10;
	/*int& refX = x + 10;
	int&& refX = x;*/
	int&& refX = x + 10;
	//int&& refXX = refX; у объекта уже есть имя
	int& refXX = refX;
	int&& test = max(5, 7);
	int&& test_2 = 2 + 3;
	test += 10;

	int b = x + 10;

	int&& test_3 = std::move(test);

	//int& refX = x; //L-value ссылки (на объект, у которого есть имя)
	//const int& refXX = x;
	//const int& refXXX = x + 20;
	//int&& reffX = x + 20; //R-value ссылка (на объект без имени)
	//reffX += 10;

	//std::cout << x << " " << &x << std::endl;
	//std::cout << refX << " " << &refX << std::endl;
	//std::cout << refXX << " " << &refXX << std::endl;
	//std::cout << refXXX << " " << &refXXX << std::endl;
	//x = 100;
	//std::cout << x << " " << &x << std::endl;
	//std::cout << refX << " " << &refX << std::endl;
	//std::cout << refXX << " " << &refXX << std::endl;
	//std::cout << refXXX << " " << &refXXX << std::endl;
	//refX = 1;
	//std::cout << x << " " << &x << std::endl;
	//std::cout << refX << " " << &refX << std::endl;
	//std::cout << refXX << " " << &refXX << std::endl;
	//std::cout << refXXX << " " << &refXXX << std::endl;

	//std::cout << 5 + 10 << std::endl;
	/*refXX = 5;
	std::cout << x << " " << &x << std::endl;
	std::cout << refX << " " << &refX << std::endl;
	std::cout << refXX << " " << &refXX << std::endl;*/
}
#endif //MAIN