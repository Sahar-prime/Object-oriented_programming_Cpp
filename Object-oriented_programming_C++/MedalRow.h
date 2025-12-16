#pragma once
#include<iostream>

enum medals { gold, silver, bronze };

class MedalRow 
{
	char country[4];
	int medals[3];
public:
	MedalRow(const char* country, const int* medals);
	MedalRow() : MedalRow{ nullptr, nullptr } {} //если известно страна, пишем страну, если нет-NON и также с медалями
	
	MedalRow& setCountry(const char* country);
	const char* getCountry()const;

	int& operator[](int index) 
	{
		return medals[index];
	}
	int operator[](int index) const 
	{
		return medals[index];
	}

	void print() const; // вывод страны и их медали
};

