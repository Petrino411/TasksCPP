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

TEST_F(StackTest, PushAndDisplayWorks) {
    testing::internal::CaptureStdout();
    stack->push(5);
    stack->push(10);
    stack->display();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("10"), std::string::npos);
    EXPECT_NE(output.find("5"), std::string::npos);
}

TEST_F(StackTest, PushDecreasesSize) {
    int initialSize = 10;
    Stack s(initialSize);
    for (int i = 0; i < 5; ++i) {
        s.push(i);
    }
    for (int i = 0; i < 5; ++i) {
        s.pop();
    }

    testing::internal::CaptureStdout();
    s.push(100);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "");
}

TEST_F(StackTest, PushOverflow) {
    Stack s(2);
    s.push(1);
    s.push(2);

    testing::internal::CaptureStdout();
    s.push(3);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Stack overflow!"), std::string::npos);
}

TEST_F(StackTest, PopWorks) {
    stack->push(1);
    stack->push(2);
    stack->pop();

    testing::internal::CaptureStdout();
    stack->display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("1"), std::string::npos);
    EXPECT_EQ(output.find("2"), std::string::npos);
}

TEST_F(StackTest, PopEmptyStack) {
    testing::internal::CaptureStdout();
    stack->pop();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Stack is empty!"), std::string::npos);
}

TEST_F(StackTest, DisplayEmptyStack) {
    testing::internal::CaptureStdout();
    stack->display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Stack is empty!"), std::string::npos);
}
