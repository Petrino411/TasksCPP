#include <iostream>
#include "RandomGenerator.h"
#include "Exercise1.h"

using namespace miit::algebra;

int main()
{
    RandomGenerator gen(-100, 200);
    Exercise1 ex(10, gen);

    std::cout << "=== Task 1 ===" << std::endl;
    ex.Task1();
    std::cout << ex.getMatrix().toString() << "\n\n";

    std::cout << "=== Task 2 ===" << std::endl;
    ex.Task2(99);
    std::cout << ex.getMatrix().toString() << "\n\n";

    std::cout << "=== Task 3 ===" << std::endl;
    ex.Task3(5);
    std::cout << ex.getMatrix().toString() << std::endl;

    return 0;
}