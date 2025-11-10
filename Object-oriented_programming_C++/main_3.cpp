#include <iostream>
#include "Point.h"
#include "Person.h"

//#define MAIN_3

#ifdef MAIN_3
int main() 
{
	setlocale(LC_ALL, "");

	Point user;
	user.show();
	user.init();
	user.show();

	user.setX(20.7);
	user.setY(15.43);
	user.setZ(10.24);
	user.show();

	Point p1(2.11);
	p1.show();
	
	Point p2{2.221, 5.32, 3.89};
	p2.show();
	std::cout << std::endl;

	Person p3;
	p3.show();
	Person p4{15};
	p4.show();
	Person p5{"TOM"};
	p5.show();
	Person p6{ "Jack", 10 };
	p6.show();
	Person p7{p6};
	p7.show();

}
#endif //MAIN_3