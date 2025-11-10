#pragma once
class Point
{
	float x, y, z;//порядок влияет на заполнение
public:
	//Point() : x{ 0 }, y{ 0 }, z{ 0 } {};
	Point() : Point{ 0, 0, 0 } {};
	//Point(float user) : x{ user }, y{ user }, z{ user } {};//порядок не влияет на заполение
	Point(float user) : Point{ user, user, user } {};
	Point(float x, float y, float z);
	~Point();//сообщает о своей работе

	void init();
	void show();

	float getX();
	float getY();
	float getZ();

	Point& setX(float x);
	Point& setY(float y);
	Point& setZ(float z);
};

