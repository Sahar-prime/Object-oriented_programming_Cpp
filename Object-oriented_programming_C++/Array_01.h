#pragma once
#include <iostream>
class Array_01
{
    int* arr;
    int size;
public:
    Array_01();
    Array_01(int size);
    Array_01(const Array_01& a); //Глубокое копирование
    Array_01(Array_01&& a)noexcept;

    Array_01& setElem(int ind, int val);

    int getElem(int ind) const;
    int getSize()const;

    ~Array_01();

    Array_01& randomize(int a, int b);
    void print() const;

    //заполнен или нет
    operator bool() const
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] != 0)
            {
                return true;
            }
        }
        return false;
    }
    //сумма всех элементов
    operator int() const
    {
        int sum = 0;
        for (int i = 0; i < size; ++i)
        {
            sum += arr[i];
        }
        return sum;
    }
    //средне арифметическое
    operator float() const
    {
        if (size == 0)
        {
            return 0; // Избегаем деления на ноль
        }
        float sum = 0;
        for (int i = 0; i < size; ++i)
        {
            sum += arr[i];
        }
        return sum / size;
    }
    //***преобразовать массив в строку
    operator char* () const
    {
        char* newstr = new char[size + 1];
        for (int i = 0; i < size; ++i)
        {
            newstr[i] = arr[i] + 48;
        }
        newstr[size] = '\0';
        return newstr;
    }

    //2 пара
    Array_01& reSize(int size); //Если больше - мусор
    Array_01& sortArr(); //Пузырковая

    int minElem() const;
    int maxElem() const;

    int operator[](int ind)const //get
    {
        return arr[ind];
    }
    int& operator[](int ind) //set
    {
        return arr[ind];
    }

    // Оператор + (склеить 2 массива)
    Array_01 operator+(const Array_01& other) const
    {
        Array_01 result(size + other.size);
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
    Array_01 operator*(int n) const
    {
        Array_01 result(size * n);
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
    Array_01& operator+=(int scalar)
    {
        for (int i = 0; i < size; ++i)
        {
            arr[i] += scalar;
        }
        return *this;
    }
    Array_01& operator-=(int scalar)
    {
        for (int i = 0; i < size; ++i)
        {
            arr[i] -= scalar;
        }
        return *this;
    }
    Array_01& operator*=(int scalar)
    {
        for (int i = 0; i < size; ++i)
        {
            arr[i] *= scalar;
        }
        return *this;
    }
    Array_01& operator/=(int scalar)
    {
        for (int i = 0; i < size; ++i)
        {
            arr[i] /= scalar;
        }
        return *this;
    }

    // Операторы ++ и -- (инкремент/декремент всех элементов)
    Array_01& operator++()
    {
        for (int i = 0; i < size; ++i)
        {
            ++arr[i];
        }
        return *this;
    }
    Array_01& operator--() {
        for (int i = 0; i < size; ++i)
        {
            --arr[i];
        }
        return *this;
    }

    // Операторы == и != (сравнение по наполнению)
    bool operator==(const Array_01& other) const
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
    bool operator!=(const Array_01& other) const
    {
        return !(*this == other);
    }

    // Операторы >, <, >=, <= (сравнение по сумме элементов)
    bool operator>(const Array_01& other) const
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
    bool operator<(const Array_01& other) const
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
    bool operator>=(const Array_01& other) const
    {
        return !(*this < other);
    }
    bool operator<=(const Array_01& other) const
    {
        return !(*this > other);
    }

    // Оператор = (присваивание)
    Array_01& operator=(const Array_01& other)
    {
        if (this != &other)
        {
            delete[]arr;
            arr = new int[other.size];
            for (int i = 0; i < other.size; i++)
            {
                arr[i] = other.arr[i];
            }
            size = other.size;
        }
        return *this;
    }
    Array_01& operator=(Array_01&& other) noexcept
    {
        if (this != &other)
        {
            delete[] arr;  // Освобождаем текущие ресурсы
            arr = other.arr;
            size = other.size;
            other.arr = nullptr;  // Обнуляем указатель в исходном объекте
            other.size = 0;
        }
        return *this;
        //переделать operator= так, чтобы он работал как Array_01(Array_01&& a)
        /*Array_01::Array_01(Array_01&& a) : size{ a.size }, arr{ a.arr }
        {
            a.arr = nullptr;
            a.size = 0;
            std::cout << "Отработал конструктор перемещения: " << this << std::endl;
        }*/
    }

    // Операторы >> и << (ввод/вывод)
    friend std::ostream& operator<<(std::ostream& os, const Array_01& a)
    {
        for (int i = 0; i < a.size; ++i)
        {
            os << a.arr[i] << " ";
        }
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Array_01& a)
    {
        for (int i = 0; i < a.size; ++i)
        {
            is >> a.arr[i];
        }
        return is;
    }
};
