#include <iostream>
#include "Array.h"

//#define MAIN

void show(const Array& a) 
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

    Array aaa, bbb;
    aaa.randomize(5, 54);
    bbb.randomize(5, 33);
    std::cout << aaa + bbb << std::endl;
    std::cout << aaa * 2 << std::endl;

    Array ccc;
    ccc.randomize(5, 10);
    ++ccc;
    std::cout << ccc << std::endl;
    --ccc;
    std::cout << ccc << std::endl;

    Array ddd(5);
    ddd.randomize(1, 10);
    std::cout << "Array ddd: " << ddd << std::endl;
    ddd += 2;
    std::cout << "After a += b: " << ddd << std::endl;

    Array mmm(4);
    mmm.randomize(1, 10);
    std::cout << "Array mmm: " << mmm << std::endl;
    mmm -= 1;
    std::cout << "After a -= b: " << mmm << std::endl;

    Array hhh(4);
    hhh.randomize(1, 10);
    std::cout << "Array ggg: " << hhh << std::endl;
    hhh *= 2;
    std::cout << "After a *= b: " << hhh << std::endl;

    Array ggg(4);
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

    Array zzz(5), xxx(5);
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

    Array uuu, jjj;
    uuu.randomize(5, 16);
    std::cout << uuu << std::endl;
    jjj = uuu;
    std::cout << jjj << std::endl;

    Array a1{ 10 };
    a1.randomize(0, 9).print();
    Array a2{ a1 }; //копия
    a1.print();
    a2.print();
    Array a3{ std::move(a2) }; //переместить
    a2.print();
    a3.print();

    a1 = a2; //копр.
    a2 = std::move(a3); //перемещ.
    std::cout << a1.getElem(5) << std::endl;
    a1.setElem(4, 2);
}
#endif //MAIN