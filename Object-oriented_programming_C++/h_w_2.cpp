#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//#define H_W_2

// Класс для хранения данных об абоненте
class Abonent 
{
    char* fullName;      // ФИО (динамическая память)
    char* homePhone;     // Домашний телефон (динамическая память)
    char* contactInfo;   // Информация о контакте (динамическая память)

    // Внутренний метод для безопасного копирования строк
    void copyString(char*& dest, const char* src) 
    {
        if (src == nullptr) 
        {
            dest = nullptr;
            return;
        }
        dest = new char[strlen(src) + 1];
        strcpy(dest, src);
    }

public:
    // Конструктор по умолчанию
    Abonent() : fullName(nullptr), homePhone(nullptr), contactInfo(nullptr) {}

    // Конструктор с параметрами
    Abonent(const char* name, const char* phone, const char* info)
    {
        copyString(fullName, name);
        copyString(homePhone, phone);
        copyString(contactInfo, info);
    }

    // Деструктор
    ~Abonent() 
    {
        delete[] fullName;
        delete[] homePhone;
        delete[] contactInfo;
    }

    // Метод для установки ФИО
    void setFullName(const char* name)
    {
        delete[] fullName;
        copyString(fullName, name);
    }

    // Метод для установки домашнего телефона
    void setHomePhone(const char* phone) 
    {
        delete[] homePhone;
        copyString(homePhone, phone);
    }

    // Метод для установки информации о контакте
    void setContactInfo(const char* info) 
    {
        delete[] contactInfo;
        copyString(contactInfo, info);
    }

    // Метод для получения ФИО
    const char* getFullName() const 
    {
        return fullName ? fullName : "Не указано";
    }

    // Метод для получения домашнего телефона
    const char* getHomePhone() const
    {
        return homePhone ? homePhone : "Не указан";
    }

    // Метод для получения информации о контакте
    const char* getContactInfo() const
    {
        return contactInfo ? contactInfo : "Отсутствует";
    }

    // Метод для вывода информации об абоненте
    void show() const 
    {
        std::cout << "ФИО: " << getFullName() << std::endl;
        std::cout << "Домашний телефон: " << getHomePhone() << std::endl;
        std::cout << "Информация о контакте: " << getContactInfo() << std::endl;
    }
};

#ifdef H_W_2
int main() 
{
    setlocale(LC_ALL, "");

    // Пример использования
    Abonent abonent("Иванов Иван Иванович", "+7 (123) 456-78-90", "Друг");

    // Вывод информации об абоненте
    abonent.show();

    // Изменение данных
    abonent.setFullName("Петров Петр Петрович");
    abonent.setHomePhone("+7 (987) 654-32-10");
    abonent.setContactInfo("Коллега");

    // Вывод обновленной информации
    abonent.show();
}
#endif //H_W_2