#pragma once
#include <iostream>
class Complex 
{
    double real;
    double imag;

public:
    // Конструкторы
    Complex(); // Конструктор по умолчанию
    Complex(double r); // Конструктор с одним параметром (действительная часть)
    Complex(double r, double i); // Конструктор с двумя параметрами
    Complex(const Complex& other); //Конструктор копирования

    Complex operator+(const Complex& other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }
    Complex operator-(const Complex& other) const 
    {
        return Complex(real - other.real, imag - other.imag);
    }
    Complex operator*(const Complex& other) const
    {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }
    Complex operator/(const Complex& other) const
    {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0)
            throw std::runtime_error("Деление на ноль!");

        return Complex(
            (real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator 
        );
    }

    bool operator==(const Complex& other) const 
    {
        return (real == other.real) && (imag == other.imag);
    }
    bool operator!=(const Complex& other) const
    {
        return !(*this == other);
    }

    // Дружественная перегрузка оператора << и >> для вывода и ввода
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};

inline std::ostream& operator<<(std::ostream& os, const Complex& c)
{
    os << c.real;
    if (c.imag >= 0) os << " + " << c.imag << "i";
    else os << " - " << -c.imag << "i";
    return os;
}
inline std::istream& operator>>(std::istream& is, Complex& c) 
{
    is >> c.real >> c.imag;
    return is;
}