#include <iostream>
#include "Array.h"

//#define MAIN_5

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
}
#endif //MAIN_5