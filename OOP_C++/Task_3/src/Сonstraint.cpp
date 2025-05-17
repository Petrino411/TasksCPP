#include "Сonstraint.h"

std::istream& operator>>(std::istream& in, Сonstraint& obj) {
    obj.ReadFrom(in);
    return in;
}