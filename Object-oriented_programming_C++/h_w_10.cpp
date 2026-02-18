#include <iostream>
#include <vector>

//#define H_W_10

#ifdef H_W_10
int main()
{
    std::vector<int> squares;
    for (int i = 0; i < 11; ++i) 
    {
        squares.push_back(i * i);
    }
    for (int num : squares)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
#endif //H_W_10