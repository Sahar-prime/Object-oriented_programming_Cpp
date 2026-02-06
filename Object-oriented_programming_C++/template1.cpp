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

template <class T>
class Point 
{
private:
    T x;
    T y;
public:
    Point(T x, T y) : x(x), y(y) {}
    T getX() const
    {
        return x;
    }
    T getY() const 
    {
        return y; 
    }
    void setX(T newX) 
    { 
        x = newX; 
    }
    void setY(T newY)
    {
        y = newY;
    }
    void show() const
    {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};
template <class T>
class Shape
{
protected:
    Point<T> start;
public:
    Shape(Point<T> start) : start(start) {}
    virtual void show() const = 0;
};
template <class T, class T2, class T3>
class Rectangle : public Shape<T>
{
private:
    T2 width;
    T3 height;
public:
    Rectangle(Point<T> start, T2 width, T3 height) : Shape<T>(start), width(width), height(height) {}
    void show() const
    {
        std::cout << "Rectangle with width " << width << " and height " << height << " starts at: ";
        this->start.show();
    }
    T2 getWidth() const
    {
        return width;
    }
    T3 getHeight() const
    {
        return height;
    }
    void setWidth(T newWidth)
    {
        width = newWidth;
    }
    void setHeight(T newHeight)
    {
        height = newHeight;
    }
};
template <class T, class T2>
class Square : public Rectangle<T, T2, T2>
{
public:
    Square(Point<T> start, T2 side) :
        Rectangle<T, T2, T2>(start, side, side) {}
    void show() const
    {
        std::cout << "Square with side " << this->getWidth() << " starts at: ";
        this->start.show();
    }
    void setWidth(T2 newSide)
    {
        this->Rectangle<T, T2, T2>::setWidth(newSide);
        this->Rectangle<T, T2, T2>::setHeight(newSide);
    }
    void setHeight(T2 newSide)
    {
        this->Rectangle<T, T2, T2>::setWidth(newSide);
        this->Rectangle<T, T2, T2>::setHeight(newSide);
    }
};
template <class T, class T2, class T3>
class Ellipse : public Shape<T>
{
private:
    T2 semiMajorAxis;
    T3 semiMinorAxis;
public:
    Ellipse(Point<T> start, T2 semiMajorAxis, T3 semiMinorAxis) :
        Shape<T>(start),
        semiMajorAxis(semiMajorAxis),
        semiMinorAxis(semiMinorAxis) {}
    void show() const
    {
        std::cout << "Ellipse with semi-major axis " << semiMajorAxis
            << " and semi-minor axis " << semiMinorAxis << " starts at: ";
        this->start.show();
    }
    T2 getSemiMajorAxis() const 
    {
        return semiMajorAxis;
    }
    T3 getSemiMinorAxis() const 
    {
        return semiMinorAxis;
    }
    void setSemiMajorAxis(T2 newSemiMajorAxis) 
    { 
        semiMajorAxis = newSemiMajorAxis; 
    }
    void setSemiMinorAxis(T3 newSemiMinorAxis) 
    {
        semiMinorAxis = newSemiMinorAxis; 
    }
};
template <class T, class T2>
class Circle : public Ellipse<T, T2, T2>
{
public:
    Circle(Point<T> start, T2 radius) : 
        Ellipse<T, T2, T2>(start, radius, radius) {}
    void show() const 
    {
        std::cout << "Circle with radius " << this->getSemiMajorAxis() << " starts at: ";
        this->start.show();
    }
    void setSemiMajorAxis(T2 newRadius) 
    {
        this->Ellipse<T, T2, T2>::setSemiMajorAxis(newRadius);
        this->Ellipse<T, T2, T2>::setSemiMinorAxis(newRadius);
    }
    void setSemiMinorAxis(T2 newRadius) 
    {
        this->Ellipse<T, T2, T2>::setSemiMajorAxis(newRadius);
        this->Ellipse<T, T2, T2>::setSemiMinorAxis(newRadius);
    }
};

#ifdef MAIN
int main()
{
//Pair->Trio
    Pair<int, std::string> pair(1, "Apple");
    pair.show();
    Trio<int, std::string, double> trio(2, "Orange", 3.14);
    trio.show();
//base->child->child2
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
    std::cout << std::endl;
//Point->Shape:
  //-Rectangle->Square
  //-Ellipse->Circle
    Point<int> p1(10, 20);
    // Прямоугольник и Квадрат
    Rectangle<int, int, int> rect(p1, 100, 50);
    rect.show();
    Square<int, int> sq(p1, 40);
    sq.show();
    sq.setWidth(60); // Обновит и ширину, и высоту
    sq.show();
    // Эллипс и Круг
    Ellipse<int, double, double> ell(p1, 15.5, 10.0);
    ell.show();
    Circle<int, double> circ(p1, 25.0);
    circ.show();
    circ.setSemiMajorAxis(30.0); // Обновит радиус
    circ.show();
}
#endif //MAIN