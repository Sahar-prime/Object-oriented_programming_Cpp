#include "Point.h"
#include <iostream>

Point::Point() 
{
	x = 0;
	y = 0;
	z = 0;
}
Point::Point(float user)
{
	x = user;
	y = user;
	z = user;
}
Point::Point(float ux, float uy, float uz)
{
	x = ux;
	y = uy;
	z = uz;
}
Point::~Point()
{
	std::cout << "Отработал деструктор\n" << std::endl;
}

void Point::init() 
{
	std::cout << "Введите x:";
	std::cin >> x;
	std::cout << "Введите y:";
	std::cin >> y;
	std::cout << "Введите z:";
	std::cin >> z;
}
void Point::show()
{
	std::cout << "Point:" << x << ", " << y << ", " << z << std::endl;
}

float Point::getX()
{
	return x;
}
float Point::getY()
{
	return y;
}
float Point::getZ()
{
	return z;
}

void Point::setX(float ux)
{
	x = ux;
}
void Point::setY(float uy)
{
	y = uy;

}
void Point::setZ(float uz)
{
	z = uz;
}