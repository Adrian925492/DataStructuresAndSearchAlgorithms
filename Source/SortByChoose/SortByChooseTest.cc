#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "SortByChoose.hpp"
#include <cstring>

using namespace sortByChoose;

TEST(SortTest, sortByChooseTest)
{
    int array[5] = {3,4,6,2,1};
    int expectedSortedArray[5] = {1,2,3,4,6};

    Sort<int>(array, 5);

    EXPECT_TRUE(0 == std::memcmp(array, expectedSortedArray, 5));
}