#include <iostream>
#include "Point.h"

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
}
#endif //MAIN_3