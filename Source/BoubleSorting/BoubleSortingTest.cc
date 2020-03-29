#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "BoubleSorting.hpp"
#include <cstring>

using namespace boubleSort;

TEST(SortTest, boubleSortTest)
{
    /* GIVEN */
    int array[5] = {3,4,6,2,1};
    int expectedSortedArray[5] = {1,2,3,4,6};

    /* WHEN */
    Sort<int>(array, 5);

    /* THEN */
    EXPECT_TRUE(0 == std::memcmp(array, expectedSortedArray, 5));
}