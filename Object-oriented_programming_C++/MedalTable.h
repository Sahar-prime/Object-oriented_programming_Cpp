#pragma once
#include "MedalRow.h"
class MedalTable
{
	MedalRow medalRows[10];
	int size;
	int findCountry(const char* country) const; //индекс или -1 (если не нашел)
public:
	MedalTable() : size{ 0 } {}
	//добавить новую строку или изменить существующую
	MedalRow& operator[](const char* country);
	MedalRow operator[](const char* country) const;

	void print() const;
};