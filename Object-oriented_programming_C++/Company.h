#pragma once
#include "Person_2.h"
class Company 
{
	char* title;
	Person_2 director;
public:
	Company();
	Company(const char* utitle);
	Company(const Person_2& dir);
	Company(const char* utitle, const Person_2& dir);
	Company(const Company& p);
	Company(Company&& p) noexcept;
	~Company();

	void show();
};