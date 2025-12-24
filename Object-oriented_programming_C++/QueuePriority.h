#pragma once
class QueuePriority //С приоритетным включением
{
	int* arr;
	int* pri;
	int current_size;
	int max_size;
public:
	QueuePriority(int max_size);
	~QueuePriority();
	void Push(int x, int p);
	int Pop();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int getSize();
	void print();
};

// 4 8 3 1 8 9 3
// 30 21 50 47