#pragma once
#include <iostream>
template <typename T>
class Array
{
	T* arr;
	int size;
public:
	Array();
	Array(int size);
	Array(const Array<T>& a); // Глубокое копирование
	Array(Array<T>&& a) noexcept;

	Array<T>& setElem(int ind, T val);

	T getElem(int ind) const;
	int getSize() const;

	~Array();

	Array<T>& randomize(T a, T b);
	void print() const;

	// Заполнен или нет
	operator bool() const
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] != T{})
			{
				return true;
			}
		}
		return false;
	}

	// Сумма всех элементов
	operator T() const
	{
		T sum = T{};
		for (int i = 0; i < size; ++i)
		{
			sum += arr[i];
		}
		return sum;
	}

	// Среднее арифметическое
	operator float() const
	{
		if (size == 0)
		{
			return 0; // Избегаем деления на ноль
		}
		float sum = 0;
		for (int i = 0; i < size; ++i)
		{
			sum += static_cast<float>(arr[i]);
		}
		return sum / size;
	}

	// Преобразовать массив в строку (только для числовых типов)
	operator char* () const
	{
		char* newstr = new char[size + 1];
		for (int i = 0; i < size; ++i)
		{
			newstr[i] = static_cast<char>(arr[i]);
		}
		newstr[size] = '\0';
		return newstr;
	}

	// 2 пара
	Array<T>& reSize(int size); // Если больше - мусор
	Array<T>& sortArr(); // Пузырковая

	T minElem() const;
	T maxElem() const;

	T operator[](int ind) const // get
	{
		return arr[ind];
	}
	T& operator[](int ind) // set
	{
		return arr[ind];
	}

	// Оператор + (склеить 2 массива)
	Array<T> operator+(const Array<T>& other) const
	{
		Array<T> result(size + other.size);
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
	Array<T> operator*(int n) const
	{
		Array<T> result(size * n);
		for (int k = 0; k < n; ++k)
		{
			for (int i = 0; i < size; ++i)
			{
				result.setElem(k * size + i, arr[i]);
			}
		}
		return result;
	}

	// Операторы +=, -=, *=, /= (поэлементные операции)
	Array<T>& operator+=(T scalar)
	{
		for (int i = 0; i < size; ++i)
		{
			arr[i] += scalar;
		}
		return *this;
	}
	Array<T>& operator-=(T scalar)
	{
		for (int i = 0; i < size; ++i)
		{
			arr[i] -= scalar;
		}
		return *this;
	}
	Array<T>& operator*=(T scalar)
	{
		for (int i = 0; i < size; ++i)
		{
			arr[i] *= scalar;
		}
		return *this;
	}
	Array<T>& operator/=(T scalar)
	{
		for (int i = 0; i < size; ++i)
		{
			arr[i] /= scalar;
		}
		return *this;
	}

	// Операторы ++ и -- (инкремент/декремент всех элементов)
	Array<T>& operator++()
	{
		for (int i = 0; i < size; ++i)
		{
			++arr[i];
		}
		return *this;
	}
	Array<T>& operator--()
	{
		for (int i = 0; i < size; ++i)
		{
			--arr[i];
		}
		return *this;
	}

	// Операторы == и != (сравнение по наполнению)
	bool operator==(const Array<T>& other) const
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
	bool operator!=(const Array<T>& other) const
	{
		return !(*this == other);
	}

	// Операторы >, <, >=, <= (сравнение по сумме элементов)
	bool operator>(const Array<T>& other) const
	{
		T sum1 = T{}, sum2 = T{};
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
	bool operator<(const Array<T>& other) const
	{
		T sum1 = T{}, sum2 = T{};
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
	bool operator>=(const Array<T>& other) const
	{
		return !(*this < other);
	}
	bool operator<=(const Array<T>& other) const
	{
		return !(*this > other);
	}

    // Оператор = (присваивание)
    Array<T>& operator=(const Array<T>& other)
    {
        if (this != &other)
        {
            delete[] arr;
            arr = new T[other.size];
            for (int i = 0; i < other.size; i++)
            {
                arr[i] = other.arr[i];
            }
            size = other.size;
        }
        return *this;
    }
    Array<T>& operator=(Array<T>&& other) noexcept
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
        //переделать operator= так, чтобы он работал как Array(Array&& a)
        /*Array::Array(Array&& a) : size{ a.size }, arr{ a.arr }
        {
            a.arr = nullptr;
            a.size = 0;
            std::cout << "Отработал конструктор перемещения: " << this << std::endl;
        }*/
    }

    // Операторы >> и << (ввод/вывод)
    friend std::ostream& operator<<(std::ostream& os, const Array<T>& a)
    {
        for (int i = 0; i < a.size; ++i)
        {
            os << a.arr[i] << " ";
        }
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Array<T>& a)
	{
		for (int i = 0; i < a.size; ++i)
		{
			is >> a.arr[i];
		}
		return is;
	}
};

