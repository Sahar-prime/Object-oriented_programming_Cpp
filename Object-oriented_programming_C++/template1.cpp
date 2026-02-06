#include <iostream>

//#define MAIN

template <class T, class T2>
class Pair
{
protected:
	T a;
	T2 b;
public:
	Pair(T a, T2 b) : a{ a }, b{ b } {}
	void show() const 
	{
		std::cout << a << " " << b << std::endl;
	}
    void setA(T newValue)
    {
        a = newValue;
    }
    void setB(T2 newValue)
    {
        b = newValue;
    }
    T getA() const 
    { 
        return a; 
    }
    T2 getB() const 
    { 
        return b;
    }
};
template <class T, class T2, class T3>
class Trio : public Pair<T, T2>
{
	T3 c;
public:
	Trio(T a, T2 b, T3 c) : Pair<T, T2>{ a, b }, c{ c } {}
	void show() const 
	{
		std::cout << this->a << " " << this->b << " " << c << std::endl;
	}
    void setC(T3 newValue) 
    {
        c = newValue;
    }
    T3 getC() const
    {
        return c;
    }
};

template <class T1, class T2>
class base 
{
protected:
    T1 value1;
    T2 value2;
public:
    base(T1 v1, T2 v2) :
        value1(v1), value2(v2) {}
    void setValue1(T1 v1) 
    {
        value1 = v1;
    }
    void setValue1(T2 v2)
    {
        value2 = v2;
    }
    T1 getValue1()
    {
        return value1;
    }
    T2 getValue2()
    {
        return value2;
    }
    void show() const
    {
        std::cout << "value1: " << value1 << ", value2: " << value2 << std::endl;
    }
};
template <class T1, class T2, class T3, class T4>
class child : public base<T1, T2> 
{
protected:
    T3 value3;
    T4 value4;
public:
    child(T1 v1, T2 v2, T3 v3, T4 v4) : 
        base<T1, T2>(v1, v2), 
        value3(v3), value4(v4) {}
    void setValue3(T3 v3)
    {
        value3 = v3;
    }
    void setValue4(T4 v4)
    {
        value4 = v4;
    }
    T3 getValue3()
    {
        return value3;
    }
    T4 getValue4()
    {
        return value4;
    }
    void show() const
    {
        base<T1, T2>::show();
        std::cout << "value3: " << value3 << ", value4: " << value4 << std::endl;
    }
};
template <class T1, class T2, class T3, class T4, class T5, class T6>
class child2 : public child<T1, T2, T3, T4> 
{
protected:
    T5 value5;
    T6 value6;
public:
    child2(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6)
        : child<T1, T2, T3, T4>(v1, v2, v3, v4),
        value5(v5), 
        value6(v6) {}
    void setValue5(T5 v5)
    {
        value5 = v5;
    }
    void setValue6(T6 v6)
    {
        value6 = v6;
    }
    T5 getValue5()
    {
        return value5;
    }
    T6 getValue6()
    {
        return value6;
    }
    void show() const
    {
        child<T1, T2, T3, T4>::show();
        std::cout << "value5: " << value5 << ", value6: " << value6 << std::endl;
    }
};

#ifdef MAIN
int main()
{
    base<int, float> b(10, 20.5);
    std::cout << "Base class:" << std::endl;
    b.show();
    std::cout << std::endl;

    child<int, float, char, double> c(30, 40.5, 'A', 50.75);
    std::cout << "Child class:" << std::endl;
    c.show();
    std::cout << std::endl;

    child2<int, float, char, double, bool, std::string> c2(60, 70.5, 'B', 80.75, true, "Hello");
    std::cout << "Child2 class:" << std::endl;
    c2.show();
}
#endif //MAIN