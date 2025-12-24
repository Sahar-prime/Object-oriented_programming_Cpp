#include <iostream>
#include "QueuePriority.h"

QueuePriority::QueuePriority(int max_size)
    : max_size(max_size),
    current_size(0)
{
    arr = new int[max_size];
    pri = new int[max_size];
}

QueuePriority::~QueuePriority()
{
    delete[]arr;
    delete[]pri;
}

void QueuePriority::Push(int x, int p)
{
    if (IsEmpty()) 
    {
        arr[0] = x;
        pri[0] = p;
    }
    if (!IsFull()) 
    {
        for(int i = 0; i < current_size; i++)
        {
            if (pri[i] < p)
            {
                for (int j = current_size; j > i; j--)
                {
                    pri[i] = pri[j - 1];
                    arr[i] = arr[j - 1];
                }
                pri[i] = p;
                arr[i] = x;
                current_size++;
                return;
            }
        }
        arr[current_size] = x;
        pri[current_size] = p;
        current_size++;
    }
}

int QueuePriority::Pop()
{
    if (!IsEmpty())
    {
        int val = arr[0];
        // Сдвигаем все элементы влево
        for (int i = 0; i < current_size - 1; i++)
        {
            arr[i] = arr[i + 1];
            pri[i] = pri[i + 1];
        }
        current_size--;
        return val;
    }
    return 0;
}

void QueuePriority::Clear()
{
    current_size = 0;
}

bool QueuePriority::IsEmpty()
{
    return current_size == 0;
}

bool QueuePriority::IsFull()
{
    return current_size == max_size;
}

int QueuePriority::getSize()
{
    return current_size;
}

void QueuePriority::print()
{
    for (int i = 0; i < current_size; i++)
    {
        std::cout << arr[i] << " - " << pri[i] << std::endl;;
    }
    std::cout << std::endl;
}
