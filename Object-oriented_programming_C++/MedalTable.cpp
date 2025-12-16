#include <iostream>
#include "MedalTable.h"

int MedalTable::findCountry(const char* country) const //индекс или -1 (если не нашел)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(medalRows[i].getCountry(), country) == 0)
		{
			return i;
		}
	}
	return -1;
}

MedalRow& MedalTable::operator[](const char* country)
{
	int index = findCountry(country);
	if (index == -1)
	{
		index = size++;
		medalRows[index].setCountry(country);
	}
	return medalRows[index];
}
MedalRow MedalTable::operator[](const char* country) const
{
	int index = findCountry(country);
	return medalRows[index];
}

void MedalTable::print() const
{
	for (int i = 0; i < size; i++)
	{
		medalRows[i].print();
	}
}