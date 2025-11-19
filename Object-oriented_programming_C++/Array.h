#pragma once
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

	//*** 3 варианта использования this
};

