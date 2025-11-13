#include <iostream>
#include <ctime>
#include "Shop.h"

int main() {
    Shop shop;
    std::time_t now = std::time(nullptr);

    Vegetable tomato("Томат", 100);
    Vegetable potato("Картофель", 50);

    shop.addRecord(Record(tomato, TypeRecord::Supply, 100, now - 86400, 4.0));
    shop.addRecord(Record(potato, TypeRecord::Supply, 200, now - 86400, 3.0));

    shop.addRecord(Record(tomato, TypeRecord::Sale, 70, now, 0.0));
    shop.addRecord(Record(potato, TypeRecord::Sale, 120, now, 0.0));

    std::cout << "Приход томатов: " << shop.getIncoming(tomato, now - 86400 * 2, now) << " кг\n";
    std::cout << "Продано томатов: " << shop.getOutgoing(tomato, now - 86400 * 2, now) << " кг\n";
    std::cout << "Прибыль по томатам: " << shop.getProfit(tomato, now - 86400 * 2, now) << " руб\n";
    std::cout << "Процент порчи томатов: " << shop.getSpoiledPercent("Томат", now - 86400 * 2, now) << "%\n";

    std::cout << "\nАссортимент:\n";
    for (auto& v : shop.getAvailableAssortment(now))
        std::cout << " - " << v.getName() << "\n";

    return 0;
}
