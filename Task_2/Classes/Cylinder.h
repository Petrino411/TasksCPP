#pragma once
#include "Point.h"

class Cylinder
{
    Point center;
    double radius;
    double height;

public:
    Cylinder();
    Cylinder(Point& p, double& r, double& h);
    double volume() const;
    bool isInside(Point p);
    friend std::ostream& operator<<(std::ostream& os, const Cylinder& cylinder);
    void input();
};
