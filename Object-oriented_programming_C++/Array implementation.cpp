#include <iostream>
#include "Array_01.h"

//#define MAIN

void show(const Array_01& a) 
{
    for (int i = 0; i < a.getSize(); i++) 
    {
        std::cout << a.getElem(i) << " ";
    }
    std::cout << std::endl;
}

#ifdef MAIN
int main() 
{
    setlocale(LC_ALL, "");
    Array_01 def;
    def.print();

    Array_01 a(5);
    a.randomize(5, 10).print(); 

    Array_01 b = a;
    b.print();

    a.setElem(2, 100).print();
    a.getElem(2);

    Array_01 c;
    c.randomize(1, 15).sortArr().reSize(6).print();

    Array_01 g (5);
    show(g);

    show(Array_01{5});

    Array_01 aaa, bbb;
    aaa.randomize(5, 54);
    bbb.randomize(5, 33);
    std::cout << aaa + bbb << std::endl;
    std::cout << aaa * 2 << std::endl;

    Array_01 ccc;
    ccc.randomize(5, 10);
    ++ccc;
    std::cout << ccc << std::endl;
    --ccc;
    std::cout << ccc << std::endl;

    Array_01 ddd(5);
    ddd.randomize(1, 10);
    std::cout << "Array ddd: " << ddd << std::endl;
    ddd += 2;
    std::cout << "After a += b: " << ddd << std::endl;

    Array_01 mmm(4);
    mmm.randomize(1, 10);
    std::cout << "Array mmm: " << mmm << std::endl;
    mmm -= 1;
    std::cout << "After a -= b: " << mmm << std::endl;

    Array_01 hhh(4);
    hhh.randomize(1, 10);
    std::cout << "Array ggg: " << hhh << std::endl;
    hhh *= 2;
    std::cout << "After a *= b: " << hhh << std::endl;

    Array_01 ggg(4);
    ggg.randomize(1, 10);
    std::cout << "Array ggg: " << ggg << std::endl;
    ggg /= 2;
    std::cout << "After a /= b: " << ggg << std::endl;

    if (mmm > ggg) 
    {
        std::cout << mmm << "> " << ggg << std::endl;
    }
    else 
    {
        std::cout << mmm << "< " << ggg << std::endl;
    }

    if (ggg < hhh)
    {
        std::cout<< ggg << "< " << hhh << std::endl;
    }
    else
    {
        std::cout<< ggg << "> " << hhh << std::endl;
    }

    Array_01 zzz(5), xxx(5);
    if (zzz == xxx)
    {
        std::cout << zzz << "= " << xxx << std::endl;
    }
    else
    {
        std::cout << zzz << "!= " << xxx << std::endl;
    }

    if (ggg != hhh)
    {
        std::cout << ggg << "!= " << hhh << std::endl;
    }
    else
    {
        std::cout << ggg << "= " << hhh << std::endl;
    }

    Array_01 uuu, jjj;
    uuu.randomize(5, 16);
    std::cout << uuu << std::endl;
    jjj = uuu;
    std::cout << jjj << std::endl;

    Array_01 a1{ 10 };
    a1.randomize(0, 9).print();
    Array_01 a2{ a1 }; //копия
    a1.print();
    a2.print();
    Array_01 a3{ std::move(a2) }; //переместить
    a2.print();
    a3.print();

    a1 = a2; //копр.
    a2 = std::move(a3); //перемещ.
    std::cout << a1.getElem(5) << std::endl;
    a1.setElem(4, 2);
}
#endif //MAIN