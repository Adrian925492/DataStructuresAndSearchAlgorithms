#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "BinaryHeap.hpp"

TEST(BinaryHeapTest, InitTest)
{
    /* GIVEN */
    BinaryHeap oBinaryHeap;

    /* WHEN */

    /* THEN */
    EXPECT_TRUE(oBinaryHeap.IsEmpty());
}

TEST(BinaryHeapTest, InsertTest)
{
    /* GIVEN */
    BinaryHeap oBinaryHeap;

    /* WHEN */
    oBinaryHeap.Insert(1);
    oBinaryHeap.Insert(2);
    oBinaryHeap.Insert(3);

    /* THEN */
    EXPECT_FALSE(oBinaryHeap.IsEmpty());
    EXPECT_EQ(oBinaryHeap.GetMax(), 3);
}

TEST(BinaryHeapTest, RemoveMaxTest)
{
    /* GIVEN */
    BinaryHeap oBinaryHeap;

    /* WHEN */
    oBinaryHeap.Insert(1);
    oBinaryHeap.Insert(2);
    oBinaryHeap.Insert(3);
    oBinaryHeap.ExtractMax();

    /* THEN */
    EXPECT_FALSE(oBinaryHeap.IsEmpty());
    EXPECT_EQ(oBinaryHeap.GetMax(), 2);
}