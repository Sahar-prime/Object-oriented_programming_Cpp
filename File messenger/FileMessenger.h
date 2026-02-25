#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <io.h>

class FileMessenger
{
private:
    std::string path;

    // Вспомогательные методы
    bool isDirectory(const std::string& fullPath);
    long long calculateDirSize(const std::string& dirPath);
    void findFilesRecursive(const std::string& currentPath, const std::string& mask);

    // Основная логика
    void printHelp();
    void addAny();
    void renameAny();
    void copyAny();
    void sizeAny();
    void showFilesContent(const std::string& currentPath = "", int level = 0);
    void deleteAny();
    void searchMask();
public:
    FileMessenger();
    void run();
};
