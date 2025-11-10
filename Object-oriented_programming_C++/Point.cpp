#include "Point.h"
#include <iostream>

/*
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
*/

Point::~Point()
{
	std::cout << "Отработал деструктор: " << this << "\n";
}
Point::Point(float x, float y, float z) : x{ x }, y { y }, z { z } 
{
	std::cout << "Отработал конструктор: " << this << "\n";
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
	std::cout << "Point:" << this->x << ", " << this->y << ", " << this->z << std::endl;
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

Point& Point::setX(float x)
{
	this->x = x;
	return *this;
}
Point& Point::setY(float y)
{
	this->y = y;
	return *this;
}
Point& Point::setZ(float z)
{
	this->z = z;
	return *this;
}