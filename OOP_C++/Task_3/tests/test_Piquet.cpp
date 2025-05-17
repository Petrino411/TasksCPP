#include <gtest/gtest.h>
#include "../src/Piquet.h"

TEST(PiquetTest, ToStringTest) {
    Piquet p(12, 28.37);
    EXPECT_EQ(p.ToString(), "ПК 12+28.37");
}

TEST(PiquetTest, NegativeNumberTest) {
    EXPECT_THROW( Piquet p(-12, 28.37), std::invalid_argument);
}

TEST(PiquetTest, ComparisonTest) {
    Piquet p1(12, 28.37);
    Piquet p2(13, 50.0);
    EXPECT_TRUE(p1 < p2);
    EXPECT_FALSE(p1 > p2);
    EXPECT_TRUE(p1 == p1);
}