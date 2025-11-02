#include <iostream>
#include"Task.h"

//#define H_W

#ifdef H_W
int main()
{
	setlocale(LC_ALL, "");

	Task task;
	task.input();
	task.print();

	task.setTitle("Новое название");
	task.setDescription("Новое описание задачи");
	task.setStatus(1);
	task.print();

	std::cout << "Название: " << task.getTitle() << std::endl;
	std::cout << "Описание: " << task.getDescription() << std::endl;
	std::cout << "Статус: " << (task.getStatus() ? "выполнена" : "не выполнена") << std::endl;
}
#endif //H_W