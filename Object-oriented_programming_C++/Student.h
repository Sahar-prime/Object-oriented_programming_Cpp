#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#pragma once
//struct - все поля открыты(public)
//class - все поля закрыты(private)
class Student
{
	//Спецификаторы доступа: 
	//public, private, protected
	char *name; //Поле
	int *marks;
    int count;
	void creatStr(const char* uname);
public:
	Student();
	Student(const char* uname);
	Student(int* umarks, int ucount);
	Student(const char* uname, int* umarks, int ucount);
	Student(const Student& s);
	
	//деструктор
	~Student();

	void init();
	void show();
	double aver();

	void setName(const char* uname);
	char* getName();
	void setMark(int mark, int index);
	int getMark(int index);
};

