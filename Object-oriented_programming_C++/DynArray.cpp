#include "DynArray.h"
#include <iostream>

//DynArray::DynArray(int row, int col) : 
//    rows(row), columns(col)
//{
//    arr = new int* [rows];
//    for (int i = 0; i < rows; ++i)
//    {
//        arr[i] = new int[columns];
//    }
//}
//DynArray::~DynArray() 
//{
//    for (int i = 0; i < rows; ++i)
//    {
//        delete[] arr[i];
//    }
//    delete[] arr;
//}
DynArray::DynArray(int row, int col) : 
    rows(row), columns(col)
{
   //arr0[*] -> 3 5 6 7 2
   //arr1[*] -> 4 9 5 3 6
   //arr2[*] -> 3 5 2 4 5
   arr = new int* [row]; //3*5
   int* temp_arr = new int[row * col];
   for (int i = 0; i < row; i++) 
   {
       arr[i] = temp_arr + i * col;
   }
   //arr0[*]   arr1[*]   arr2[*]
   //|         |         |
   //3 5 6 7 2 4 9 5 3 6 3 5 2 4 5
}
DynArray::~DynArray()
{
    delete[]arr[0];
    delete[] arr;
}

void DynArray::randomize()
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < columns; ++j)
        {
            arr[i][j] = rand() % 100;
        }
    }
}
void DynArray::print()const 
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int DynArray::operator()(int row, int col) const
{
    return arr[row][col];
}
int& DynArray::operator()(int row, int col)
{
    return arr[row][col];
}