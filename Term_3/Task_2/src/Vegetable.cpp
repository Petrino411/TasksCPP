#include "Vegetable.h"

Vegetable::Vegetable(const std::string& name, double price)
    : name(name), price(price) {}

const std::string& Vegetable::getName() const { return name; }

double Vegetable::getPrice() const { return price; }

void Vegetable::setName(const std::string& n) { name = n; }

void Vegetable::setPrice(double p) { price = p; }
