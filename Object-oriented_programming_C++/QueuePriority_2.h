#pragma once
class QueuePriority_2 //с приоритетным исключением
{
	int* arr;
	int* pri;
	int current_size;
	int max_size;
public:
	QueuePriority_2(int max_size);
	~QueuePriority_2();
	void Push(int x, int p);
	int Pop();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int getSize();
	void Print();
};