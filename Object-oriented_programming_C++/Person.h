#pragma once

class Person
{
	char *name;
	int age;
public:
	Person();
	Person(const char* uname);
	Person(int uage);
	Person(const char* uname, int uage);
	~Person();

	void show();
};

