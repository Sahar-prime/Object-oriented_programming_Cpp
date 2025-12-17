#include <iostream>
#include "DynArray_2d.h"

DynArray_2d::DynArray_2d(int row, int col)
    : rows(row), 
    columns(col)
{
    arr = new int[rows * columns];
}

DynArray_2d::~DynArray_2d()
{
    delete[] arr;
}

int DynArray_2d::index2D(int i, int j) const
{
    return i * columns + j;
}

void DynArray_2d::init()
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            std::cin >> arr[index2D(i, j)];
        }
    }
}

void DynArray_2d::print() const
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            std::cout << arr[index2D(i, j)];
        }
        std::cout << std::endl;
    }
}

int& DynArray_2d::operator()(int i, int j)
{
    return arr[index2D(i, j)];
}

int DynArray_2d::operator()(int i, int j) const
{
    return arr[index2D(i, j)];
}

void DynArray_2d::deleteCol(int pos) 
{
    columns--;
    int* temp = new int[rows * columns];
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < rows; j++) 
        {
            arr[index2D(i, j)] = arr[index2D(i, j + (j >= pos))];
        }
    }
    delete[]arr;
    arr = temp;
}
//addCol
//deleteRow
//addRow