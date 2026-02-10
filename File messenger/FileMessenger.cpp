#include "FileMessenger.h"

FileManager::FileManager()
{
    path = "C:\\Users\\user\\Рабочий стол\\User\\";
    system("mkdir \"C:\\Users\\user\\Рабочий стол\\User\" 2> nul");
}

void FileManager::printHelp()
{
    std::cout << "Все команды: add, rename, copy, size, delete, exit" << std::endl;
}

void FileManager::addFile()
{
    std::string name, ext, buf;
    std::cout << "Имя файла: ";
    std::cin >> name;
    std::cout << "Расширение (без точки): ";
    std::cin >> ext;

    std::string fullPath = path + name + "." + ext;
    FILE* file = fopen(fullPath.c_str(), "a");
    if (file)
    {
        std::cout << "Текст: ";
        std::cin.ignore();
        std::getline(std::cin, buf);
        fprintf(file, "%s\n", buf.c_str());
        fclose(file);
        std::cout << "Записано в " << name << "." << ext << "\n";
    }
    else
    {
        std::cerr << "Ошибка при открытии файла.\n";
    }
}

void FileManager::renameFile()
{
    std::string name, newName, newExt;
    std::cout << "Имя файла для переименования (с расширением): ";
    std::cin >> name;
    std::string oldFullPath = path + name;

    std::cout << "Новое имя: ";
    std::cin >> newName;
    std::cout << "Новое расширение: ";
    std::cin >> newExt;

    std::string newFullPath = path + newName + "." + newExt;

    if (rename(oldFullPath.c_str(), newFullPath.c_str()) == 0)
    {
        std::cout << "Файл успешно переименован в " << newName << "." << newExt << "\n";
    }
    else
    {
        perror("Ошибка при переименовании");
    }
}

void FileManager::copyFile()
{
    std::string name, target, targetExt;
    std::cout << "Файл (с расширением): ";
    std::cin >> name;
    std::cout << "Имя копии: ";
    std::cin >> target;
    std::cout << "Расширение копии: ";
    std::cin >> targetExt;

    FILE* source = fopen((path + name).c_str(), "rb");
    FILE* dest = fopen((path + target + "." + targetExt).c_str(), "wb");

    if (source && dest)
    {
        char ch;
        while (fread(&ch, 1, 1, source))
        {
            fwrite(&ch, 1, 1, dest);
        }
        fclose(source);
        fclose(dest);
        std::cout << "Копия создана.\n";
    }
    else
    {
        std::cerr << "Ошибка: файл не найден.\n";
    }
}

void FileManager::getFileSize()
{
    std::string name;
    std::cout << "Файл (с расширением): ";
    std::cin >> name;

    FILE* file = fopen((path + name).c_str(), "rb");
    if (file)
    {
        fseek(file, 0, SEEK_END);
        long size = ftell(file);
        fclose(file);
        std::cout << "Размер: " << size << " байт\n";
    }
    else
    {
        perror("Ошибка");
    }
}

void FileManager::deleteFile()
{
    std::string name;
    std::cout << "Файл для удаления (с расширением): ";
    std::cin >> name;

    if (remove((path + name).c_str()) == 0)
    {
        std::cout << "Удалено.\n";
    }
    else
    {
        perror("Ошибка");
    }
}

void FileManager::run()
{
    std::string cmd;
    printHelp();
    while (true)
    {
        std::cout << ">";
        std::cin >> cmd;
        if (cmd == "exit")
        {
            break;
        }
        else if (cmd == "add")
        {
            addFile();
        }
        else if (cmd == "rename")
        {
            renameFile();
        }
        else if (cmd == "copy")
        {
            copyFile();
        }
        else if (cmd == "size")
        {
            getFileSize();
        }
        else if (cmd == "delete")
        {
            deleteFile();
        }
        else if (cmd == "help")
        {
            printHelp();
        }
    }
}
