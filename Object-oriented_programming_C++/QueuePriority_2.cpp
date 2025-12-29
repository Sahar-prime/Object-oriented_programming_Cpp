#include "QueuePriority_2.h"
#include <iostream>

QueuePriority_2::QueuePriority_2(int max_size)
{
    arr = new int[max_size];
    pri = new int[max_size];
    current_size = 0;
    this->max_size = max_size;
}

QueuePriority_2::~QueuePriority_2() 
{
    delete[] arr;
    delete[] pri;
}

void QueuePriority_2::Push(int x, int p) 
{
    if (IsFull()) 
    {
        std::cout << "Очередь полна!" << std::endl;
        return;
    }

    // Добавление элемента в конец очереди
    arr[current_size] = x;
    pri[current_size] = p;
    current_size++;
}

int QueuePriority_2::Pop() 
{
    if (IsEmpty()) 
    {
        std::cout << "Очередь пуста!" << std::endl;
        return -1; // Возвращаем -1 как признак ошибки
    }

    // Поиск элемента с максимальным приоритетом
    int max_pri_index = 0;
    for (int i = 1; i < current_size; i++)
    {
        if (pri[i] > pri[max_pri_index])
        {
            max_pri_index = i;
        }
    }

    // Сохраняем значение элемента с максимальным приоритетом
    int result = arr[max_pri_index];

    // Сдвигаем элементы после найденного элемента влево
    for (int i = max_pri_index; i < current_size - 1; i++)
    {
        arr[i] = arr[i + 1];
        pri[i] = pri[i + 1];
    }

    // Уменьшаем размер очереди
    current_size--;

    return result;
}

void QueuePriority_2::Clear()
{
    current_size = 0;
}

bool QueuePriority_2::IsEmpty()
{
    return current_size == 0;
}

bool QueuePriority_2::IsFull()
{
    return current_size == max_size;
}

int QueuePriority_2::getSize() 
{
    return current_size;
}

void QueuePriority_2::Print()
{
    for (int i = 0; i < current_size; i++) 
    {
        std::cout << arr[i] << " - " << pri[i] << std::endl;
    }
    std::cout << std::endl;
}
