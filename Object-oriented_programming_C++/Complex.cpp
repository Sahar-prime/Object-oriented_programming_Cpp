#include "Complex.h"
#include <iostream>

Complex::Complex() : real(0), imag(0) {}
Complex::Complex(double r) : real(r), imag(0) {}
Complex::Complex(double r, double i) : real(r), imag(i) {}
Complex::Complex(const Complex& other) : real{ other.real }, imag{ other.imag } {}