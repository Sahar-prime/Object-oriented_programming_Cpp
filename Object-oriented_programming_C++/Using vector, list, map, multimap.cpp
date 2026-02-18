#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>
#include <map>

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

void show(std::vector<std::vector<int>>& v) 
{
	for (int i = 0; i < v.size(); i++) 
	{
		for (int j = 0; j < v[i].size(); j++) 
		{
			std::cout << v[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void show(std::list<int>& v)
{
	std::list<int> ::iterator it;
	for (it = v.begin(); it != v.end(); it++)
	{
		std::cout << *(it) << " ";
	}
	std::cout << std::endl;
}

void show(const std::map<std::string, int>& m) 
{
	for (std::map<std::string, int>::const_iterator it = m.begin(); it != m.end(); ++it)
	{
		std::cout << it->first << ": " << it->second << std::endl;
	}
}
void show(const std::multimap<std::string, int>& mm) 
{
	for (std::multimap<std::string, int>::const_iterator it = mm.begin(); it != mm.end(); ++it)
	{
		std::cout << it->first << ": " << it->second << std::endl;
	}
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
	std::cout << std::endl;

	std::list<int> l; //двусвязный список
	std::list<int> l2 = { 4,7,3,5,2,7,4,1,4 };
	std::list<int> l3(5, 10);
	std::list<int> l4(l2);
	
	//std::cout << l3[5] << std::endl; //нет индексации
	std::list<int> ::iterator it, it2;
	for (it = l2.begin(); it != l2.end(); it++) 
	{
		std::cout << *(it) << " ";
	}
	std::cout << std::endl;

	it = l2.begin();
	for (int i = 0; i < 3; i++)
	{
		it++;
	}
	std::cout << std::endl;
	it2 = l2.end();
	for (int i = 0; i < 2; i++)
	{
		it2--;
	}
	
	std::list<int>l5(it2, l2.end());
	show(l5);
	std::cout << std::endl;

	l.push_back(10);
	l.push_front(20);
	l.pop_back();
	l.pop_back();

	l.sort();
	l.reverse();
	l.sort();
	l2.sort();
	l.merge(l2);//общий отсортированный список. Не будет объединять, если не отсортированны листы
	l2.remove(7);
	
	std::list<int> l11={ 4,2,5,7,2,5,7 };
	std::list<int> l22={ 2,0,5,9,1,6,2 };
	//l11.splice(l11.end(), l22, l22.begin());

	std::list<int>::iterator ite, ite2;
	ite = l22.begin();
	for (int i = 0; i < 2; i++)
	{
		ite++;
	}
	ite2 = l22.end();
	for (int i = 0; i < 2; i++)
	{
		ite2--;
	}
	l11.splice(l11.end(), l22, ite, ite2);
	std::cout << "L11: ";
	show(l11);
	std::cout << "L22: ";
	show(l22);

	l11.sort();
	l11.unique(); //дубликаты должны быть рядом
	show(l11);

	// 1 2 4 5 6 7 9 -> 2 4 5 6 7 9 1
	if (!l11.empty()) 
	{
		l11.splice(l11.end(), l11, l11.begin());
	}
	std::cout << "Final: ";
	show(l11);

	std::map<std::string, int> students;
	std::multimap<std::string, int> multiStudents;

	students["Sidorov"] = 3;
	students["Ivanov"] = 5;
	students["Petrov"] = 4;
	//multiStudents["Ivanov"] = 4; //не знает какой нужен Иванов
	show(students);
	students["Ivanov"] = 4;
	students.insert(std::pair<std::string, int>("Ivanov", 10));
	students.insert(std::pair<std::string, int>("Salykin", 10));
	show(students);
	multiStudents.insert(std::pair<std::string, int>("Ivanov", 10));
	multiStudents.insert(std::pair<std::string, int>("Salykin", 10));
	multiStudents.insert(std::pair<std::string, int>("Salykin", 20));
	show(multiStudents);
	std::multimap<std::string, int> ::iterator tt = multiStudents.lower_bound("Ivanov");
	std::multimap<std::string, int> ::iterator tt2 = multiStudents.upper_bound("Ivanov");
	for (tt; tt != tt2; tt++) 
	{
		std::cout << tt->first << " - " << tt->second << std::endl;
	}

	return 0;
}
#endif //MAIN
