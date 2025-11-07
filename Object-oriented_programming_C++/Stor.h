#pragma once
class Stor
{
	int* storage;
	int size;
	static int usedMemory;
public:
	Stor(int usize);
	~Stor();

	void print();
	static int getUsedMemory();
};

//Использованная память - 0Б
//Storage(5) -> 4 7 2 4 8 - 20 б
//Storage(3) -> 9 2 3 - 32 б