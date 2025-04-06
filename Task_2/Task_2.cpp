#include <iostream>
#include "Classes/Cylinder.h"
#include "Classes/Point.h"

int main(int argc, char* argv[])
{
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
