#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//#define MAIN

using std::cout;
using std::cin;
using std::endl;

namespace exploration
{
	void fire()
	{
		cout << "Пламя" << endl;
	}
}
namespace weapon
{
	int a;
	void fire()
	{
		cout << "Выстрел" << endl;
	}
}
//директива using
//using namespace std;
//using namespace exploration;
//using namespace weapon;

//объявление using
using weapon::a;

#ifdef MAIN
int main()
{
	setlocale(0, "");

	exploration::fire();
	weapon::fire();
	cout << a << endl;
	std::cout << std::endl;

	int a = 5, b = 2;
	std::cout << float(a) / float(b) << std::endl;
	float c = 10.3;
	int d = c;
	std::cout << std::endl;
}
#endif //MAIN