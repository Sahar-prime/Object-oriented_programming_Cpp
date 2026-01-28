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

class DomesticAnimal
{
protected:
	char name[20];
public:
	DomesticAnimal(const char* name)
	{
		strcpy(this->name, name);
	}
	virtual void Sound() const = 0;
	virtual void Name() const
	{
		std::cout << "Имя: " << name << std::endl;
	}
	virtual void Type() const = 0;
};
class Dog : public DomesticAnimal
{
public:
	Dog(const char* name) : DomesticAnimal(name) {}
	void Sound() const 
	{
		std::cout << name << " говорит: Гав-гав!" << std::endl;
	}
	void Type() const
	{
		std::cout << "Подвид: Собака" << std::endl;
	}
};
class Cat : public DomesticAnimal
{
public:
	Cat(const char* name) : DomesticAnimal(name) {}
	void Sound() const 
	{
		std::cout << name << " говорит: Мяу!" << std::endl;
	}
	void Type() const 
	{
		std::cout << "Подвид: Кошка" << std::endl;
	}
};

class OneStr 
{
protected:
	char* str;
public:
	OneStr(const char* str) :
		str{ new char[strlen(str) + 1] }
	{
		strcpy(this -> str, str);
		std::cout << "Отработал констуктор для OneStr\n";
	}
	virtual void Show() const 
	{
		std::cout << str << std::endl;
	}
	virtual ~OneStr()
	{
		delete[]str;
		std::cout << "Отработал деструктор для OneStr\n";
	}
};
class TwoStr: public OneStr
{
protected:
	char* str2;
public:
	TwoStr(const char* str, const char* str2) :
		str2{ new char[strlen(str2) + 1] },
		OneStr{str}
	{
		strcpy(this->str2, str2);
		std::cout << "Отработал констуктор для TwoStr\n";
	}
	virtual void Show() const
	{
		std::cout << str << " " << str2 << std::endl;
	}
	virtual ~TwoStr()
	{
		delete[]str2;
		std::cout << "Отработал деструктор для TwoStr\n";
	}
};

////1
//class Figure
//{
//public:
//	virtual double square() const = 0;
//};
//class Rectangle : public Figure 
//{
//	double a, b;
//public:
//	Rectangle(double a, double b) :
//		a(a), 
//		b(b) {}
//	double square() const
//	{
//		return a * b; 
//	}
//};
//class Circle : public Figure
//{
//	double r;
//public:
//	Circle(double r) : r(r) {}
//	double square() const
//	{
//		return 3.14 * r * r; 
//	}
//};
//class Right_triangle : public Figure
//{
//	double a, b;
//public:
//	Right_triangle(double a, double b) :
//		a(a),
//		b(b) {}
//	double square() const
//	{
//		return 0.5 * a * b; 
//	}
//};
//class Trapezoid : public Figure 
//{
//	double a, b, h;
//public:
//	Trapezoid(double a, double b, double h) :
//		a(a),
//		b(b),
//		h(h) {}
//	double square() const
//	{
//		return 0.5 * (a + b) * h;
//	}
//};

////2
//class Figure 
//{
//public:
//	virtual double square() const = 0;
//};
//class Rectangle : public Figure 
//{
//protected:
//	double a, b;
//public:
//	Rectangle(double s1, double s2) : a(s1), b(s2) {}
//	double square() const
//	{
//		return a * b;
//	}
//};
//class Right_triangle : public Rectangle 
//{
//public:
//	Right_triangle(double l1, double l2) : Rectangle(l1, l2) {}
//	double square() const
//	{
//		return 0.5 * Rectangle::square();
//	}
//};
//class Circle : public Figure
//{
//private:
//	double r;
//public:
//	Circle(double radius) : r(radius) {}
//	virtual double square() const
//	{
//		return 3.14 * r * r;
//	}
//};
//class Trapezoid : public Figure
//{
//private:
//	double a, b, h;
//public:
//	Trapezoid(double b1, double b2, double height) : a(b1), b(b2), h(height) {}
//	double square() const 
//	{
//		return 0.5 * (a + b) * h;
//	}
//};

////3
//class Figure 
//{
//public:
//	virtual double square() const = 0;
//};
//class Rectangle : public Figure 
//{
//protected:
//	double a, b;
//public:
//	Rectangle(double s1, double s2) : a(s1), b(s2) {}
//	double square() const 
//	{
//		return a * b;
//	}
//};
//class Right_triangle : public Rectangle
//{
//public:
//	Right_triangle(double l1, double l2) : Rectangle(l1, l2) {}
//	double square() const 
//	{
//		return 0.5 * Rectangle::square();
//	}
//};
//class Trapezoid : public Right_triangle 
//{
//private:
//	double h;
//public:
//	Trapezoid(double b1, double b2, double height) : Right_triangle(b1 + b2, height) {}
//	double square() const 
//	{
//		return Right_triangle::square();
//	}
//};
//class Circle : public Figure 
//{
//private:
//	double r;
//public:
//	Circle(double radius) : r(radius) {}
//	double square() const 
//	{
//		return 3.14159 * r * r;
//	}
//};

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
	std::cout << std::endl;
//DomesticAnimal
	DomesticAnimal* d[2] =
	{
		new Dog("Бобик"),
		new Cat("Мурка")
	};
	for (int i = 0; i < 2; ++i)
	{
		d[i]->Name();
		d[i]->Type();
		d[i]->Sound();
		std::cout << std::endl;
	}
	for (int i = 0; i < 1; ++i)
	{
		delete d[i];
	}
//Str
	OneStr* ptr = new TwoStr{ "test", "qwerty" };
	ptr->Show();
	delete ptr;
//Figure
}
#endif //MAIN