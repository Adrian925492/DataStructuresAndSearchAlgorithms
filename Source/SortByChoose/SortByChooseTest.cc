#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "SortByChoose.hpp"
#include <cstring>

using namespace sortByChoose;

TEST(SortTest, sortByChooseTest)
{
    /* GIVEN */
    int array[5] = {3,4,6,2,1};
    int expectedSortedArray[5] = {1,2,3,4,6};

    /* WHEN */
    Sort<int>(array, 5);

    /* THEN */
    EXPECT_TRUE(0 == std::memcmp(array, expectedSortedArray, 5));
}