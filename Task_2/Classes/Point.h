#pragma once
#include <ostream>

class Point
{
private:
    double x;
    double y;
    double z;

public:
    Point();
    Point(double x, double y, double z);
    double getX() const;
    double getY() const;
    double getZ() const;
    
    void input();
    bool operator==(const Point& point1, const Point& point2);
    bool operator!=(const Point& point1, const Point& point2);

    friend std::ostream& operator<<(std::ostream& os, const Point& point);
    
};
