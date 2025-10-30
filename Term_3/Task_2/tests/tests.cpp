#include <gtest/gtest.h>
#include "Shop.h"


static std::time_t daysAgo(int days) {
    return std::time(nullptr) - days * 86400;
}


TEST(VegetableShopTest, AddRecordAndRetrieve) {
    Shop shop;
    Vegetable tomato("Томат", 100);

    shop.addRecord(Record(tomato, TypeRecord::Supply, 100, daysAgo(2), 5.0));
    shop.addRecord(Record(tomato, TypeRecord::Sale, 60, daysAgo(0), 0.0));

    EXPECT_NEAR(shop.getIncoming(tomato, daysAgo(3), daysAgo(0)), 95.0, 0.001);
    EXPECT_DOUBLE_EQ(shop.getOutgoing(tomato, daysAgo(3), daysAgo(0)), 60.0);
}

TEST(VegetableShopTest, ProfitCalculation) {
    Shop shop;
    std::time_t now = std::time(nullptr);

    Vegetable tomatoBuy("Томат", 100);
    Vegetable tomatoSell("Томат", 150);

    shop.addRecord(Record(tomatoBuy, TypeRecord::Supply, 100, now - 86400, 0.0));
    shop.addRecord(Record(tomatoSell, TypeRecord::Sale, 80, now, 0.0));

    double profit = shop.getProfit(tomatoSell, now - 86400 * 2, now);

    EXPECT_NEAR(profit, 2000, 0.001);
}

TEST(VegetableShopTest, SpoiledPercentAverage) {
    Shop shop;
    Vegetable potato("Картофель", 50);
    std::time_t now = std::time(nullptr);

    shop.addRecord(Record(potato, TypeRecord::Supply, 100, now - 86400 * 3, 2.0));
    shop.addRecord(Record(potato, TypeRecord::Supply, 200, now - 86400 * 2, 4.0));

    double spoiled = shop.getSpoiledPercent("Картофель", now - 86400 * 5, now);
    EXPECT_NEAR(spoiled, 3.333, 0.001);
}

TEST(VegetableShopTest, AvailableAssortment) {
    Shop shop;
    std::time_t now = std::time(nullptr);

    Vegetable tomato("Томат", 100);
    Vegetable potato("Картофель", 50);
    Vegetable carrot("Морковь", 50);

    shop.addRecord(Record(tomato, TypeRecord::Supply, 100, now - 86400, 5.0));
    shop.addRecord(Record(potato, TypeRecord::Supply, 200, now - 86400, 3.0));
    shop.addRecord(Record(carrot, TypeRecord::Supply, 50, now + 86400, 1.0));

    auto list = shop.getAvailableAssortment(now);
    ASSERT_EQ(list.size(), 2);
    EXPECT_EQ(list[0].getName(), "Томат");
    EXPECT_EQ(list[1].getName(), "Картофель");
}

TEST(VegetableShopTest, NoRecordsReturnsZero) {
    Shop shop;
    Vegetable onion("Лук", 20);
    std::time_t now = std::time(nullptr);

    EXPECT_DOUBLE_EQ(shop.getIncoming(onion, now - 1000, now + 1000), 0.0);
    EXPECT_DOUBLE_EQ(shop.getOutgoing(onion, now - 1000, now + 1000), 0.0);
    EXPECT_DOUBLE_EQ(shop.getProfit(onion, now - 1000, now + 1000), 0.0);
    EXPECT_DOUBLE_EQ(shop.getSpoiledPercent("Лук", now - 1000, now + 1000), 0.0);
}

TEST(VegetableShopTest, MultipleProductsMixedRecords) {
    Shop shop;
    std::time_t now = std::time(nullptr);

    Vegetable tomato("Томат", 100);
    Vegetable potato("Картофель", 50);

    shop.addRecord(Record(tomato, TypeRecord::Supply, 100, now - 86400, 5.0));
    shop.addRecord(Record(potato, TypeRecord::Supply, 150, now - 86400, 2.0));
    shop.addRecord(Record(tomato, TypeRecord::Sale, 60, now, 0.0));
    shop.addRecord(Record(potato, TypeRecord::Sale, 100, now, 0.0));

    EXPECT_NEAR(shop.getIncoming(tomato, now - 86400 * 2, now), 95.0, 0.001);
    EXPECT_NEAR(shop.getIncoming(potato, now - 86400 * 2, now), 147.0, 0.001);

    EXPECT_DOUBLE_EQ(shop.getOutgoing(tomato, now - 86400 * 2, now), 60.0);
    EXPECT_DOUBLE_EQ(shop.getOutgoing(potato, now - 86400 * 2, now), 100.0);
}

TEST(VegetableShopTest, SpoiledPercentPerPeriod) {
    Shop shop;
    std::time_t now = std::time(nullptr);
    Vegetable veg("Свёкла", 150);

    shop.addRecord(Record(veg, TypeRecord::Supply, 100, now - 86400 * 10, 10.0));
    shop.addRecord(Record(veg, TypeRecord::Supply, 100, now - 86400 * 2, 2.0));

    double recentSpoiled = shop.getSpoiledPercent("Свёкла", now - 86400 * 3, now);
    EXPECT_NEAR(recentSpoiled, 2.0, 0.001);

    double allSpoiled = shop.getSpoiledPercent("Свёкла", now - 86400 * 15, now);
    EXPECT_NEAR(allSpoiled, 6.0, 0.001);
}
