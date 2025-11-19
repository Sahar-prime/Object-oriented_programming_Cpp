#include <iostream>
#include "Array.h"

//#define MAIN_5

void show(const Array& a) 
{
    for (int i = 0; i < a.getSize(); i++) 
    {
        std::cout << a.getElem(i) << " ";
    }
    std::cout << std::endl;
}

#ifdef MAIN_5
int main() 
{
    setlocale(LC_ALL, "");
    Array def;
    def.print();

    Array a(5); 
    a.randomize(5, 10).print(); 

    Array b = a;
    b.print();

    a.setElem(2, 100).print();
    a.getElem(2);

    Array c;
    c.randomize(1, 15).sortArr().reSize(6).print();

    Array g (5);
    show(g);

    show(Array{5});
}
#endif //MAIN_5
