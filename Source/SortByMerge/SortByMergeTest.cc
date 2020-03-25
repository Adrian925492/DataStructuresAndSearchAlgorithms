#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "SortByMerge.hpp"
#include <cstring>

using namespace sortByMerge;

TEST(SortTest, sortByMergeTest)
{
    int array[5] = {3,4,6,2,1};
    int expectedSortedArray[5] = {1,2,3,4,6};

    Sort<int>(array, 0, 5);

    EXPECT_TRUE(0 == std::memcmp(array, expectedSortedArray, 5));
}