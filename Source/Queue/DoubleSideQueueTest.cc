#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "DoubleSideQueue.hpp"

using namespace doubleSideQueue;

TEST(DoubleSideQueueTest, InitTest)
{
    /* GIVEN */
    Queue<uint16_t> oQueue;

    /* WHEN */

    /* THEN */
    EXPECT_TRUE(oQueue.isEmpty());
    EXPECT_EQ(oQueue.front(), NULL);
    EXPECT_EQ(oQueue.back(), NULL);
}