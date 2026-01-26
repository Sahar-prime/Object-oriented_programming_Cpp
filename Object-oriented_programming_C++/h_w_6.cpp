#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//#define H_W_6

class Engine
{
protected:
    double volume;  
    char fuelType[50]; 
public:
    Engine(double v, const char* ft) : volume(v) 
    {
        strcpy(fuelType, ft);
    }
    void setVolume(double v) 
    {
        volume = v;
    }
    void setFuelType(const char* ft) 
    {
        strcpy(fuelType, ft);
    }
    double getVolume() const 
    {
        return volume;
    }
    const char* getFuelType() const 
    {
        return fuelType;
    }
    void printInfo() const 
    {
        std::cout << "Двигатель: Объем = " << volume << " л, Вид бензина = " << fuelType << std::endl;
    }
};
class Body
{
protected:
    char color[50];    
    int seatCount;    

public:
    Body(const char* c, int sc) : seatCount(sc)
    {
        strcpy(color, c);
    }
    void setColor(const char* c)
    {
        strcpy(color, c);
    }
    void setSeatCount(int sc)
    {
        seatCount = sc;
    }
    const char* getColor() const
    {
        return color;
    }
    int getSeatCount() const 
    {
        return seatCount;
    }
    void printInfo() const 
    {
        std::cout << "Корпус: Цвет = " << color << ", Количество мест = " << seatCount << std::endl;
    }
};
class Car : public Engine, public Body 
{
private:
    char brand[50];  
public:
    Car(const char* b, double v, const char* ft,
        const char* c, int sc)
        : Engine(v, ft), Body(c, sc)
    {
        strcpy(brand, b);
    }
    void setBrand(const char* b)
    { 
        strcpy(brand, b);
    }
    const char* getBrand() const
    {
        return brand; 
    }
    void printInfo() const 
    {
        std::cout << "Машина: Марка = " << brand << std::endl;
        Engine::printInfo();
        Body::printInfo();
    }
};

#ifdef H_W_6
int main()
{
    setlocale(LC_ALL, "");
    Car myCar("Toyota", 2.0, "АИ-95", "Красный", 5);
    myCar.printInfo();
}
#endif //H_W_6