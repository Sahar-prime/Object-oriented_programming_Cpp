#include <iostream>
#include "Worker.h"

//#define H_W_3

#ifdef H_W_3
int main() 
{
    setlocale(LC_ALL, "");
    // Пример использования
    Worker workers[] = {
        Worker("Иванов Иван Иванович", "Инженер", 2010, 50000),
        Worker("Петров Петр Петрович", "Менеджер", 2015, 60000),
        Worker("Сидоров Сидор Сидорович", "Инженер", 2020, 55000),
    };
    int size = sizeof(workers) / sizeof(workers[0]);

    // Вывод информации о всех работниках
    for (int i = 0; i < size; ++i) {
        workers[i].displayInfo();
    }

    // Примеры использования статических функций
    Worker::displayWorkersWithExperience(workers, size, 5, 2025);
    Worker::displayWorkersWithSalary(workers, size, 52000);
    Worker::displayWorkersByPosition(workers, size, "Инженер");
}
#endif //H_W_3