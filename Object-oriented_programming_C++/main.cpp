#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>

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

void show(std::vector<int> &v) 
{
	std::cout << "Size: " << v.size() << " " << v.capacity() << " " << v.max_size() << std::endl;
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

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
	std::cout << std::endl;

	//STL - стандартная библиотека шаблонов
	//1 - контейнер:
	//std::string s; //STL или не STL?
	//std::vector<int> v;
	//2 - алгоритм
	//3 - итератор
	//4 - функторы
	//5 - аллокатор
	//6 - предикат

	std::string t; 
	std::cin >> t;
	std::cout << t << std::endl;
	t.append("Qwerty");
	std::cout << t << std::endl;
	t += "abc";
	std::cout << t << std::endl;
	std::cout << t[3] << std::endl;
	t[3] = 'a';
	std::cout << t.size() << t.length() << std::endl;
	std::cout << t.empty() << std::endl;
	std::cout << t.find("a") << std::endl;
	std::cout << t.rfind("a") << std::endl;
	std::cout << t.find_first_of("a") << std::endl;

	std::string t2 = "Hello world!";
	int te = reinterpret_cast<int>(t2.c_str());
	std::cout << std::endl;

	FILE* f = fopen("C:\\Users\\user\\Рабочий стол\\temp.txt", "w");
	fprintf(f, "%s", t2.c_str());

//vector list map multimap
	int size = 5;
	std::vector<int> v1; //пустой вектор
	std::vector<int> v2(5, 7);
	std::vector<int> v3(v2);
	std::vector<int> v4 = { 8, 3, 1, 3, 5, 7 };
	show(v2);
	show(v3);
	std::cout << std::endl;
	for (int i = 0; i < size; i++)
	{
		v1.push_back(5);
	}
	show(v1);
	for (int i = 0; i < size; i++)
	{
		v1.push_back(5);
	}
	show(v1);
	for (int i = 0; i < size; i++)
	{
		v1.push_back(5);
	}
	show(v1);
	std::cout << std::endl;
	//5 5 5 5 5 -> 5 6
	//5 5 5 5 5 5 5 5 5 5 -> 10 13
	//5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 -> 15 19
	
	//if (v1 == v2)
	//if (v1[8] == v2[3])
	std::cout << v1.at(7) << std::endl;
	v1.at(7) = 10;
	show(v1);
	std::cout << std::endl;

	std::vector<int> vect = { 4,2,5,6,5,4 };
	/*std::cout << vect[15] << std::endl;
	vect[15] = 10;*/
	try
	{
		std::cout << vect.at(5) << std::endl;
		vect.at(15) = 10;
		show(vect);
	}
	catch (...) 
	{
		std::cout << "out of range\n";
	}
	vect.pop_back();

	std::vector<int> vc = { 4,2,7,4,8 };
	vect.swap(vc);
	//vect.clear();
	//if(vect.empty())
}
#endif //MAIN
