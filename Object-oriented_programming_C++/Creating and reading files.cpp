#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream> //ofstream ifstream
#include <stdio.h>
#include <io.h>
#include <direct.h>

//#define MAIN

struct Student
{
	char name[20];
	int age;
	float aver;
};

void RenameFile()
{
	char oldName[256], newName[256];

	std::cout << "Enter current file path: ";
	std::cin.getline(oldName, 256);

	std::cout << "Enter new path/name: ";
	std::cin.getline(newName, 256);

	if (rename(oldName, newName) == 0) 
	{
		std::cout << "Successfully renamed/moved.\n";
	}
	else
	{
		perror("Error");
	}
}
void RemoveFile()
{
	char fileName[256];

	std::cout << "Enter file path to delete: ";

	std::cin.getline(fileName, 256);

	if (remove(fileName) == 0)
	{
		std::cout << "File deleted.\n";
	}
	else {
		perror("Error");
	}
}
void SearchDir() 
{
	char path[50];
	std::cout << "Enter path with mask: ";
	std::cin.getline(path, 50);
	//_finddata_t - структура хранящая информацию о файле
	_finddata_t fileinfo; // Создаем на стеке, выделять память через new не нужно
	intptr_t handle = _findfirst(path, &fileinfo);

	if (handle == -1) 
	{
		std::cout << "No files found or invalid path." << std::endl;
		return;
	}
	int counter = 0;
	do 
	{
		// Пропускаем системные папки "." и ".."
		if (fileinfo.name[0] != '.') {
			std::cout << fileinfo.name << std::endl;
			counter++;
		}
	} while (_findnext(handle, &fileinfo) == 0);

	std::cout << "Total files found: " << counter << std::endl;

	_findclose(handle);
}
void GreatDir() 
{
	char Name[50];
	std::cout << "Enter name: ";
	std::cin.getline(Name, 50);
	if (_mkdir(Name) == -1) 
	{
		perror("Error\n");
	}
	else 
	{
		std::cout << "OK\n";
	}
}
void RemoveDir()
{
	char Name[50];
	std::cout << "Enter name: ";
	std::cin.getline(Name, 50);
	if (_rmdir(Name) == -1)
	{
		perror("Error\n");
	}
	else
	{
		std::cout << "OK\n";
	}
}

#ifdef MAIN
int main()
{
	setlocale(LC_ALL, "");

	const int size = 5;
	int arr[size] = { 4, 2, 9, 6, 1 };
	FILE* f; //файловый указатель
	f = fopen("C:\\Users\\user\\Рабочий стол\\123.txt", "w");
	//r - read ВАЖНО: если файла нет - ошибка
	//w - write 
	//a - add/append
	int a = 2;
	float b = 5.7;
	fprintf(f, "%d %f ", a, b);
	for (int i = 0; i < size; i++)
	{
		fprintf(f, "%d ", arr[i]);
	}
	fclose(f);
	f = fopen("C:\\Users\\user\\Рабочий стол\\123.txt", "r");
	int a2;
	float b2;
	int arr2[size];
	
	if ((f = fopen("C:\\Users\\user\\Рабочий стол\\123.txt", "r")) == 0) 
	{
		printf("Ошибка: файл не найден.\n");
		return 1;
	}
	fscanf(f, "%d %f", &a2, &b2);
	for (int i = 0; i < size; i++) 
	{
		fscanf(f, "%d", &arr2[i]);
	}
	fclose(f);
	std::cout << a2 << " " << b2 << "\n";
	for (int i = 0; i < size; i++) 
	{
		std::cout << arr2[i] << " ";
	}
	std::cout << std::endl;

//Student
	const char* path = "C:\\Users\\user\\Рабочий стол\\Student.txt";
	FILE* file;
	file = fopen(path, "w");
	Student s = { "Ivan", 20, 4.1 };
	fprintf(file, "%s %d %f", s.name, s.age, s.aver);
	fclose(file);

	if ((file = fopen(path, "r")) == 0)
	{
		printf("Ошибка: файл не найден.\n");
		return 1;
	}
	Student s2;
	file = fopen(path, "r");
	fscanf(file, "%s %d %f", s2.name, &s2.age, &s2.aver);
	fclose(file);
	std::cout << s2.name << " " << s2.age << " " << s2.aver << std::endl;

//
	const char* path_arr = "C:\\Users\\user\\Рабочий стол\\arr.txt";
	int z1, z2, ns1, ns2;
	std::cin >> z1 >> z2;
	int** arrz = new int* [z1];
	for (int i = 0; i < z1; i++) 
	{
		arrz[i] = new int[z2];
		for (int j = 0; j < z2; j++) arrz[i][j] = rand() % 10;
	}
	std::ofstream outFile_arr(path_arr);
	outFile_arr << z1 << " " << z2 << "\n";
	for (int i = 0; i < z1; i++)
	{
		for (int j = 0; j < z2; j++) 
		{
			outFile_arr << arrz[i][j] << " ";
		}
		outFile_arr << "\n";
	}
	outFile_arr.close();
	std::ifstream inFile_arr(path_arr);
	if (inFile_arr >> ns1 >> ns2)
	{
		int** arrx = new int* [ns1];
		for (int i = 0; i < ns1; i++) 
		{
			arrx[i] = new int[ns2];
			for (int j = 0; j < ns2; j++)
			{
				inFile_arr >> arrx[i][j];
				std::cout << arrx[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	inFile_arr.close();
//
	int user;
	do 
	{
		std::cout << "1 - Rename/Move File\n2 - Remove File\n3 - Search Dir\n";
		std::cout << "4 - Great Dir\n5 - Remove Dir\n6 - Rename Dir\n0 - Exit\n";
		std::cout << "Your choice: ";
	
		if (!(std::cin >> user)) 
		{ 
			std::cout << "Invalid input. Please enter a number.\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}
		std::cin.ignore(32767, '\n');
	
		switch (user) 
		{
		case 1:
			RenameFile();
			break;
		case 2:
			RemoveFile();
			break;
		case 3:
			SearchDir();
			break;
		case 4:
			GreatDir();
			break;
		case 5:
			RemoveDir();
			break;
		case 6:
			RenameFile();
			break;
		case 0:
			std::cout << "Exit...\n";
			break;
		default:
			std::cout << "Unknown command!\n";
			break;
		}
	} while (user != 0);

}
#endif //MAIN