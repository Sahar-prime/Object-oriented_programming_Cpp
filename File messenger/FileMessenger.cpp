#include "FileMessenger.h"

FileMessenger::FileMessenger()
{
    path = "C:\\Users\\user\\Рабочий стол\\User\\";
    system("mkdir \"C:\\Users\\user\\Рабочий стол\\User\" 2> nul");
}

void FileMessenger::printHelp()
{
    std::cout << "Все команды: add, rename, copy, size, delete, show, show_all, exit" << std::endl;
}

void FileMessenger::addFile()
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

void FileMessenger::renameFile()
{
    std::string name, newName, newExt;
    std::cout << "Имя файла для переименования (с расширением): ";
    std::cin >> name;
    std::string oldFullPath = path + name;
    
    // Проверка существования файла через fopen
    FILE* file = fopen(oldFullPath.c_str(), "r");
    if (!file)
    {
        std::cerr << "Ошибка: файл не существует или недоступен.\n";
        return;
    }
    fclose(file);
    
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

void FileMessenger::copyFile()
{
    std::string name, target;
    std::cout << "Файл (с расширением): ";
    std::cin >> name;

    std::string sourcePath = path + name;
    FILE* source = fopen(sourcePath.c_str(), "rb");
    if (!source)
    {
        std::cerr << "Ошибка: файл не существует или недоступен.\n";
        return;
    }

    // Определяем расширение
    size_t dotPos = name.find_last_of('.');
    if (dotPos == std::string::npos)
    {
        std::cerr << "Ошибка: неверный формат имени файла.\n";
        fclose(source);
        return;
    }
    std::string ext = name.substr(dotPos);

    std::cout << "Новое имя файла (без расширения): ";
    std::cin >> target;
    std::string destPath = path + target + ext;

    // Копирование
    FILE* dest = fopen(destPath.c_str(), "wb");
    if (!dest)
    {
        std::cerr << "Ошибка: не удалось создать копию.\n";
        fclose(source);
        return;
    }

    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source)) > 0)
    {
        fwrite(buffer, 1, bytesRead, dest);
    }

    fclose(source);
    fclose(dest);
    std::cout << "Файл скопирован как: " << target << ext << "\n";
}

void FileMessenger::getFileSize()
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

void FileMessenger::deleteFile()
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

void FileMessenger::run()
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
        else if (cmd == "show_all") 
        {
            showUserFolderContent();
        }
        else if (cmd == "help")
        {
            printHelp();
        }
    }
}

void FileMessenger::showUserFolderContent()
{
    std::cout << "Список файлов в папке User:\n";
    std::string command = "dir \"" + path + "\" /b";
    system(command.c_str());
}
