#pragma once
#include <iostream>
//struct - все поля открыты(public)
//class - все поля закрыты(private)
class Student
{
	//Спецификаторы доступа: 
	//public, private, protected
	char *name;//Поле
	int *marks;
    int count;
	void creatStr(const char* uname);
public:
	Student();
	Student(const char* uname);
	Student(int* umarks, int ucount);
	Student(const char* uname, int* umarks, int ucount);
	Student(const Student& s);
	Student(Student&& s)noexcept;
	
	//деструктор
	~Student();

	void init();
	void show();
	double aver();

	void setName(const char* uname);
	char* getName();
	void setMark(int mark, int index);
	int getMark(int index);

	Student& operator=(const Student& other);
	Student& operator=(Student&& other) noexcept;
};

