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

void func(const int* p) //int *p = x; 
{
	int* temp;
	temp = const_cast<int*>(p);
	*temp *= 2;
}

class A 
{
public:
	virtual void test() 
	{
		std::cout << "class A\n";
	}
};
class B : public A 
{
	virtual void test()
	{
		std::cout << "class B\n";
	}
};

#ifdef MAIN
int main() 
{
	setlocale(0, "");

	exploration::fire();
	weapon::fire();
	cout << a << endl;

	int a = 5, b = 2;
	std::cout << float(a) / float(b) << std::endl;
	float c = 10.3;
	int d = c;

	//static_cast
	int A1 = 5, B1 = 2;
	std::cout << static_cast<float>(A1) / B1 << std::endl;
	//const_cast
	int x = 10;
	func(&x);
	std::cout << x << std::endl;
	//dynamic_cast
	A* ptrA, objA;
	B* ptrB, objB;
	ptrA = dynamic_cast<A*>(&objA);
	if (ptrA) 
	{
		std::cout << "OK\n";
		ptrA->test();
	}
	else
	{
		std::cout << "Error!\n";
	}
	ptrA = dynamic_cast<B*>(&objB);
	if (ptrA)
	{
		std::cout << "OK\n";
		ptrA->test();
	}
	else
	{
		std::cout << "Error!\n";
	}
	ptrB = dynamic_cast<B*>(&objA);
	if (ptrB)
	{
		std::cout << "OK\n";
		ptrA->test();
	}
	else
	{
		std::cout << "Error!\n";
	}
	ptrB = dynamic_cast<B*>(&objB);
	if (ptrB)
	{
		std::cout << "OK\n";
		ptrA->test();
	}
	else
	{
		std::cout << "Error!\n";
	}
	//reinterpret_cast
	/*char string[20] = "Hello world!";
	int x = reinterpret_cast<int>(string);
	std::cout << std::endl;*/
}
#endif //MAIN
