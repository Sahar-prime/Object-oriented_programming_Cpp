#include "Stack.h"
#include <iostream>

Stack::Stack()
{
	size = down;
}

void Stack::Push(int x) 
{
	if (!IsFull()) 
	{
		arr[size++] = x;
	}
}

//69742_____
//0123456789

int Stack::Pop() 
{
	if (!IsEmpty())
	{
		return arr[--size];
	}
	return 0;
}

void Stack::Clear() 
{
	size = 0; //"быстрая очистка"
}

bool Stack::IsEmpty() 
{
	return size == down;
}

bool Stack::IsFull() 
{
	return size == up;
}

int Stack::getSize() 
{
	return size;
}

void Stack::print()
{
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}