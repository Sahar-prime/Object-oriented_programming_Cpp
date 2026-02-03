#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>

//#define MAIN

#ifdef MAIN
int main() 
{
    setlocale(LC_ALL, "");

    system("mkdir \"C:\\Users\\user\\Рабочий стол\\User\" 2> nul");
    std::string path = "C:\\Users\\user\\Рабочий стол\\User\\", cmd, ext, name, buf;
    std::cout << "Все команды: add, rename, copy, size, delete, exit" << std::endl;

    while (true) 
    {
        std::cout << ">";
        std::cin >> cmd;
        if (cmd == "exit") break;

        if (cmd == "add")
        {
            std::cout << "Имя файла: "; std::cin >> name;
            std::cout << "Расширение (без точки): "; std::cin >> ext;

            std::string full = path + name + "." + ext;
            FILE* f = fopen(full.c_str(), "a");
            if (f) 
            {
                std::cout << "Текст: ";
                std::cin.ignore();
                std::getline(std::cin, buf);
                fprintf(f, "%s\n", buf.c_str());
                fclose(f);
                std::cout << "Записано в " << name << "." << ext << "\n";
            }
        }
        else if (cmd == "rename") 
        {
            std::string oldFull, newName, newExt;
            std::cout << "Имя файла для переименования (с расширением): "; std::cin >> name;
            oldFull = path + name;

            std::cout << "Новое имя: "; std::cin >> newName;
            std::cout << "Новое расширение: "; std::cin >> newExt;

            std::string newFull = path + newName + "." + newExt;

            if (rename(oldFull.c_str(), newFull.c_str()) == 0) 
            {
                std::cout << "Файл успешно переименован в " << newName << "." << newExt << "\n";
            }
            else 
            {
                perror("Ошибка при переименовании");
            }
        }
        else if (cmd == "copy")
        {
            std::cout << "Файл (с расширением): "; std::cin >> name;
            std::string target, targetExt;
            std::cout << "Имя копии: "; std::cin >> target;
            std::cout << "Расширение копии: "; std::cin >> targetExt;

            FILE* s = fopen((path + name).c_str(), "rb");
            FILE* d = fopen((path + target + "." + targetExt).c_str(), "wb");
            if (s && d) 
            {
                char ch;
                while (fread(&ch, 1, 1, s)) fwrite(&ch, 1, 1, d);
                fclose(s); fclose(d);
                std::cout << "Копия создана.\n";
            }
            else 
            {
                std::cout << "Ошибка: файл не найден.\n";
            }
        }
        else if (cmd == "size")
        {
            std::cout << "Файл (с расширением): ";
            std::cin >> name;
            FILE* f = fopen((path + name).c_str(), "rb"); // Открываем в бинарном режиме
            if (f) 
            {
                fseek(f, 0, SEEK_END);    // Переходим в конец файла
                long size = ftell(f);     // Получаем текущую позицию (это и есть размер)
                fclose(f);
                std::cout << "Размер: " << size << " байт\n";
            }
            else
            {
                perror("Ошибка");
            }
        }
        else if (cmd == "delete")
        {
            std::cout << "Файл для удаления (с расширением): ";
            std::cin >> name;
            if (remove((path + name).c_str()) == 0) std::cout << "Удалено.\n";
            else perror("Ошибка");
        }
        else if (cmd == "help")
        {
            std::cout << "Все команды: add, rename, copy, size, delete, exit" << std::endl;
        }
    }
}
#endif //MAIN