#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <iostream>

Book::Book(const char* author, const char* title, int year) :
    author{ new char[strlen(author) + 1] },
    title{ new char[strlen(title) + 1] }, year{ year }
{
    strcpy(this->author, author);
    strcpy(this->title, title);
}

Book::Book(const Book& b) : Book{ b.author, b.title, b.year } {}

Book::Book() : Book{ "NO_AUTHOR", "NO_TITLE", 0} {}

Book::~Book() 
{
    delete[] author;
    delete[] title;
}

void Book::show() const
{
    std::cout << "Author: " << author << ", Title: " << title << ", Year: " << year << std::endl;
}

const char* Book::getAuthor() const 
{
    return author;
}

int Book::getYear() const 
{
    return year;
}

