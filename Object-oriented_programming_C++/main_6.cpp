#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Book.h"

//#define MAIN_6

void show(Book* b, int size) 
{
	for (int i = 0; i < size; ++i) 
	{
		b[i].show();
	}
}

void search_author(Book* b, int size, const char* author) 
{
	char* copy_user = new char[strlen(author) + 1];
	strcpy(copy_user, author);
	_strlwr(copy_user);

	for (int i = 0; i < size; ++i)
	{
		char* copy = new char[strlen(b[i].getAuthor()) + 1];
		strcpy(copy, b[i].getAuthor());
		_strlwr(copy);

		if (strstr(copy, copy_user)) 
		{
			b[i].show();
		}
	}
}
void search_year(Book* b, int size, int year) 
{
	for (int i = 0; i < size; ++i) 
	{
		if (b[i].getYear() == year) 
		{
			b[i].show();
		}
	}
}

#ifdef MAIN_6
int main()
{ 
	setlocale(LC_ALL, "");

	Book b;
	Book b2{ "qqq", "ttt", 1243 };
	Book b3{ b2 };
	b.show();
	b2.show();
	b3.show();
	std::cout << b2.getAuthor() << " " << b3.getYear() << std::endl;

	Book b1[3] = { Book{}, Book{"Author", "Title", 2000}, Book{b1[1]} };
	search_author(b1, 3, "Author");
	std::cout << std::endl;
	search_year(b1, 3, 2000);
}
#endif //MAIN_6
