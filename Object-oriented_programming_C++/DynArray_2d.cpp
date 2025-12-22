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
    if (pos < 0 || pos >= columns) return;
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
void DynArray_2d::addColum(int pos)
{
    if (pos < 0 || pos > columns) return;
    columns++;
    int* temp = new int[rows * columns];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (j < pos)
                temp[index2D(i, j)] = arr[index2D(i, j)];
            else if (j > pos)
                temp[index2D(i, j)] = arr[index2D(i, j - 1)];
            else
                temp[index2D(i, j)] = 0;
        }
    }
    delete[] arr;
    arr = temp;
}
void DynArray_2d::deleteRow(int pos)
{
    if (pos < 0 || pos >= rows) return;
    rows--;
    int* temp = new int[rows * columns];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            temp[index2D(i, j)] = arr[index2D(i + (i >= pos), j)];
        }
    }
    delete[] arr;
    arr = temp;
}
void DynArray_2d::addRow(int pos)
{
    if (pos < 0 || pos > rows) return;
    rows++;
    int* temp = new int[rows * columns];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i < pos)
                temp[index2D(i, j)] = arr[index2D(i, j)];
            else if (i > pos)
                temp[index2D(i, j)] = arr[index2D(i - 1, j)];
            else
                temp[index2D(i, j)] = 0;
        }
    }
    delete[] arr;
    arr = temp;
}