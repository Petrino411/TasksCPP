#include "Cylinder.h"
#include <iostream>
#include <limits>


using namespace std;


constexpr double PI = 3.14159265358979323846;// в стандарте с++ 17 больше никак, с 20 пришлось переехать.

Cylinder::Cylinder(const Point& p, const double& r, const double& h)
{
    if (r <= 0 || h <= 0)
    {
        throw std::invalid_argument("Радиус и высота цилиндра должны быть положительными числами.");
    }
    center = p;
    radius = r;
    height = h;
}

double Cylinder::volume() const
{
    return PI * radius * radius * height;
}

bool Cylinder::isInside(const Point& p) const
{
    double dx = p.getX() - center.getX();
    double dy = p.getY() - center.getY();
    double dz = p.getZ() - center.getZ();
    bool withinHeight = (dz >= 0) && (dz <= height);
    bool withinCircle = (dx * dx + dy * dy) <= (radius * radius);
    return withinCircle && withinHeight;
}


std::ostream& operator<<(std::ostream& os, const Cylinder& cylinder)
{
    os << "Цилиндр:\n"
        << "  Центр основания: " << cylinder.center << "\n"
        << "  Радиус: " << cylinder.radius << "\n"
        << "  Высота: " << cylinder.height << '\n'
        << "  Объем: " << cylinder.volume() << '\n';
    return os;
}

void Cylinder::input()
{
    auto c = Point();
    c.input();
    center = c;

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
}
