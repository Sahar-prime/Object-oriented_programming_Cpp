#include <iostream>

//#define MAIN

void func(int size)
{
	try
	{
		int* arr;
		if (size > 10)
		{
			throw size;
		}
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			std::cin >> arr[i];
			if (arr[i] > 5)
			{
				throw "Too much!";
			}
			if (arr[i] < 0)
			{
				throw "Too low!";
			}
		}
	}
	catch (...) 
	{
		std::cout << "Exception!\n";
		throw;
	}
}

#ifdef MAIN
int main() 
{
	//try catch ***throw
	float a, b;
	try
	{
		std::cout << "Enter a: ";
		std::cin >> a;
		std::cout << "Enter b: ";
		std::cin >> b;
		if (a==0 or b == 0)
		{
			throw "Division by zero!"; // Выбрасываем исключение вручную
		}
		std::cout << "a:b = " << a / b << std::endl;
	}
	catch (std::exception e) 
	{
		std::cout << "Error system!\n";
	}
	catch (...) //ловит все исключения (кроме встроенных)
	{
		std::cout << "Error!\n";
	}
	std::cout << "Continue\n";

	try 
	{
		func(5);
		func(-5);
		func(3);
	}
	catch (std::exception e)
	{
		std::cout << "Error! : " << e.what() << std::endl;
	}
	catch (int a)
	{
		std::cout << "Error! size = " << a << std::endl;
	}
	catch (const char* x)
	{
		std::cout << "Error! " << x << std::endl;
	}
	catch (...) 
	{
		std::cout << "Error out!\n";
	}
}
#endif //MAIN
