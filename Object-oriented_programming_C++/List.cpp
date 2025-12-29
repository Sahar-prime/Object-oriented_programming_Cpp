#include "List.h"
#include <iostream>

List::List()
{
	head = tail = nullptr;
}
List::~List()
{
	while (head != nullptr)
	{
		DelHead();
	}
}
void List::AddTail(int x)
{
	Node* elem = new Node;
	elem->value = x;
	elem->next = nullptr;
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
void List::DelHead()
{
	if (head == nullptr) return;

	Node* temp = head; //Запоминаем старую голову
	head = head->next; //Смещаем голову на следующий элемент

	if (head == nullptr) //Если список стал пустым
	{
		tail = nullptr; //обнуляем хвост
	}

	delete temp; //Очищаем память
}
void List::DelTail() 
{
	if (tail == nullptr) return;

	if (head == tail)
	{
		delete tail;
		head = tail = nullptr;
		return;
	}
	Node* temp = head;
	while (temp->next != tail)
	{ 
		temp = temp->next;
	}
	delete tail; 
	tail = temp; 
	tail->next = nullptr;
}
void List::Print()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->value << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}
int List::getSize()
{
	int count = 0;
	Node* temp = head;
	while (temp != nullptr)
	{
		count++;
		temp = temp->next;
	}
	return count;
}