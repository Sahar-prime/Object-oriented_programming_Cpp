#pragma once
class Point_2
{
	float x, y;
public:
	Point_2();
	Point_2(float x, float y);
	void init();
	void show()const;
	static bool isEqual(const Point_2& p1, const Point_2& p2);
	static Point_2 add(const Point_2& p1, const Point_2& p2);
	static Point_2 mult(const Point_2& p1, float value);
	static float distance(const Point_2& p1, const Point_2& p2);// расстояние
	float lenght()const; //длина вектора
};

