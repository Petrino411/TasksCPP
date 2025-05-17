#include <gtest/gtest.h>
#include "Stack.h"

class StackTest : public ::testing::Test {
protected:
    Stack *stack{};

    void SetUp() override {
        stack = new Stack(10);
    }

    void TearDown() override {
        delete stack;
    }
};

TEST_F(StackTest, ConstructorPositiveSize) {
    EXPECT_NO_THROW(Stack s(5));
}

TEST_F(StackTest, ConstructorNegativeSizeThrows) {
    EXPECT_THROW(Stack s(-1), std::invalid_argument);
}

TEST_F(StackTest, PushReturnsTrue) {
    EXPECT_TRUE(stack->push(5));
    EXPECT_TRUE(stack->push(10));
    EXPECT_EQ(stack->size(), 2);
}

TEST_F(StackTest, PushOverflowReturnsFalse) {
    Stack s(2);
    EXPECT_TRUE(s.push(1));
    EXPECT_TRUE(s.push(2));
    EXPECT_FALSE(s.push(3));
    EXPECT_EQ(s.size(), 2);
}

TEST_F(StackTest, PopReturnsTrueAndChangesTop) {
    stack->push(1);
    stack->push(2);
    EXPECT_TRUE(stack->pop());

    testing::internal::CaptureStdout();
    stack->display();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("1"), std::string::npos);
    EXPECT_EQ(output.find("2"), std::string::npos);
}

TEST_F(StackTest, PopEmptyReturnsFalse) {
    EXPECT_FALSE(stack->pop());
}

TEST_F(StackTest, PushAndPopMultiple) {
    for (int i = 0; i < 5; ++i)
        EXPECT_TRUE(stack->push(i));

    for (int i = 0; i < 5; ++i)
        EXPECT_TRUE(stack->pop());

    EXPECT_TRUE(stack->isEmpty());
    EXPECT_EQ(stack->size(), 0);
}

TEST_F(StackTest, DisplayEmptyStackOutput) {
    testing::internal::CaptureStdout();
    stack->display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Stack is empty!"), std::string::npos);
}

TEST_F(StackTest, DisplayShowsAllItemsInOrder) {
    stack->push(1);
    stack->push(2);
    stack->push(3);

    testing::internal::CaptureStdout();
    stack->display();
    std::string output = testing::internal::GetCapturedStdout();

    size_t pos3 = output.find("3");
    size_t pos2 = output.find("2");
    size_t pos1 = output.find("1");

    ASSERT_NE(pos3, std::string::npos);
    ASSERT_NE(pos2, std::string::npos);
    ASSERT_NE(pos1, std::string::npos);

    EXPECT_TRUE(pos3 < pos2 && pos2 < pos1);
}
