#include <iostream>
#include "MedalRow.h"
#include "MedalTable.h"

//#define MAIN_11

#ifdef MAIN_11
int main() 
{
	MedalRow mr;
	mr.setCountry("RUS");
	std::cout << "Country: " << mr.getCountry() << std::endl;
	mr[gold] = 3;
	mr[silver] = 7;
	mr[bronze] = 2;
	mr.print();

	MedalTable mt;
	mt["RUS"][silver] = 7;
	mt["USA"][bronze] = 3;
	mt["RUS"][gold] = 2;
	mt["FRA"][silver] = 6;
	mt["USA"][silver] = 5;
	mt.print();

}
#endif //MAIN_11