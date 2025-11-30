#pragma once
class Overcoat
{
    char* type;  // Тип одежды (например, "пальто", "куртка")
    double price; // Цена
public:
    // Конструкторы
    Overcoat();
    Overcoat(const char* type, double price);

    // Деструктор
    ~Overcoat();

    // Перегруженные операторы
    bool operator==(const Overcoat& other) const;
    Overcoat& operator=(const Overcoat& other);
    bool operator>(const Overcoat& other) const;

    // Геттеры
    const char* getType() const;
    double getPrice() const;
};