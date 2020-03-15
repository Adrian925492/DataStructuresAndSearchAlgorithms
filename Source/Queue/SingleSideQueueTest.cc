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

TEST(SingleSideQueueTest, EnqueueTest)
{
    /* GIVEN */
    Queue<uint16_t> oQueue;

    /* WHEN */
    oQueue.enqueue(1u);
    oQueue.enqueue(2u);

    /* THEN */
    EXPECT_FALSE(oQueue.isEmpty());
    EXPECT_EQ(oQueue.front(), 1u);
}