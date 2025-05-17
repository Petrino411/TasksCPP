#include <sstream>
#include <iomanip>
#include <cmath>
#include "Piquet.h"


Piquet::Piquet(int n, double s, bool isSt) {
    number = n;
    shift = s;
    isStandard = isSt;
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

Piquet Piquet::operator>>(double meters) {
    double total = number * 100.0 + shift + meters;
    return Piquet(static_cast<int>(total / 100), std::fmod(total, 100.0), isStandard);
}

Piquet Piquet::operator<<(double meters) {
    double total = number * 100.0 + shift - meters;
    return Piquet(static_cast<int>(total / 100), std::fmod(total, 100.0), isStandard);
}

bool Piquet::operator<(const Piquet &other) const {
    return number * 100 + shift < other.number * 100 + other.shift;
}

bool Piquet::operator>(const Piquet &other) {
    return other < *this;
}

bool Piquet::operator==(const Piquet &other) {
    return number == other.number && std::abs(shift - other.shift) < 1e-6;
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
