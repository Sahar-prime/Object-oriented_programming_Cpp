#pragma once
class Queue 
{
	int* arr;
	int current_size;
	int max_size;
public:
	Queue(int max_size);
	~Queue();
	void Push(int x);
	int Pop();
	void PopRing();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int getSize();
	void print();
};