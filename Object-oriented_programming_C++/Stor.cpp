#include "Stor.h"
#include <iostream>

int Stor::usedMemory{ 0 };//задали static-переменную

Stor::Stor(int usize) : storage{ new int[usize] }, size{ usize }
{
	usedMemory += size * 4;
	for (int i = 0; i < size; i++)
	{
		storage[i] = rand() % 10;
	}
	std::cout << "Добавленно хранилище на " << size << " элементов\n";
	std::cout << "Всего занято: " << usedMemory << std::endl;
}
Stor::~Stor()
{
	delete[]storage;
	usedMemory -= size * 4;
	std::cout << "Освобождено хранилище на " << size << " элементов\n";
	std::cout << "Всего занято: " << usedMemory << std::endl;
}

void Stor::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << storage[i] << " ";
	}
	std::cout << std::endl;
}
int Stor::getUsedMemory()
{
	return usedMemory;
}