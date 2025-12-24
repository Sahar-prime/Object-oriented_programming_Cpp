#include <iostream>
#include "Stack.h"
#include "Queue.h"

//#define MAIN

#ifdef MAIN
int main() 
{
	setlocale(LC_ALL, "");
	
	//Stack
    Stack stack;
    // Проверяем, пуст ли стек
    std::cout << "Стек пуст? " << (stack.IsEmpty() ? "Да" : "Нет") << std::endl;
    // Добавляем элементы в стек
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    // Выводим текущий размер стека
    std::cout << "Текущий размер стека: " << stack.getSize() << std::endl;
    // Выводим элементы стека
    std::cout << "Элементы стека: ";
    stack.print();
    // Удаляем элемент из стека
    std::cout << "Извлечённый элемент: " << stack.Pop() << std::endl;
    // Выводим элементы стека после удаления
    std::cout << "Элементы стека после извлечения: ";
    stack.print();
    // Проверяем, заполнен ли стек
    std::cout << "Стек заполнен? " << (stack.IsFull() ? "Да" : "Нет") << std::endl;
    // Очищаем стек
    stack.Clear();
    // Проверяем, пуст ли стек после очистки
    std::cout << "Стек пуст после очистки? " << (stack.IsEmpty() ? "Да" : "Нет") << std::endl;

	//Queue
    Queue q(5); // Очередь на 5 элементов
    q.Push(10);
    q.Push(20);
    q.Push(30);
    std::cout << "Очередь: ";
    q.print(); // Вывод: 10 20 30
    std::cout << "Удален элемент: " << q.Pop() << std::endl; // Удален элемент: 10
    std::cout << "Очередь после удаления: ";
    q.print(); // Вывод: 20 30
    q.Clear();
    std::cout << "Очередь после очистки: ";
    q.print(); // Вывод: (пусто)
}
#endif //MAIN