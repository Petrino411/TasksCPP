#include <gtest/gtest.h>
#include "../src/Piquet.h"

TEST(PiquetTest, ToStringTest) {
Piquet p(12, 28.37);
EXPECT_EQ(p.ToString(), "ПК 12+28.37");
}

TEST(PiquetTest, ShiftRightTest) {
Piquet p(12, 28.37);
Piquet result = p >> 150;
EXPECT_EQ(result.ToString(), "ПК 13+78.37");
}

TEST(PiquetTest, ShiftLeftTest) {
Piquet p(12, 28.37);
Piquet result = p << 50;
EXPECT_EQ(result.ToString(), "ПК 11+78.37");
}

TEST(PiquetTest, ComparisonTest) {
Piquet p1(12, 28.37);
Piquet p2(13, 50.0);
EXPECT_TRUE(p1 < p2);
EXPECT_FALSE(p1 > p2);
EXPECT_TRUE(p1 == p1);
}