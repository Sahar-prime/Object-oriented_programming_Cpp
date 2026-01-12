#pragma once
class List_2
{
	struct Node_2
	{
		int value;
		Node_2* next;
		Node_2* prev;
	};
	Node_2* head, * tail;
public:
	List_2();
	~List_2();
	void AddTail_2(int x);
	void AddHead_2(int x);
	void AddIndex(int index, int x);
	void DelHead_2();
	void DelTail_2();
	void DelIndex(int index);
	void Print_Head();
	void Print_Tail();
	int getSize_2();
};