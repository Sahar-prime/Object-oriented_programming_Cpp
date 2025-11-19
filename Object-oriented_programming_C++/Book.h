#pragma once
class Book
{
	char* author;
	char* title;
	int year;
public:
	Book();
	Book(const char* author, const char* title, int year);
	Book(const Book& b);
	~Book();
	void show()const;
	//методы по необходимости
	const char* getAuthor() const;
	int getYear() const;
};