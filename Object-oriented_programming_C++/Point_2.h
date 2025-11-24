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
	float getX() const;
	float getY() const;
	
	////2
	//friend Point_2 operator+(const Point_2& p1, const Point_2& p2);

	//3 - метод класса (первый параметр - неявный this)

	//friend Point_2 operator-(const Point_2& p);

	//friend Point_2 operator*(const Point_2& p1, float value);

	Point_2 operator+(const Point_2& p)
	{
		return Point_2(this->x + p.x, this->y + p.y);
	}

	Point_2 operator-() 
	{
		return Point_2{ -this-> x, -this->y };
	}

	Point_2 operator*(float value)
	{
		return Point_2(x * value, y * value);
	}

	Point_2& operator++() 
	{
		++x;
		++y;
		return *this;
	}
	Point_2& operator--()
	{
		--x;
		--y;
		return *this;
	}

	const Point_2 operator++(int)
	{
		Point_2 temp{ x,y };
		++x;
		++y;
		return temp;
	}
	const Point_2 operator--(int)
	{
		Point_2 temp{ x,y };
		--x;
		--y;
		return temp;
	}
};



//Point_2 operator*(const Point_2& p1, float value)
//{
//	return Point_2(p1.getX() * value, p1.getY() * value);
//}
//Point_2 operator*(const Point_2& p1, float value)
//{
//	return Point_2(p1.x * value, p1.x * value);
//}

//Point_2 operator-(const Point_2& p)
//{
//	return Point_2{ -p.getX(), -p.getY() };
//}
//Point_2 operator-(const Point_2& p)
//{
//	return Point_2{ -p.x, -p.y };
//}

////1 - через обычные фунции
//Point_2 operator+(const Point_2& p1, const Point_2& p2)
//{
//	return Point_2(p1.getX() + p2.getX(), p1.getY() + p2.getY());
//}

////2 - дружественные классы
//Point_2 operator+(const Point_2& p1, const Point_2& p2)
//{
//	return Point_2(p1.x + p2.x, p1.y + p2.y);
//}

