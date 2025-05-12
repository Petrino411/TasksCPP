#include "Cylinder.h"
#include <iostream>
#include <limits>


using namespace std;


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

Point Cylinder::getCenter() {
    return center;
}

double Cylinder::getRadius() {
    return radius;
}

double Cylinder::getHeight() {
    return height;
}


double Cylinder::volume() const
{
    return std::numbers::pi * radius * radius * height;
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

