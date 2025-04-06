#include "Point.h"
#include <cmath>
#include <iostream>
#include <limits>

Point::Point(){}

Point::Point(double x = 0.0, double y = 0.0, double z = 0.0) : x(x), y(y), z(z)
{
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

void Point::input() {
    std::cout << "Введите координаты точки (x y z): ";
    std::cin >> x >> y >> z;
}

bool Point::operator==(const Point& point1, const Point& point2)
{
    return true;
}

bool Point::operator!=(const Point& point1, const Point& point2)
{
    return !(point1 == point2);
}

std::ostream& Point::operator<<(std::ostream& os, const Point& point)
{
    os << "Точка: (" << point.getX() << ", " << point.getY() << ", " << point.getZ() << ")";
    return os;
}
