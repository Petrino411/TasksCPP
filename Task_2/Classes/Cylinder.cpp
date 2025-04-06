#include "Cylinder.h"
#include <iostream>
#include <numbers>
#include <sstream>


Cylinder::Cylinder()
{
}

Cylinder::Cylinder(Point& p, double& r, double& h):
    center{p}, radius{r}, height{h}
{
}

double Cylinder::volume() const
{
    return std::numbers::pi * radius * radius * radius;
}

bool Cylinder::isInside(Point p)
{
    double dx = p.getX() - center.getX();
    double dy = p.getY() - center.getY();
    double distanceSquared = dx * dx + dy * dy;

    return distanceSquared <= (radius * radius);
}

std::ostream& operator<<(std::ostream& os, const Cylinder& cylinder) {
    os << "Цилиндр:\n"
       << "  Центр основания: " << cylinder.center << "\n"
       << "  Радиус: " << cylinder.radius << "\n"
       << "  Высота: " << cylinder.height;
    return os;
}

void Cylinder::input()
{
    auto c = Point();
    c.input();
    center = c;

    std::cout << "Введите радиус цилиндра: ";
    std::cin >> radius;

    std::cout << "Введите высоту цилиндра: ";
    std::cin >> height;
}
