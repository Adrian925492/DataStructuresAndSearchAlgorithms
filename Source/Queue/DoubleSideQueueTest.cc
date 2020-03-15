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

TEST(DoubleSideQueueTest, PushToFrontTest)
{
    /* GIVEN */
    Queue<uint16_t> oQueue;

    /* WHEN */
    oQueue.pushToFront(1);
    oQueue.pushToFront(2);
    oQueue.pushToFront(3);

    /* THEN */
    EXPECT_FALSE(oQueue.isEmpty());
    EXPECT_EQ(oQueue.front(), 3u);
    EXPECT_EQ(oQueue.back(), 1u);
}

TEST(DoubleSideQueueTest, PushToBackTest)
{
    /* GIVEN */
    Queue<uint16_t> oQueue;

    /* WHEN */
    oQueue.pushToBack(1);
    oQueue.pushToBack(2);
    oQueue.pushToBack(3);

    /* THEN */
    EXPECT_FALSE(oQueue.isEmpty());
    EXPECT_EQ(oQueue.front(), 1u);
    EXPECT_EQ(oQueue.back(),3u);
}

TEST(DoubleSideQueueTest, PopFrontTest)
{
    /* GIVEN */
    Queue<uint16_t> oQueue;

    /* WHEN */
    oQueue.pushToFront(1);
    oQueue.pushToFront(2);
    oQueue.pushToFront(3);
    oQueue.popFront();

    /* THEN */
    EXPECT_FALSE(oQueue.isEmpty());
    EXPECT_EQ(oQueue.front(), 2u);
    EXPECT_EQ(oQueue.back(),1u);
}

TEST(DoubleSideQueueTest, PopBackTest)
{
    /* GIVEN */
    Queue<uint16_t> oQueue;

    /* WHEN */
    oQueue.pushToFront(1);
    oQueue.pushToFront(2);
    oQueue.pushToFront(3);
    oQueue.popBack();

    /* THEN */
    EXPECT_FALSE(oQueue.isEmpty());
    EXPECT_EQ(oQueue.front(), 3u);
    EXPECT_EQ(oQueue.back(),2u);
}