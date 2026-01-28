#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//#define MAIN

class Point 
{
	int x, y;
public:
	Point() : x(0), y(0) {}
	void set_point(int x, int y) 
	{
		this->x = x;
		this->y = y;
	}
	void show() const 
	{
		std::cout << "(" << x << ", " << y << ")";
	}
};
class Figura 
{
	Point* points;
	int count;
public:
	Figura() : points{ new Point[3] }, count{ 3 } {}
	~Figura() 
	{
		delete[] points;
	}
	void set_figura(int new_count) 
	{
		delete[] points;
		count = new_count;
		points = new Point[count];
		for (int i = 0; i < count; i++) {
			int tx, ty;
			std::cout << "Введите x и y для точки " << i + 1 << ": ";
			std::cin >> tx >> ty;
			points[i].set_point(tx, ty);
		}
	}
	void show() const 
	{
		std::cout << "Фигура из " << count << " точек: ";
		for (int i = 0; i < count; i++)
		{
			points[i].show();
			if (i < count - 1) std::cout << " - ";
		}
		std::cout << std::endl;
	}
};
class Picture 
{
	Figura* f;
	int count;
public:
	Picture(): f{ new Figura[2] }, count{ 2 } {}
	~Picture()
	{
		delete[] f;
	}
	void set_picture(int new_count)
	{
		delete[] f;
		count = new_count;
		f = new Figura[count];
		for (int i = 0; i < count; i++)
		{
			int points_count;
			std::cout << "Настройка фигуры №" << i + 1 << ":" << std::endl;
			std::cout << "Введите количество точек для этой фигуры: ";
			std::cin >> points_count;
			f[i].set_figura(points_count);
		}
	}
	void show() const
	{
		std::cout << "\nКартина содержит " << count << " фигур(ы):" << std::endl;
		for (int i = 0; i < count; i++)
		{
			std::cout << i + 1 << ". ";
			f[i].show();
		}
	}
};

class A 
{
public:
	virtual void show() const 
	{
		std::cout << "class A\n";
	}
};
class B : public A
{
public:
	virtual void show() const
	{
		std::cout << "class B\n";
	}
};
class C: public B
{
public:
	virtual void show() const
	{
		std::cout << "class C\n";
	}
};

class Weapon 
{
protected:
	char name[20];
public:
	Weapon(const char* name)
	{
		strcpy(this->name, name);
	}
	virtual void damage() const = 0;
};
class Gun : public Weapon
{
public:
	Gun(const char* name) : Weapon{ name } {}
	void damage() const
	{
		std::cout << "Огнестрельный\n";
	}
};
class Knife : public Weapon
{
public:
	Knife(const char* name) : Weapon{ name } {}
	void damage() const
	{
		std::cout << "Колюще-режущий\n";
	}
};
class Grenade : public Weapon
{
public:
	Grenade(const char* name) : Weapon{ name } {}
	void damage() const
	{
		std::cout << "Взрывной\n";
	}
};

#ifdef MAIN
int main() 
{
	setlocale(LC_ALL, "");
//ABC
	A objA, * ptrA;
	B objB, * ptrB;
	C objC, * ptrC;
	ptrA = &objA;
	ptrA->show();
	ptrA = &objB;
	ptrA->show(); 
	ptrA = &objC;
	ptrA->show();
	std::cout << std::endl;
	/*ptrB = &objA;
	ptrB = &objB;
	ptrB = &objC;
	ptrC = &objA;
	ptrC = &objB;
	ptrC = &objC;*/
	A* arr[3] = {new A, new B, new C};
	for (int i = 0; i < 3; i++) 
	{
		arr[i]->show();
	}

//Weapon
	Weapon* w[3] = 
	{ 
		new Gun("АК-47"),
		new Knife("Кухонный"),
		new Grenade("Молотова")
	};
	int user;
	std::cout << "Выбери оружие:\n1 - пистолет\n2 - нож\n3 - граната\n";
	std::cout << "Ваш выбор: ";
	std::cin >> user;
	if (user >= 4 or user <= 0)
	{
		std::cout << "Такого оружия нет!";
	}
	else
	{
		w[user - 1]->damage();
	}
}
#endif //MAIN