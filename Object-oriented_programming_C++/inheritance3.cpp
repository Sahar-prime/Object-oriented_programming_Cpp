#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//#define MAIN

class Student
{
protected:
	char* name;
	int* marks;
	int count;
public:
	Student(const char* name, const int* marks, int count) :
		name{ new char[strlen(name) + 1] },
		marks{ new int[count] },
		count{ count }
	{
		strcpy(this->name, name);
		for (int i = 0; i < count; ++i) 
		{
			this->marks[i] = marks[i];
		}
	}
	void set_name(const char* n) 
	{
		delete[] name;
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	const char* get_name() const 
	{
		return name; 
	}
	void set_marks(const int* m, int count)
	{
		delete[] marks;
		this->count = count;
		this->marks = new int[count];
		for (int i = 0; i < count; i++) marks[i] = m[i];
	}
	const int* get_marks() const 
	{
		return marks;
	}
	void set_mark(int index, int value) 
	{
		if (index >= 0 && index < count) 
		{
			marks[index] = value;
		}
	}
	int get_mark(int index) const
	{
		if (index >= 0 && index < count)
		{
			return marks[index];
		}
		return -1; // Или выбросить исключение
	}
	virtual void show() const 
	{
		std::cout << "Student: " << name << "\nMarks: ";
		for (int i = 0; i < count; ++i)
		{
			std::cout << marks[i] << " ";
		}
		std::cout << std::endl;
	}
	virtual ~Student()
	{
		delete[] name;
		delete[] marks;
	}
	int get_count() const
	{
		return count;
	}
};
class Aspirant : public Student 
{
	char* title;
	bool is_done;
public:
	Aspirant():
		Student("", nullptr, 0),
		title{ nullptr }, 
		is_done{ false }
	{
		title = new char[1];
		title[0] = '\0';
	}
	Aspirant(const char* name, const int* marks, int count, const char* title, bool is_done)
		: Student(name, marks, count),
		is_done{ is_done },
		title{ new char[strlen(title) + 1] }
	{
		strcpy(this->title, title);
	}
	void set_title(const char* t)
	{
		delete[] title;
		title = new char[strlen(t) + 1];
		strcpy(title, t);
	}
	const char* get_title() const
	{
		return title;
	}
	void set_done(bool status) 
	{
		is_done = status;
	}
	bool get_done() const
	{
		return is_done;
	}
	virtual ~Aspirant() 
	{
		delete[] title;
	}
	virtual void show() const 
	{
		Student::show();
		std::cout << "Title: " << title << "\nStatus: " << (is_done ? "Finished" : "In progress") << std::endl;
	}
};
class GraduationGroup 
{
	char* number;
	Aspirant* group;
	int count;
public:
	//GraduationGroup() : number{ nullptr }, group{ nullptr }, count{ 0 } {}
	GraduationGroup(const char* number, const Aspirant* group, int count):
		number{new char[strlen(number)+1]},
		group{new Aspirant[count]},
		count{count}
	{
		strcpy(this->number, number);
		for (int i = 0; i < count; i++) 
		{
			this->group[i].set_name(group[i].get_name());
			for (int j = 0; j < this->group[i].get_count(); j++) 
			{
				this->group[i].set_mark(rand() % 5 + 1, j);
			}
			this->group[i].set_title(group[i].get_title());
			this->group[i].set_done(group[i].get_done());
		}
	}
	void set_number(const char* n) 
	{
		delete[] number;
		number = new char[strlen(n) + 1];
		strcpy(number, n);
	}
	const char* get_number() const 
	{
		return number;
	}
	void set_group(const Aspirant* aspirants, int count)
	{
		delete[] this->group;
		this->group = new Aspirant[count];
		for (int i = 0; i < count; i++)
		{
			this->group[i].set_name(group[i].get_name());
			for (int j = 0; j < this->group[i].get_count(); j++)
			{
				this->group[i].set_mark(rand() % 5 + 1, j);
			}
			this->group[i].set_title(group[i].get_title());
			this->group[i].set_done(group[i].get_done());
		}
	}
	~GraduationGroup() 
	{
		delete[] number;
		delete[] group;
	}
};

#ifdef MAIN
int main() 
{
	Student* a = new Aspirant{ "qwerty" , new int[3] {4, 5, 3}, 3, "title", false};
	a->show();
}
#endif //MAIN