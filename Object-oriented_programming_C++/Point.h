#pragma once
class Point
{
	float x, y, z;
public:
	Point(); // 0 0 0
	Point(float user);//user user user
	Point(float ux, float uy, float uz);//ux uy uz
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

