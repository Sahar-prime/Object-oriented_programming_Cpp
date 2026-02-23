#include "FileMessenger.h"

FileMessenger::FileMessenger() 
{
    path = "C:\\Users\\user\\Рабочий стол\\User\\";
    // Создаем базовую директорию, если её нет
    system("mkdir \"C:\\Users\\user\\Рабочий стол\\User\" 2> nul");
}

// Проверка типа объекта через _findfirst из <io.h>
bool FileMessenger::isDirectory(const std::string& fullPath)
{
    _finddata_t fileInfo;
    intptr_t handle = _findfirst(fullPath.c_str(), &fileInfo);
    if (handle != -1L) 
    {
        bool res = (fileInfo.attrib & _A_SUBDIR); // Проверка бита директории
        _findclose(handle);
        return res;
    }
    return false;
}

void FileMessenger::addAny()
{
    int choice;
    std::cout << "1 - Файл, 2 - Папка: ";
    std::cin >> choice;
    std::string name;
    std::cout << "Имя: ";
    std::cin >> name;

    if (choice == 1)
    {
        std::string ext, buf;
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
            std::cout << "Файл создан.\n";
        }
    }
    else {
        system(("mkdir \"" + path + name + "\"").c_str());
        std::cout << "Папка создана.\n";
    }
}

void FileMessenger::renameAny()
{
    std::string oldName, newName;
    std::cout << "Имя объекта (с расширением): ";
    std::cin >> oldName;
    std::cout << "Новое имя/путь: ";
    std::cin >> newName;

    // rename() в C работает и для файлов, и для папок
    if (rename((path + oldName).c_str(), (path + newName).c_str()) == 0)
        std::cout << "Успешно перемещено/переименовано.\n";
    else
        perror("Ошибка");
}

void FileMessenger::copyAny()
{
    std::string src, dst;
    std::cout << "Что копируем (имя): ";
    std::cin >> src;
    std::cout << "Имя копии: ";
    std::cin >> dst;

    std::string srcPath = path + src;
    std::string dstPath = path + dst;

    if (isDirectory(srcPath))
    {
        // Для папок используем системный xcopy (рекурсивно)
        std::string cmd = "xcopy \"" + srcPath + "\" \"" + dstPath + "\" /E /I /H /Y > nul";
        system(cmd.c_str());
        std::cout << "Папка скопирована.\n";
    }
    else
    {
        FILE* s = fopen(srcPath.c_str(), "rb"), * d = fopen(dstPath.c_str(), "wb");
        if (!s || !d) { std::cout << "Ошибка доступа.\n"; if (s) fclose(s); return; }
        char buffer[4096]; size_t n;
        while ((n = fread(buffer, 1, sizeof(buffer), s)) > 0) fwrite(buffer, 1, n, d);
        fclose(s); fclose(d);
        std::cout << "Файл скопирован.\n";
    }
}

long long FileMessenger::calculateDirSize(const std::string& dirPath)
{
    long long totalSize = 0;
    _finddata_t info;
    intptr_t h = _findfirst((dirPath + "\\*").c_str(), &info);
    if (h != -1L) 
    {
        do
        {
            std::string n = info.name;
            if (n != "." && n != "..") 
            {
                if (info.attrib & _A_SUBDIR)
                    totalSize += calculateDirSize(dirPath + "\\" + n);
                else
                    totalSize += info.size;
            }
        } while (_findnext(h, &info) == 0);
        _findclose(h);
    }
    return totalSize;
}

void FileMessenger::sizeAny()
{
    std::string name;
    std::cout << "Имя объекта: ";
    std::cin >> name;
    std::string fullPath = path + name;

    if (isDirectory(fullPath))
        std::cout << "Размер папки: " << calculateDirSize(fullPath) << " байт\n";
    else
    {
        _finddata_t info;
        intptr_t h = _findfirst(fullPath.c_str(), &info);
        if (h != -1L)
        {
            std::cout << "Размер файла: " << info.size << " байт\n";
            _findclose(h);
        }
        else perror("Ошибка");
    }
}

void FileMessenger::deleteAny() 
{
    std::string name;
    std::cout << "Удалить (имя): ";
    std::cin >> name;
    std::string fullPath = path + name;

    if (isDirectory(fullPath))
    {
        // /s - подпапки, /q - без подтверждения
        system(("rd /s /q \"" + fullPath + "\"").c_str());
        std::cout << "Папка удалена.\n";
    }
    else 
    {
        if (remove(fullPath.c_str()) == 0) std::cout << "Файл удален.\n";
        else perror("Ошибка");
    }
}

void FileMessenger::findFilesRecursive(const std::string& curr, const std::string& mask)
{
    _finddata_t info;
    // 1. Ищем файлы по маске в текущей папке
    intptr_t h = _findfirst((curr + "\\" + mask).c_str(), &info);
    if (h != -1L)
    {
        do
        {
            if (!(info.attrib & _A_SUBDIR))
                std::cout << "Найдено: " << curr << "\\" << info.name << "\n";
        } while (_findnext(h, &info) == 0);
        _findclose(h);
    }
    // 2. Рекурсивно идем вглубь
    h = _findfirst((curr + "\\*").c_str(), &info);
    if (h != -1L)
    {
        do 
        {
            std::string n = info.name;
            if ((info.attrib & _A_SUBDIR) && n != "." && n != "..")
                findFilesRecursive(curr + "\\" + n, mask);
        } while (_findnext(h, &info) == 0);
        _findclose(h);
    }
}

void FileMessenger::searchMask() 
{
    std::string mask;
    std::cout << "Введите маску (напр. *.txt): ";
    std::cin >> mask;
    findFilesRecursive(path, mask);
}

//void FileMessenger::showContent() 
//{
//    std::cout << "Содержимое папки User:\n";
//    system(("dir \"" + path + "\" /b").c_str());
//}

void FileMessenger::printHelp() 
{
    std::cout << "Команды: add, rename, move, copy, size, delete, search, exit\n";
}

void FileMessenger::run() 
{
    std::string cmd;
    printHelp();
    while (true)
    {
        std::cout << ">";
        if (!(std::cin >> cmd)) break;
        if (cmd == "exit") break;
        else if (cmd == "add") addAny();
        else if (cmd == "rename" || cmd == "move") renameAny();
        else if (cmd == "copy") copyAny();
        else if (cmd == "size") sizeAny();
        else if (cmd == "delete") deleteAny();
        else if (cmd == "search") searchMask();
        else printHelp();
    }
}