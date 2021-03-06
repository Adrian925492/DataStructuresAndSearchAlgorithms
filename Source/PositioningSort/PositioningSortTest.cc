#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "PositioningSort.hpp"
#include <cstring>

using namespace positioningSort;

TEST(SortTest, positioningTest)
{
    /* GIVEN */
    int array[5] = {321,421,6123,2,1};
    int expectedSortedArray[5] = {1,2,321,421,6123};

    /* WHEN */
    Sort<int>(array, 5);

    /* THEN */
    EXPECT_TRUE(0 == std::memcmp(array, expectedSortedArray, 5));
}