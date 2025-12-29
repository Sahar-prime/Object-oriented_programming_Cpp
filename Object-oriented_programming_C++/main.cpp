#include <iostream>

//#define MAIN

class List //Queue
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
	void Print();
	int getSize();
};

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

#ifdef MAIN
int main() 
{
	List l;
	for (int i = 0; i < 5; i++) 
	{
		l.AddTail(rand()%10);
	}
	l.Print();
	std::cout << l.getSize() << std::endl;
	for (int i = 0; i < 5; i++)
	{
		l.DelHead();
	}
	l.Print();
	for (int i = 0; i < 5; i++)
	{
		l.AddTail(rand() % 10);
	}
	l.Print();
}
#endif //MAIN