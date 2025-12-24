#include "Queue.h"
#include <iostream>

Queue::Queue(int max_size)
    : max_size(max_size), 
    current_size(0)
{
    arr = new int[max_size];
}

Queue::~Queue()
{
    delete[] arr;
}

void Queue::Push(int x) 
{
    if (!IsFull())
    {
        arr[current_size++] = x;
    }
}

int Queue::Pop()
{
    if (!IsEmpty())
    {
        int val = arr[0];
        // Сдвигаем все элементы влево
        for (int i = 0; i < current_size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        current_size--;
        return val;
    }
    return 0;
}

void Queue::PopRing()
{
    if (!IsEmpty())
    {
        int val = arr[0];
        //Удаление первого элемента очереди
        for (int i = 0; i < current_size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        //Добавление в конец очереди
        arr[current_size - 1] = val;
    }
}

void Queue::Clear()
{
    current_size = 0;
}

bool Queue::IsEmpty() 
{
    return current_size == 0;
}

bool Queue::IsFull() 
{
    return current_size == max_size;
}

int Queue::getSize() 
{
    return current_size;
}

void Queue::print()
{
    for (int i = 0; i < current_size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
