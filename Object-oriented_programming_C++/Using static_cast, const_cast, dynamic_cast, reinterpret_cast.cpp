#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//#define MAIN

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
}
#endif //MAIN