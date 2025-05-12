#include <iostream>
#include "Cylinder.h"
#include "Point.h"


/**
 * @brief Главная функция программы.
 * @param argc Количество аргументов командной строки.
 * @param argv Массив аргументов командной строки.
 * @return Код завершения программы (0 в случае успеха).
 */
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus");
    Cylinder cylinder;
    std::cout << "Введите данные для цилиндра:\n";
    cylinder.input();
    std::cout << cylinder << '\n';
    
    Point point;
    std::cout << "\nВведите данные для точки:\n";
    point.input();
    std::cout << point << '\n';

    if (cylinder.isInside(point)) {
        std::cout << "\nТочка находится внутри цилиндра.\n";
    } else {
        std::cout << "\nТочка находится вне цилиндра.\n";
    }

    return 0;
    
 
}
