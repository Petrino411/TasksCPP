#include "Point.h"
#include <cmath>
#include <iostream>
#include <limits>


Point::Point() : x(0.0), y(0.0), z(0.0)
{
}


Point::Point(const double x, const double y, const double z) : x(x), y(y), z(z)
{
}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

double Point::getZ() const
{
    return z;
}

void Point::input()
{
    std::cout << "Введите координаты точки (x y z): ";
    while (!(std::cin >> x >> y >> z))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода. Повторите ввод: ";
    }
}

bool operator==(const Point& point1, const Point& point2)
{
    return std::abs(point1.getX() - point2.getX()) <= std::numeric_limits<double>::epsilon()
        && std::abs(point1.getY() - point2.getY()) <= std::numeric_limits<double>::epsilon()
        && std::abs(point1.getZ() - point2.getZ()) <= std::numeric_limits<double>::epsilon();
}

bool operator!=(const Point& point1, const Point& point2)
{
    return !(point1 == point2);
}

std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << "Точка: (" << point.getX() << ", " << point.getY() << ", " << point.getZ() << ")";
    return os;
}
