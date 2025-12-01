#pragma once
#include <iostream>
class Array
{
	int* arr;
	int size;
public:
	Array();
	Array(int size);
	Array(const Array& a); //Глубокое копирование
	Array& setElem(int ind, int val);
	int getElem(int ind) const;
	Array& randomize(int a, int b);
	~Array();
	void print();
	//2 пара
	Array& reSize(int size); //Если больше - мусор
	Array& sortArr(); //Пузырковая
	int minElem() const;
	int maxElem() const;
	int getSize()const;

    // Оператор + (склеить 2 массива)
    Array operator+(const Array& other) const 
    {
        Array result(size + other.size);
        for (int i = 0; i < size; ++i)
        {
            result.setElem(i, arr[i]);
        }
        for (int i = 0; i < other.size; ++i)
        {
            result.setElem(size + i, other.arr[i]);
        }
        return result;
    }

    // Оператор * (продублировать массив n раз)
    Array operator*(int n) const
    {
        Array result(size * n);
        for (int k = 0; k < n; ++k) 
        {
            for (int i = 0; i < size; ++i) 
            {
                result.setElem(k * size + i, arr[i]);
            }
        }
        return result;
    }

    // Операторы +=, -=, *=, /= (поэлементные операции) например 5,4,5 ->6,5,6
    Array& operator+=(int scalar) 
    {
        for (int i = 0; i < size; ++i)
        {
            arr[i] += scalar;
        }
        return *this;
    }
    Array& operator-=(int scalar)
    {
        for (int i = 0; i < size; ++i)
        {
            arr[i] -= scalar;
        }
        return *this;
    }
    Array& operator*=(int scalar) 
    {
        for (int i = 0; i < size; ++i)
        {
            arr[i] *= scalar;
        }
        return *this;
    }
    Array& operator/=(int scalar) 
    {
        for (int i = 0; i < size; ++i)
        {
            arr[i] /= scalar;
        }
        return *this;
    }

    // Операторы ++ и -- (инкремент/декремент всех элементов)
    Array& operator++()
    {
        for (int i = 0; i < size; ++i)
        {
            ++arr[i];
        }
        return *this;
    }
    Array& operator--() {
        for (int i = 0; i < size; ++i)
        {
            --arr[i];
        }
        return *this;
    }

    // Операторы == и != (сравнение по наполнению)
    bool operator==(const Array& other) const 
    {
        if (size != other.size)
        {
            return false;
        }
        for (int i = 0; i < size; ++i)
        {
            if (arr[i] != other.arr[i])
            {
                return false;
            }
        }
        return true;
    }
    bool operator!=(const Array& other) const 
    {
        return !(*this == other);
    }

    // Операторы >, <, >=, <= (сравнение по сумме элементов)
    bool operator>(const Array& other) const 
    {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < size; ++i)
        {
            sum1 += arr[i];
        }
        for (int i = 0; i < other.size; ++i) 
        {
            sum2 += other.arr[i];
        }
        return sum1 > sum2;
    }
    bool operator<(const Array& other) const 
    {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < size; ++i)
        {
            sum1 += arr[i];
        }
        for (int i = 0; i < other.size; ++i) 
        {
            sum2 += other.arr[i];
        }
        return sum1 < sum2;
    }
    bool operator>=(const Array& other) const 
    {
        return !(*this < other);
    }
    bool operator<=(const Array& other) const
    {
        return !(*this > other);
    }

    // Оператор = (присваивание)
    Array& operator=(const Array& other) 
    {
        if (this != &other)
        {
            delete[] arr;
            size = other.size;
            arr = new int[size];
            for (int i = 0; i < size; ++i) 
            {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    // Операторы >> и << (ввод/вывод)
    friend std::ostream& operator<<(std::ostream& os, const Array& a) 
    {
        for (int i = 0; i < a.size; ++i)
        {
            os << a.arr[i] << " ";
        }
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Array& a)
    {
        for (int i = 0; i < a.size; ++i)
        {
            is >> a.arr[i];
        }
        return is;
    }

	//***
	//+= *= (дописывает)
};

