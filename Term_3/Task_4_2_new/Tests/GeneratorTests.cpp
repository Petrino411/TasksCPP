#include <gtest/gtest.h>
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include <sstream>

using namespace miit::algebra;

TEST(GeneratorTests, RandomGeneratorProducesInRange) {
    RandomGenerator gen(-10, 10);
    for (int i = 0; i < 100; ++i) {
        int val = gen.generate();
        EXPECT_GE(val, -10);
        EXPECT_LE(val, 10);
    }
}

TEST(GeneratorTests, IStreamGeneratorProducesFromStream) {
    std::istringstream input("1 2 3");
    IStreamGenerator gen(input);
    EXPECT_EQ(gen.generate(), 1);
    EXPECT_EQ(gen.generate(), 2);
    EXPECT_EQ(gen.generate(), 3);
}
