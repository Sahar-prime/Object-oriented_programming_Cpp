#include<iostream>
#include"Student.h"

//#define MAIN

#ifdef MAIN
int main() 
{
	setlocale(LC_ALL, "");

	Student s; //Объект
	s.init();
	s.show();
	std::cout << "Средняя оценка: " << s.aver() << std::endl;
	std::string s2;
	std::cout << s2.size() << std::endl;

	char n[5] = "Dane";
	int m[3] = { 3,4,5 };
	Student d;
	d.show();
	Student d2{n};
	d2.show();
	Student d3{m, 3};
	d3.show();
	Student d4{n, m, 3};
	d4.show();
	d4.setName("John");
	d4.show(); 

	int marks[] = { 5, 4, 3 };
	Student student1("Иванов Иван", marks, 3);
	Student student2;
	student2 = std::move(student1);
	std::cout << "Состояние student2 после перемещающего присваивания:" << std::endl;
	student2.show();
}
#endif //MAIN