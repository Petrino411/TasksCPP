#include <iostream>
#include "SpeedLimit.h"

int main() {
    SpeedLimit sl;
    std::istringstream input("ПК 12 + 28.37 ПК 15 + 45.20 60");
    input >> sl;
    std::cout << sl << std::endl;
    return 0;
}
