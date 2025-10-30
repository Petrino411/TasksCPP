#include "Shop.h"
#include <algorithm>

void Shop::addRecord(const Record& record) {
    records.push_back(record);
}

double Shop::getIncoming(const Vegetable& veg, std::time_t from, std::time_t to) const {
    double total = 0.0;
    for (const auto& r : records) {
        if (r.getTypeRecord() == TypeRecord::Supply &&
            r.getVegetable().getName() == veg.getName() &&
            r.getDate() >= from && r.getDate() <= to) {
            total += r.getGoodKilos();
        }
    }
    return total;
}

double Shop::getOutgoing(const Vegetable& veg, std::time_t from, std::time_t to) const {
    double total = 0.0;
    for (const auto& r : records) {
        if (r.getTypeRecord() == TypeRecord::Sale &&
            r.getVegetable().getName() == veg.getName() &&
            r.getDate() >= from && r.getDate() <= to) {
            total += r.getKilos();
        }
    }
    return total;
}

double Shop::getProfit(const Vegetable& veg, std::time_t from, std::time_t to) const {
    double income = 0.0;
    double outcome = 0.0;

    for (const auto& r : records) {
        if (r.getVegetable().getName() != veg.getName()) continue;
        if (r.getDate() < from || r.getDate() > to) continue;

        if (r.getTypeRecord() == TypeRecord::Supply) {
            outcome += r.getGoodKilos() * r.getVegetable().getPrice();
        } else if (r.getTypeRecord() == TypeRecord::Sale) {
            income += r.getKilos() * r.getVegetable().getPrice();
        }
    }
    return income - outcome;
}

double Shop::getSpoiledPercent(const std::string& name, std::time_t from, std::time_t to) const {
    double totalKilos = 0.0;
    double totalSpoiled = 0.0;

    for (const auto& r : records) {
        if (r.getTypeRecord() == TypeRecord::Supply &&
            r.getVegetable().getName() == name &&
            r.getDate() >= from && r.getDate() <= to) {
            totalKilos += r.getKilos();
            totalSpoiled += r.getKilos() * r.getSpoiledPercent() / 100.0;
        }
    }

    if (totalKilos == 0) return 0.0;
    return (totalSpoiled / totalKilos) * 100.0;
}

std::vector<Vegetable> Shop::getAvailableAssortment(std::time_t date) const {
    std::vector<std::string> names;
    for (const auto& r : records) {
        if (r.getTypeRecord() == TypeRecord::Supply && r.getDate() <= date) {
            if (std::find(names.begin(), names.end(), r.getVegetable().getName()) == names.end()) {
                names.push_back(r.getVegetable().getName());
            }
        }
    }

    std::vector<Vegetable> assortment;
    for (const auto& name : names) {
        auto it = std::find_if(records.begin(), records.end(), [&](const Record& r) {
            return r.getVegetable().getName() == name;
        });
        if (it != records.end())
            assortment.push_back(it->getVegetable());
    }
    return assortment;
}
