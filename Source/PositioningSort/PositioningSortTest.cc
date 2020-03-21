#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "PositioningSort.hpp"
#include <cstring>

using namespace positioningSort;

TEST(PositioningSortingTest, ArraySortTest)
{
    int array[5] = {3,4,6,2,1};
    int expectedSortedArray[5] = {1,2,3,4,6};

    Sort<int>(array, 5);

    EXPECT_TRUE(0 == std::memcmp(array, expectedSortedArray, 5));
}