#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "CountingSort.hpp"
#include <cstring>

using namespace countingSort;

TEST(CountingSortingTest, ArraySortTest)
{
    int array[7] = {1,6,2,3,1,4,6};
    int expectedSortedArray[7] = {1,1,2,3,4,6,6};

    Sort<int>(array, 7);

    EXPECT_TRUE(0 == std::memcmp(array, expectedSortedArray, 7));
}