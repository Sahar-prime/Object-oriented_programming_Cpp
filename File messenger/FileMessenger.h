#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <io.h>
#include <direct.h>

class FileMessenger
{
private:
    std::string path;

    void printHelp();
    void addFile();
    void renameFile();
    void copyFile();
    void getFileSize();
    void deleteFile();
    void showUserFolderContent();
public:
    FileMessenger();
    void run();
};
