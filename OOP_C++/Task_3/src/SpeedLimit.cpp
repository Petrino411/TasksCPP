#include "SpeedLimit.h"

std::string SpeedLimit::ToString() const {
    std::ostringstream oss;
    oss << "Ограничение скорости: " << limit << " км/ч "
        << "от " << start.ToString() << " до " << end.ToString();
    return oss.str();
}

void SpeedLimit::ReadFrom(std::istream &in) {
    in >> start >> end >> limit;
    if (limit <= 0 || limit > 80) {
        throw std::runtime_error("Некорректное значение ограничения скорости");
    }
}

std::ostream &operator<<(std::ostream &out, const SpeedLimit &s) {
    out << s.ToString();
    return out;
}
