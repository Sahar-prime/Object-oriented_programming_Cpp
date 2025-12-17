#pragma once
#include <iostream>
class DynArray 
{
	int** arr;
	int rows, columns;
public:
	DynArray(int row, int col);
	~DynArray();
	void randomize();
	void print()const;

	//перегрузить двумя способами (как [])
	int operator()(int row, int col) const;
	int& operator()(int row, int col);
};