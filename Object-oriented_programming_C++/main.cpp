#include <iostream>

//#define MAIN

class Point 
{
	int x, y;
public:
	Point(int x, int y) : x{ x }, y{ y } {};
	void print() 
	{
		std::cout << "(" << x << ";" << y << ")";
	}
	operator bool() const 
	{
		return x != 0 or y != 0;
	}
	operator int() const 
	{
		return x * y;
	}
	operator float() const 
	{
		return sqrt(pow(x, 2) + pow(y, 2));
	}
};

#ifdef MAIN
int main() 
{
	setlocale(LC_ALL, "");

	//Point
	Point p{ 4,7 };
	p.print();
	if (bool(p)) 
	{
		std::cout << "Точка не 0;0\n";
	}
	else 
	{
		std::cout << "Точка 0;0\n";
	}
	std::cout << int(p) << std::endl;
	std::cout << float(p) << std::endl;
}
#endif //MAIN