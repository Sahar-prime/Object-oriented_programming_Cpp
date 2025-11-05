#pragma once
class Point
{
	float x, y, z;//порядок влияет на заполнение
public:
	//Point() : x{ 0 }, y{ 0 }, z{ 0 } {};
	Point() : Point{ 0, 0, 0 } {};
	//Point(float user) : x{ user }, y{ user }, z{ user } {};//порядок не влияет на заполение
	Point(float user) : Point{ user, user, user } {};
	Point(float ux, float uy, float uz): x{ ux }, y{ uy }, z{ uz } {};
	~Point();//сообщает о своей работе

	void init();
	void show();

	float getX();
	float getY();
	float getZ();

	void setX(float ux);
	void setY(float uy);
	void setZ(float uz);
};

