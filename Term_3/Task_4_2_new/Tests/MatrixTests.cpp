#include <gtest/gtest.h>
#include "Matrix.h"
#include "Generator.h"

using namespace miit::algebra;

class DummyGenerator : public Generator {
public:
    int generate() override { return 42; }
};

TEST(MatrixTests, DefaultConstructor) {
    Matrix<int> m;
    EXPECT_EQ(m.getSize(), 0);
}

TEST(MatrixTests, FillAndAccess) {
    DummyGenerator gen;
    Matrix<int> m(5);
    m.fill(gen);
    for (size_t i = 0; i < m.getSize(); ++i)
        EXPECT_EQ(m[i], 42);
}

TEST(MatrixTests, CopyConstructor) {
    Matrix<int> m1(3);
    for (size_t i = 0; i < 3; ++i) m1[i] = i;
    Matrix<int> m2 = m1;
    for (size_t i = 0; i < 3; ++i)
        EXPECT_EQ(m1[i], m2[i]);
}

TEST(MatrixTests, OutOfRangeThrows) {
    Matrix<int> m(3);
    EXPECT_THROW(m[3], std::out_of_range);
}

TEST(MatrixTests, ShiftOperators) {
    Matrix<int> m(3);
    m[0] = 1; m[1] = 2; m[2] = 3;
    m << 9;
    EXPECT_EQ(m[0], 2);
    EXPECT_EQ(m[2], 9);

    m >> 7;
    EXPECT_EQ(m[0], 7);
}
