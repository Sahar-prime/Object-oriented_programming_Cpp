#pragma once

class DynArray_2d
{
    int* arr;
    int rows, columns;
    int index2D(int i, int j) const; 

public:
    DynArray_2d(int row, int col);   
    ~DynArray_2d();

    void deleteCol(int pos);

    void init(); 
    void print() const;          

    int& operator()(int i, int j); 
    int operator()(int i, int j) const;
};

//35643
//94528
//31904

//356439452831904