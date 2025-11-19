#include <iostream>
#include "Point_2.h"

//#define MAIN_7

#ifdef MAIN_7
int main() 
{
	Point_2 p1, p2{ 5,10 };
	if (Point_2::isEqual(p1, p2)) 
	{
		std::cout << "Equal\n";
	}
	else 
	{
		std::cout << "No equal\n";
	}
	p1.init();
	p1.show();
	std::cout << std::endl;
	Point_2 p3{ Point_2::add(p1, p2) };
	p3.show();
	Point_2 p4{ Point_2::mult(p1, 3.5) };
	p4.show();
	std::cout << Point_2::distance(p3, p4) << std::endl;
	//std::cout << p3%p4 << std::endl;
	std::cout << p3.lenght() << std::endl;
	//std::cout << !p3 << std::endl;
	//$p4 - нельзя (нет такого оператора)
	//p4 = p3 p4+=3 (+ = += -разные операторы)
	//нельзя поменять количество операндов
	//Рекомендация - не использовать операторы, которые не очевидны
}
#endif //MAIN_7