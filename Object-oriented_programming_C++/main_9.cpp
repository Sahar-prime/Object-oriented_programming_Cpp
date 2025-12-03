#include <iostream>
#include "Time.h"

//#define MAIN_9

#ifdef MAIN_9
int main() 
{
    Time t1(10, 59, 59);
    Time t2(10, 0, 0);

    std::cout << "t1: " << t1 << std::endl;
    std::cout << "t2: " << t2 << std::endl;

    t1.incrementSecond();
    std::cout << "t1 + 1 second: " << t1 << std::endl;

    ++t1;
    std::cout << "++t1: " << t1 << std::endl;

    t1--;
    std::cout << "t1--: " << t1 << std::endl;

    if (t1 != t2) 
    {
        std::cout<< t1 << " != " << t2 << std::endl;
    }
    else
    {
        std::cout << t1 << " = " << t2 << std::endl;
    }

    Time t3 = t1 - t2;
    std::cout << t3 << std::endl;
    Time t4 = t1 + t2;
    std::cout << t4 << std::endl;

    Time t5;
    std::cin >> t5;
    std::cout << t5 << std::endl;
    t5 += t1;
    std::cout << t5 << std::endl;

    if (t5 > t2)
    {
        std::cout << t5 << " > " << t2 << std::endl;
    }
    else
    {
        std::cout << t5 << " < " << t2 << std::endl;
    }

    Time t6(t5);
    std::cout << t6 << std::endl;
}
#endif //MAIN_9