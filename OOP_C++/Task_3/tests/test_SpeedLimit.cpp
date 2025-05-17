#include <gtest/gtest.h>
#include "../src/SpeedLimit.h"

TEST(SpeedLimitTest, ToStringTest) {
SpeedLimit sl;
std::istringstream input("ПК 12 + 28.37 ПК 15 + 45.20 60");
input >> sl;
EXPECT_EQ(sl.ToString(), "Ограничение скорости: 60 км/ч от ПК 12+28.37 до ПК 15+45.20");
}

TEST(SpeedLimitTest, InvalidSpeedLimitTest) {
SpeedLimit sl;
std::istringstream input("ПК 12 + 28.37 ПК 15 + 45.20 100");
EXPECT_THROW(input >> sl, std::runtime_error);
}

TEST(SpeedLimitTest, ValidSpeedLimitTest) {
SpeedLimit sl;
std::istringstream input("ПК 10 + 50.0 ПК 20 + 70.0 80");
input >> sl;
EXPECT_EQ(sl.ToString(), "Ограничение скорости: 80 км/ч от ПК 10+50.00 до ПК 20+70.00");
}
