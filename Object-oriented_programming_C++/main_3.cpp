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

	user.setX(20);
	user.setY(15);
	user.setZ(10);
	user.show();

	Point p1(5);
	p1.show();
}
#endif //MAIN_3