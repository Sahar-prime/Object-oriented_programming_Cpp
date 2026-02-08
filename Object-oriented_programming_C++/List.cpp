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
void List::DelTail_1() 
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
void List::DelTail() //функция для удаления как из стека (с конца списка)
{
	// 1. Если список пуст — делать нечего
	if (head == nullptr) return;
	// 2. Если в списке всего один элемент
	if (head == tail)
	{
		delete head;
		head = tail = nullptr;
		return;
	}
	// 3. Если элементов > 1, ищем предпоследний (тот, что указывает на tail)
	Node* temp = head;
	while (temp->next != tail)
	{
		temp = temp->next;
	}
	// 4. Удаляем последний, переназначаем tail на текущий (предпоследний)
	delete tail;
	tail = temp;
	tail->next = nullptr; // Теперь это новый конец
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