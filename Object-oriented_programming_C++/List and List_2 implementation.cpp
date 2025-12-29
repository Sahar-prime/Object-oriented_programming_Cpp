#include <iostream>
#include "List.h"
#include "List_2.h"

//#define MAIN

#ifdef MAIN
int main() 
{
	setlocale(LC_ALL, "");

	//List
	List l;
	for (int i = 0; i < 5; i++) 
	{
		l.AddTail(rand()%10);
	}
	l.Print();
	std::cout << l.getSize() << std::endl;
	for (int i = 0; i < 5; i++)
	{
		l.DelHead();
	}
	l.Print();
	for (int i = 0; i < 5; i++)
	{
		l.AddTail(rand() % 10);
	}
	l.Print();
	std::cout << std::endl;

	//List_2
	List_2 list;
	list.AddHead_2(10);
	list.AddTail_2(20);
	list.AddHead_2(5);
	std::cout << "Размер: " << list.getSize_2() << std::endl;
	std::cout << "Список: ";
	list.Print_Head();
	list.DelHead_2();
	list.DelTail_2();
	std::cout << "После удаления: ";
	list.Print_Head();

}
#endif //MAIN