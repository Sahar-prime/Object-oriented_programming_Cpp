#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <io.h>

//class FileMessenger
//{
//private:
//    std::string path;
//
//    void printHelp();
//    void addFile();
//    void renameFile();
//    void copyFile();
//    void getFileSize();
//    void deleteFile();
//    void showUserFolderContent();
//public:
//    FileMessenger();
//    void run();
//};

class FileMessenger
{
private:
    std::string path;

    // Вспомогательные методы (используют только <io.h>)
    bool isDirectory(const std::string& fullPath);
    long long calculateDirSize(const std::string& dirPath);
    void findFilesRecursive(const std::string& currentPath, const std::string& mask);

    // Основная логика
    void printHelp();
    void addAny();
    void renameAny();
    void copyAny();
    void sizeAny();
    void deleteAny();
    void searchMask();

public:
    FileMessenger();
    void run();
};