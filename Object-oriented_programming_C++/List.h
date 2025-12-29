#pragma once
class List //Queue + Stack
{
	struct Node
	{
		int value;
		Node* next;
	};
	Node* head, * tail;
public:
	List();
	~List();
	void AddTail(int x);
	void DelHead();
	void DelTail();
	void Print();
	int getSize();
};