#include <sstream>
#include <iomanip>
#include <cmath>
#include "Piquet.h"


Piquet::Piquet(int n, double s) {
    number = n;
    shift = s;
    if(n < 0 || s < 0.0){
        throw std::invalid_argument("Числа не могут быть отрицательными");
    }
    isStandard = (n == 100) && (std::abs(s) < std::numeric_limits<double>::epsilon());
}

std::string Piquet::ToString() const {
    std::ostringstream oss;
    if (number < 0)
        oss << "ПК 0" << std::abs(number);
    else
        oss << "ПК " << number;
    oss << "+" << std::fixed << std::setprecision(2) << shift;
    return oss.str();
}

bool Piquet::operator<(const Piquet &other) const {
    return number + shift < other.number + other.shift;
}

bool Piquet::operator>(const Piquet &other) const {
    return number + shift > other.number + other.shift;
}

bool Piquet::operator==(const Piquet &other) {
    return (number == other.number) && (std::abs(shift - other.shift) < std::numeric_limits<double>::epsilon());
}

bool Piquet::operator!=(const Piquet &other) {
    return !(*this == other);
}

std::istream &operator>>(std::istream &in, Piquet &p) {
    std::string label;
    char plus;
    in >> label >> p.number >> plus >> p.shift;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Piquet &p) {
    out << p.ToString();
    return out;
}


