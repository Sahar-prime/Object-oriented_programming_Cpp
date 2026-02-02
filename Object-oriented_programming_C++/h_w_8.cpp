#include <iostream>

//#define H_W_8

// Абстрактный базовый класс
class Equation
{
public:
    virtual void roots(double* result, int& count) const = 0;
};
// Класс для линейных уравнений (ax + b = 0)
class LinearEquation : public Equation
{
private:
    double a;
    double b;
public:
    LinearEquation(double a, double b) : a(a), b(b) {}

    void roots(double* result, int& count) const
    {
        if (a == 0) 
        {
            if (b == 0) 
            {
                std::cout << "Уравнение имеет бесконечное количество решений." << std::endl;
                count = 0;
            }
            else 
            {
                std::cout << "Уравнение не имеет решений." << std::endl;
                count = 0;
            }
        }
        else
        {
            result[0] = -b / a;
            count = 1;
        }
    }
};
// Класс для квадратных уравнений (ax² + bx + c = 0)
class QuadraticEquation : public Equation
{
private:
    double a;
    double b;
    double c;
public:
    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

    void roots(double* result, int& count) const 
    {
        if (a == 0)
        {
            std::cout << "Это не квадратное уравнение." << std::endl;
            count = 0;
            return;
        }

        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0)
        {
            std::cout << "Уравнение не имеет действительных корней." << std::endl;
            count = 0;
        }
        else if (discriminant == 0) 
        {
            result[0] = -b / (2 * a);
            count = 1;
        }
        else 
        {
            double sqrt_discriminant = sqrt(discriminant);
            result[0] = (-b + sqrt_discriminant) / (2 * a);
            result[1] = (-b - sqrt_discriminant) / (2 * a);
            count = 2;
        }
    }
};

#ifdef H_W_8
int main() 
{
    setlocale(LC_ALL, "");

    double rootsArray[2];
    int rootsCount;

    LinearEquation linear(2, -4);
    linear.roots(rootsArray, rootsCount);
    if (rootsCount > 0) 
    {
        std::cout << "Корни линейного уравнения: ";
        for (int i = 0; i < rootsCount; ++i) {
            std::cout << rootsArray[i] << " ";
        }
        std::cout << std::endl;
    }
    QuadraticEquation quadratic(1, -3, 2);
    quadratic.roots(rootsArray, rootsCount);
    if (rootsCount > 0)
    {
        std::cout << "Корни квадратного уравнения: ";
        for (int i = 0; i < rootsCount; ++i)
        {
            std::cout << rootsArray[i] << " ";
        }
        std::cout << std::endl;
    }
}
#endif //H_W_8