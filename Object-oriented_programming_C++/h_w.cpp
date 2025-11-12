#include <iostream>
#include"Task.h"

//#define H_W

#ifdef H_W
int main()
{
	setlocale(LC_ALL, "");

    Task task1;
    task1.print();

    Task task2("Сделать уборку", "Убрать комнату и вынести мусор", false);
    task2.print();

    Task task3 = task2;
    task3.print();

    task3.setTitle("Сходить в магазин");
    task3.print();

    task3.setTitle("Купить продукты").setDescription("Молоко, хлеб, яйца").setStatus(true);
    task3.print();
}
#endif //H_W