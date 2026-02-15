#include "FileMessenger.h"

//#define MAIN

#ifdef MAIN
int main()
{
    setlocale(LC_ALL, "");

    FileMessenger manager;
    manager.run();
    return 0;
}
#endif //MAIN