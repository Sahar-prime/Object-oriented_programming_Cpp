#include "Array.h"
#include <iostream>

Array::Array() : size{5}
{
	arr = new int[size];
	for (int i = 0; i < size; ++i) 
	{
		arr[i] = 0;
	}
	std::cout << "Отработал конструктор: " << this << std::endl;
}

Array::Array(int size) : arr{ new int[size] }, size{ size }
{
	for (int i = 0; i < size; ++i) 
	{
		arr[i] = 0;
	}
	std::cout << "Отработал конструктор: " << this << std::endl;
}

Array::Array(const Array& a) : size{ a.size }, arr{ new int[a.size] }
{
	for (int i = 0; i < size; ++i)
	{
		arr[i] = a.arr[i];
	}
	std::cout << "Отработал конструктор копий: " << this << std::endl;
}

Array& Array::setElem(int ind, int val)
{
	if (ind >= 0 && ind < size) 
	{
		arr[ind] = val;
	}
	return *this;
}

void Array::getElem(int ind)
{
	if (ind >= 0 && ind < size)
	{
		std::cout << "Элемент [" << ind << "]: " << arr[ind] << std::endl;
	}
}

Array& Array::randomize(int a, int b)
{
	for (int i = 0; i < size; ++i) 
	{
		arr[i] = rand() % (b - a + 1) + a;
	}
	return *this;
}

void Array::print() 
{
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

Array::~Array()
{
	delete[] this->arr;
	std::cout << "Отработал деструктор: " << this << "\n";
}

Array& Array::reSize(int newSize) 
{
	int* newArr = new int[newSize];
	int elementsToCopy = (newSize < size) ? newSize : size;
	for (int i = 0; i < elementsToCopy; ++i) 
	{
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	size = newSize;
	return *this;
}

Array& Array::sortArr() 
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1]) 
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return *this;
}

int Array::minElem() 
{
	int minVal = arr[0];
	for (int i = 1; i < size; ++i) 
	{
		if (arr[i] < minVal)
		{
			minVal = arr[i];
		}
	}
	return minVal;
}

int Array::maxElem() 
{
	int maxVal = arr[0];
	for (int i = 1; i < size; ++i) 
	{
		if (arr[i] > maxVal)
		{
			maxVal = arr[i];
		}
	}
	return maxVal;
}