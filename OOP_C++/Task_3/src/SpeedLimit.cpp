#include "SpeedLimit.h"


SpeedLimit::SpeedLimit(Piquet& s, Piquet& e, double l) : start(s), end(e), limit(l) {
    if (l <= 0 || l > 80) {
        throw std::runtime_error("Некорректное значение ограничения скорости");
    }
    if(s > e){
        throw std::runtime_error("Некорректное значение начала ограничения скорости");
    }
}

std::string SpeedLimit::ToString() const {
    std::ostringstream oss;
    oss << "Ограничение скорости: " << limit << " км/ч "
        << "от " << start.ToString() << " до " << end.ToString();
    return oss.str();
}

void SpeedLimit::ReadFrom(std::istream &in) {
    if(start > end){
        throw std::runtime_error("Некорректное значение начала ограничения скорости");
    }
    in >> start >> end >> limit;
    if (limit <= 0 || limit > 80) {
        throw std::runtime_error("Некорректное значение ограничения скорости");
    }
}



