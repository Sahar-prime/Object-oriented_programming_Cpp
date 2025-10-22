#include<iostream>
#include"Student.h"
#include"Task.h"

#define MAIN

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

	Task task;
	task.input();
	task.print();
}
#endif //MAIN