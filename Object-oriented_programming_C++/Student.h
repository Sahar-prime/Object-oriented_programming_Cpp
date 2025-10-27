#pragma once
//struct - все поля открыты(public)
//class - все поля закрыты(private)
class Student
{
	//Спецификаторы доступа: 
	//public, private, protected
	char name[20]; //Поле
	int marks[3];

public:
	void init();
	void show();
	double aver();

	void setName(const char* uname);
	char* getName();
	void setMark(int mark, int index);
	int getMark(int index);
};

