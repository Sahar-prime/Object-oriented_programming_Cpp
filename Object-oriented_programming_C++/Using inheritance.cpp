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
class Dog : public Animal 
{
protected:
	int number_commands;
	double size_dog;
public:
	Dog(const char* name, int years, int number_commands, double size_dog) :
		Animal{ name, years }, size_dog{ size_dog }, number_commands{ number_commands } 
	{}
	void set_number_commands(int number_commands)
	{
		this->number_commands = number_commands;
	}
	void set_size_dog(double size_dog)
	{
		this->size_dog = size_dog;
	}
	double get_size_dog()const
	{
		return size_dog;
	}
	int get_number_commands()const
	{
		return number_commands;
	}
	void print() const
	{
		Animal::print();
		std::cout << "Number commands: " << number_commands << std::endl;
		std::cout << "Size dog: " << size_dog << std::endl;
	}
};
class Lion : public Cat
{
protected:
	char terr[20];
	char flock[20];
public:
	Lion(const char* name, int years, const char* breed, double sleep, const char* terr, const char* flock)
		: Cat(name, years, breed, sleep)
	{
		strcpy(this->terr, terr);
		strcpy(this->flock, flock);
	}
	void set_terr(const char* terr) 
	{
		strcpy(this->terr, terr); 
	}
	void set_flock(const char* flock) 
	{ 
		strcpy(this->flock, flock); 
	}
	const char* get_terr() const 
	{ 
		return terr; 
	}
	const char* get_flock() const 
	{ 
		return flock;
	}
	void print() const 
	{
		Cat::print();
		std::cout << "Territory: " << terr << std::endl;
		std::cout << "Flock: " << flock << std::endl;
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

class CPU 
{
protected:
	int cores;
	double frequency;
public:
	CPU(int cores, double frequency) : cores{ cores }, frequency{ frequency } {}
	void set_cores(int cores) 
	{
		this->cores = cores;
	}
	void set_frequency(double frequency) 
	{
		this->frequency = frequency;
	}
	int get_cores() const 
	{
		return cores;
	}
	double get_frequency() const
	{
		return frequency;
	}
	void print() const
	{
		std::cout << "Cores: " << cores << std::endl;
		std::cout << "Frequency: " << frequency << std::endl;
	}
};
class RAM 
{
protected:
	char firm[20];
	int count;
public:
	RAM(const char* firm, int count) : count{count}
	{
		strcpy(this->firm, firm);
	}
	void set_firm(const char* firm) 
	{
		strcpy(this->firm, firm);
	}
	void set_count(int count)
	{
		this->count = count;
	}
	const char* get_firm() const 
	{
		return firm;
	}
	int get_count() const 
	{
		return count;
	}
	void print() const 
	{
		std::cout << "Firm: " << firm << std::endl;
		std::cout << "Count: " << count << std::endl;
	}
};

class COMP : public CPU, public RAM
{
protected:
	char name[20];
public:
	COMP (const char* name, int cores, double frequency, const char* firm, int count) :
		CPU{ cores, frequency }, RAM{ firm, count }
	{
		strcpy(this->name, name);
	}
	void set_name() 
	{
		strcpy(this->name, name);
	}
	const char* get_name() const 
	{
		return name;
	}
	void print() const 
	{
		std::cout << "Name: " << name << std::endl;
		CPU::print();
		RAM::print();
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

	Lion l{ "Alex", 10, "asd", 13.5, "Afrika", "tip" };
	l.print();
	std::cout << std::endl;
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
	std::cout << a.get_name_job() << " - " << a.get_status() << "\n" << std::endl;;
//COMP
	COMP comp{ "qwerty", 4, 2.2, "test", 2 };
	comp.print();
}
#endif //MAIN