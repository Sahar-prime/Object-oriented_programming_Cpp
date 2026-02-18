#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>

//#define MAIN

void show(std::vector<int> &v) 
{
	std::cout << "Size: " << v.size() << " " << v.capacity() << " " << v.max_size() << std::endl;
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

#ifdef MAIN
int main() 
{
	setlocale(0, "");

//vector list map multimap
	int size = 5;
	std::vector<int> v1; //пустой вектор
	std::vector<int> v2(5, 7);
	std::vector<int> v3(v2);
	std::vector<int> v4 = { 8, 3, 1, 3, 5, 7 };
	show(v2);
	show(v3);
	std::cout << std::endl;
	for (int i = 0; i < size; i++)
	{
		v1.push_back(5);
	}
	show(v1);
	for (int i = 0; i < size; i++)
	{
		v1.push_back(5);
	}
	show(v1);
	for (int i = 0; i < size; i++)
	{
		v1.push_back(5);
	}
	show(v1);
	std::cout << std::endl;
	//5 5 5 5 5 -> 5 6
	//5 5 5 5 5 5 5 5 5 5 -> 10 13
	//5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 -> 15 19
	
	//if (v1 == v2)
	//if (v1[8] == v2[3])
	std::cout << v1.at(7) << std::endl;
	v1.at(7) = 10;
	show(v1);
	std::cout << std::endl;

	std::vector<int> vect = { 4,2,5,6,5,4 };
	/*std::cout << vect[15] << std::endl;
	vect[15] = 10;*/
	try
	{
		std::cout << vect.at(5) << std::endl;
		vect.at(15) = 10;
		show(vect);
	}
	catch (...) 
	{
		std::cout << "out of range\n";
	}
	vect.pop_back();

	std::vector<int> vc = { 4,2,7,4,8 };
	vect.swap(vc);
	std::cout << std::endl;
	//vect.clear();
	//if(vect.empty())

	std::vector<int> g = { 4,2,5,6,5,4 }; //begin - первый, end - за последний
	show(g);
	std::cout << std::endl;
	std::vector<int>::iterator iter = g.begin(), iter2;
	for (int i = 0; i < g.size(); i++)
	{
		std::cout << *(iter + i) << " ";
	}
	std::cout << std::endl;
	for (iter = g.begin(); iter != g.end(); iter++)
	{
		std::cout << *(iter) << " ";
	}
	std::cout << std::endl;

	std::vector<int>::reverse_iterator riter = g.rbegin();
	for (riter; riter != g.rend(); riter++)
	{
		std::cout << *(riter) << " ";
	}
	std::cout << std::endl;

	iter = g.begin();
	g.resize(20);
	iter = g.begin();
	g.insert(iter + 3, 10);
	show(g);
	std::cout << std::endl;
	
	/*std::vector<int> g2(g.begin() + 3, g.end() - 2);
	show(g2);
	iter2 = g2.begin();
	g2.insert(iter2 + 2, g.begin() + 5, g2.end() - 3);
	show(g);*/

	/*g2.erase(g2.begin() + 5);
	g2.erase(g2.begin() + 3, g2.end() - 5);*/

	//two-dimensional vector
	const int s = 10;
	std::vector<std::vector<int>> multiplicationTable(s, std::vector<int>(s));
	for (int i = 0; i < s; ++i)
	{
		for (int j = 0; j < s; ++j) 
		{
			multiplicationTable[i][j] = (i + 1) * (j + 1);
		}
	}
	for (int i = 0; i < multiplicationTable.size(); ++i)
	{
		for (int j = 0; j < multiplicationTable[i].size(); ++j) 
		{
			std::cout << multiplicationTable[i][j] << "\t";
		}
		std::cout << std::endl;
	}

}
#endif //MAIN
