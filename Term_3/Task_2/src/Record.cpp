#include "Record.h"

Record::Record(const Vegetable& veg, TypeRecord type, double kilos,
               std::time_t date, double spoiledPercent)
    : vegetable(veg), typeRecord(type), kilos(kilos),
      date(date), spoiledPercent(spoiledPercent) {}

const Vegetable& Record::getVegetable() const { return vegetable; }

TypeRecord Record::getTypeRecord() const { return typeRecord; }

double Record::getKilos() const { return kilos; }

std::time_t Record::getDate() const { return date; }

double Record::getSpoiledPercent() const { return spoiledPercent; }

double Record::getGoodKilos() const {
    return kilos * (1.0 - spoiledPercent / 100.0);
}
