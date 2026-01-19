#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//#define MAIN

class Animal 
{
protected:
	char name[20];
	int years;
public:
	Animal(const char* name, int years) : years{ years } 
	{
		strcpy(this->name, name);
	};
	void set_name(const char* name) 
	{
		strcpy(this->name, name);
	}
	void set_years(int years)
	{
		this->years = years;
	}
	const char* get_name()const 
	{
		return name;
	}
	int get_years()const
	{
		return years;
	}
	void print() const
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Year: " << years << std::endl;
	}
};
class Cat : public Animal
{
protected:
	char breed[20];
	double sleep;
public:
	Cat(const char* name, int years, const char* breed, double sleep) :
		Animal{ name, years }, sleep{ sleep }
	{
		strcpy(this->breed, breed);
	}
	void set_breed(const char* breed)
	{
		strcpy(this->breed, breed);
	}
	void set_sleep(int sleep)
	{
		this->sleep = sleep;
	}
	const char* get_breed()const
	{
		return breed;
	}
	int get_sleep()const
	{
		return sleep;
	}
	void print() const
	{
		Animal::print();
		std::cout << "Breed: " << breed << std::endl;
		std::cout << "Sleep: " << sleep << std::endl;
	}
};

class Student
{
protected:
	char name[20];
	int year;
public:
	Student(const char* name, int year) : year{ year } 
	{
		strcpy(this->name, name);
	};
	void set_name(const char* name)
	{
		strcpy(this->name, name);
	}
	void set_years(int years)
	{
		this->year = years;
	}
	const char* get_name()const
	{
		return name;
	}
	int get_years()const
	{
		return year;
	}
	void print() const
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Year: " << year << std::endl;
	}
};
class Aspirant : public Student
{
private:
	char name_job[20];
	bool status;
public:
	Aspirant(const char* name, int year, const char* name_job, bool status) :
		Student{name, year},
		status {status}
	{
		strcpy(this->name_job, name_job);
	}
	void set_name_job(const char* name_job)
	{
		strcpy(this->name_job, name_job);
	}
	void set_status(bool status)
	{
		this->status = status;
	}
	const char* get_name_job() const
	{
		return name_job;
	}
	bool get_status()const
	{
		return status;
	}
	void print() const
	{
		Student::print();
		std::cout << "Name_job: " << name_job << std::endl;
		std::cout << "Status: " << status << std::endl;
	}
};

#ifdef MAIN
int main() 
{
//Animal
	Cat c{ "Murka", 7, "persidskaya", 17.4 };
	c.print();
	std::cout << std::endl;
	c.set_name("Darvin");
	c.set_years(10);
	c.set_breed("Mainecoon");
	c.set_sleep(12);
	std::cout << c.get_name() << " " << c.get_years() << std::endl;
	std::cout << c.get_breed() << " " << c.get_sleep() << std::endl << std::endl;
//Student
	Student s("Ivan", 1);
	s.set_name("Max");
	s.set_years(21);
	s.print();
	std::cout << s.get_name() << " " << s.get_years() << "\n\n";
	Aspirant a("Oleg", 1, "Math", true);
	a.set_name_job("Physics");
	a.set_status(false);
	a.print();
	std::cout << a.get_name_job() << " - " << a.get_status() << "\n";
}
#endif //MAIN