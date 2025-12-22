#include <iostream>

//#define MAIN

template <class P, class H>
class Point 
{
	P x;
	H y;
public:
	Point(P x, H y) : x{ x }, y{ y } {};
	void print() 
	{
		std::cout << "(" << x << "; " << y << ")" << std::endl;
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

template <typename T>
T summar(T* arr, int size)
{
	T s = 0;
	for (int i = 0; i < size; i++)
	{
		s += arr[i];
	}
	return s;
}

#ifdef MAIN
int main() 
{
	setlocale(LC_ALL, "");

	//Summar
	const int size = 5;
	int arr[size] = { 4,7,2,7,3 };
	float arr2[size] = { 5.7,3.2,9.1,8.4,6.3 };
	std::cout << summar(arr, size) << std::endl;
	std::cout << summar(arr2, size) << std::endl;
 
	//Point
	Point<int, int> p{ 5,4 };
	Point<double, double> p2{ 5.7, 4.1 };
	Point<int, double> p3{ 5, 4.7 };
	Point<double, int> p4{ 5.7, 4 };
	p.print();
	p2.print();
	p3.print();
	p4.print();
	std::cout << std::endl;
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