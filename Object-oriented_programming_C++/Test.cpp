#include "String.h"

//#define TEST

#ifdef TEST
int main()
{
    // Примеры использования конструкторов
    String defaultString; // Строка длиной 80 символов
    defaultString.print();

    String customSizeString(20); // Строка длиной 20 символов
    customSizeString.print();

    String userString("Hello, World!"); // Строка, инициализированная пользователем
    userString.print();
}
#endif //TEST