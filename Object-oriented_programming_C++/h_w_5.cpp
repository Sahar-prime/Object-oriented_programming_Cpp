#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//#define H_W_5

class Passport 
{
protected:
	char fio[35];
	int number[7];
public:
	Passport(const char* fio, const int* number)
	{
		strcpy(this->fio, fio);

		for (int i = 0; i < 7; i++)
		{
			this->number[i] = number[i];
		}
	}
	void set_fio(const char* fio)
	{
		strcpy(this->fio, fio);
	}
	void set_number(const int* number)
	{
		for (int i = 0; i < 7; i++)
		{
			this->number[i] = number[i];
		}
	}
	const int* get_number() const
	{
		return number;
	}
	const char* get_fio() const 
	{ 
		return fio;
	}
	void print() const
	{
		std::cout << "FIO: " << fio << std::endl;
		std::cout << "Number: ";
		for (int i = 0; i < 7; i++)
		{
			std::cout << number[i];
		}
		std::cout << std::endl;
	}
};
class foreignPassport : public Passport 
{
private:
	int number_visa[7];
	char county[4];
public:
	foreignPassport(const char* fio, const int* number, const char* county, const int* number_visa):
		Passport{ fio, number }
	{
		strcpy(this->county, county);

		for (int i = 0; i < 7; i++)
		{
			this->number_visa[i] = number_visa[i];
		}
	}
	void set_county(const char* county)
	{
		strcpy(this->county, county);
	}
	void set_number_visa(const int* number_visa)
	{
		for (int i = 0; i < 7; i++)
		{
			this->number_visa[i] = number_visa[i];
		}
	}
	const int* get_number_visa() const
	{
		return number_visa;
	}
	const char* get_county() const
	{
		return county;
	}
	void print() const
	{
		Passport::print();
		std::cout << "County: " << county << std::endl;
		std::cout << "Number visa: ";
		for (int i = 0; i < 7; i++)
		{
			std::cout << number_visa[i];
		}
		std::cout << std::endl;
	}
};

#ifdef H_W_5
int main()
{
	int n1[7] = { 1,1,1,1,1,1,1 }, n2[7] = { 2,2,2,2,2,2,2 };

	Passport p("Ivanov", n1);
	p.print();

	foreignPassport fp("Petrov", n1, "USA", n2);

	fp.set_fio("Sidorov");
	fp.set_number(n2);
	fp.set_county("UK");
	fp.set_number_visa(n1);

	std::cout << "\nUpdated: " << fp.get_fio() << " [" << fp.get_county() << "]\n";
	std::cout << "Pass num: " << fp.get_number()[0] << " Visa num: " << fp.get_number_visa()[0] << "\n\n";

	fp.print();
}
#endif //H_W_5