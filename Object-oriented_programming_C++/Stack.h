#pragma once
class Stack
{
	enum stage { down = 0, up = 10 };
	int arr[up];
	int size; //"указатель" на вершину
public:
	Stack();
	void Push(int x);
	int Pop();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int getSize();
	void print();
};