#include "List_2.h"
#include <iostream>

List_2::List_2()
{
	head = tail = nullptr;
}
List_2::~List_2()
{
	while (head != nullptr)
	{
		DelHead_2();
	}
}
void List_2::AddTail_2(int x)
{
	Node_2* elem = new Node_2;
	elem->value = x;
	elem->next = nullptr;
	elem->prev = tail;
	if (head != nullptr)
	{
		tail->next = elem;
	}
	else
	{
		head = elem;
	}
	tail = elem;
}
void List_2::AddHead_2(int x)
{
	Node_2* elem = new Node_2;
	elem->value = x;
	elem->prev = nullptr;
	elem->next = head;
	if (head != nullptr)
	{
		head->prev = elem;
	}
	else
	{
		tail = elem;
	}
	head = elem;
}
void List_2::DelHead_2()
{
	if (head == nullptr) return;

	Node_2* temp = head;
	head = head->next;
	if (head != nullptr)
	{
		head->prev = nullptr;
	}
	else
	{
		tail = head;
	}
	delete temp;
}
void List_2::DelTail_2()
{
	if (tail == nullptr) return;

	Node_2* temp = tail;
	tail = tail->prev;

	if (tail != nullptr)
	{
		tail->next = nullptr;
	}
	else
	{
		head = tail;
	}
	delete temp;
}
void List_2::Print_Head()
{
	Node_2* temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->value << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}
void List_2::Print_Tail()
{
	Node_2* temp = tail;
	while (temp != nullptr)
	{
		std::cout << temp->value << " ";
		temp = temp->prev;
	}
	std::cout << std::endl;
}
int List_2::getSize_2()
{
	int count = 0;
	Node_2* temp = head;
	while (temp != nullptr)
	{
		count++;
		temp = temp->next;
	}
	return count;
}