#include "Сonstraint.h"

std::istream& operator>>(std::istream& in, Сonstraint& obj) {
    obj.ReadFrom(in);
    return in;
}

std::ostream &operator<<(std::ostream &out, const Сonstraint &obj) {
    out << obj.ToString();
    return out;
}
