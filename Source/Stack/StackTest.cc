#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Stack.hpp"

using namespace stack;

TEST(StackTest, InitTest)
{
    /* GIVEN */
    Stack<uint16_t> oStack;

    /* WHEN */

    /* THEN */
    EXPECT_EQ(oStack.isEmpty(), true);
    EXPECT_EQ(oStack.getTop(), NULL);
}

TEST(StackTest, PushTest)
{
    /* GIVEN */
    Stack<uint16_t> oStack;

    /* WHEN */
    oStack.push(2);
    oStack.push(1);

    /* THEN */
    EXPECT_EQ(oStack.isEmpty(), false);
    EXPECT_EQ(oStack.getTop(), 1u);
}

TEST(StackTest, PopTest)
{
    /* GIVEN */
    Stack<uint16_t> oStack;

    /* WHEN */
    oStack.push(2);
    oStack.push(1);
    oStack.pop();

    /* THEN */
    EXPECT_EQ(oStack.isEmpty(), false);
    EXPECT_EQ(oStack.getTop(), 2u);
}