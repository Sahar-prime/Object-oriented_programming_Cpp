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
}
#endif //H_W