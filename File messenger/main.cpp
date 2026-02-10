#define _CRT_SECURE_NO_WARNINGS
#include "FileMessenger.h"

//#define MAIN

#ifdef MAIN
int main()
{
    setlocale(LC_ALL, "");

    FileManager manager;
    manager.run();
    return 0;
}
#endif //MAIN