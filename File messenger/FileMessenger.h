#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>

class FileManager
{
private:
    std::string path;

    void printHelp();
    void addFile();
    void renameFile();
    void copyFile();
    void getFileSize();
    void deleteFile();

public:
    FileManager();
    void run();
};
