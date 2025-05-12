#include <iostream>
#include "Cylinder.h"
#include "Point.h"
#include <limits>

/**
 * @brief Функция для ввода точки.
 * @return Точка, введённая пользователем.
 */
Point inputPoint();

/**
 * @brief Функция для ввода цилиндра.
 * @return Цилиндр, введённый пользователем.
 */
Cylinder inputCylinder();

/**
* @brief Главная функция программы.
* @param argc Количество аргументов командной строки.
* @param argv Массив аргументов командной строки.
* @return Код завершения программы (0 в случае успеха).
*/
int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "rus");

    auto cylinder = inputCylinder();
    std::cout << cylinder << '\n';
    auto point = inputPoint();
    std::cout << point << '\n';

    if (cylinder.isInside(point)) {
        std::cout << "\nТочка находится внутри цилиндра.\n";
    } else {
        std::cout << "\nТочка находится вне цилиндра.\n";
    }

    return 0;

}


Point inputPoint() {
    double x = 0, y = 0, z = 0;
    std::cout << "Введите координаты точки (x y z): ";
    while (!(std::cin >> x >> y >> z)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода. Повторите ввод: ";
    }
    return {x, y, z};


}

Cylinder inputCylinder() {
    std::cout << "Введите данные для цилиндра:\n";
    auto p = inputPoint();
    double radius = 0, height = 0;


    std::cout << "Введите радиус цилиндра: ";
    while (!(std::cin >> radius) || radius <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка: радиус должен быть положительным числом. Повторите ввод: ";
    }

    std::cout << "Введите высоту цилиндра: ";
    while (!(std::cin >> height) || height <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка: высота должна быть положительным числом. Повторите ввод: ";
    }

    return Cylinder(p, radius, height);
}


