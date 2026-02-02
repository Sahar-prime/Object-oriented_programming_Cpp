#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>

//#define MAIN

#ifdef MAIN
int main() 
{
    setlocale(LC_ALL, "Russian");

    // Новые переменные для гибкости
    std::string fileName, fileExt, content;
    std::cout << "Введите имя файла (без расширения): ";
    std::cin >> fileName;
    std::cout << "Введите расширение (например, txt): ";
    std::cin >> fileExt;
    std::cin.ignore(); // Очистка буфера
    std::cout << "Введите содержимое файла: ";
    std::getline(std::cin, content);

    // СОЗДАНИЕ ПАПКИ через системную команду Windows
    system("mkdir \"C:\\Users\\user\\Рабочий стол\\Test\" 2> nul");

    std::string fullPath = "C:\\Users\\user\\Рабочий стол\\Test\\" + fileName + "." + fileExt;
    const char* path = fullPath.c_str();

    FILE* file = fopen(path, "w");
    if (file != NULL) 
    {
        fprintf(file, "%s", content.c_str()); // Запись введенного контента
        fclose(file);
        printf("Файл создан: %s\n", path);
    }
    else 
    {
        perror("Ошибка открытия файла");
    }
    char c[50];
    std::cout << "Введите 'delete file' для удаления или любой текст для сохранения: ";
    std::cin.getline(c, 50);

    if (strcmp(c, "delete file") == 0) 
    {
        if (remove(path) == 0)
        {
            std::cout << "Файл успешно удален!" << std::endl;
        }
        else 
        {
            perror("Ошибка при удалении файла");
        }
    }
    else
    {
        std::cout << "Файл сохранен на рабочем столе. Вы ввели: " << c << std::endl;
    }
}
#endif //MAIN