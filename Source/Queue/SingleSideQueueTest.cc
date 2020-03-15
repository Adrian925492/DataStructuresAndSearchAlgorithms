#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "SingleSideQueue.hpp"

using namespace singleSideQueue;

TEST(SingleSideQueueTest, IntiTest)
{
    /* GIVEN */
    Queue<uint16_t> oQueue;

    /* WHEN */

    /* THEN */
    EXPECT_TRUE(oQueue.isEmpty());
    EXPECT_EQ(oQueue.front(), NULL);
}