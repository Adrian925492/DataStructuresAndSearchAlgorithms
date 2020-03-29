#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "BinarySearch.hpp"

using namespace binarySearch;

TEST(SearchTest, binarySearchTest)
{
    /* GIVEN */
    int inputArray[5] = {1,2,3,4,6};

    /* WHEN */

    /* THEN */
    EXPECT_EQ(Search<int>(inputArray, 0, 4, 1), 0);
    EXPECT_EQ(Search<int>(inputArray, 0, 4, 2), 1);
    EXPECT_EQ(Search<int>(inputArray, 0, 4, 3), 2);
    EXPECT_EQ(Search<int>(inputArray, 0, 4, 4), 3);
    EXPECT_EQ(Search<int>(inputArray, 0, 4, 6), 4);
    EXPECT_EQ(Search<int>(inputArray, 0, 4, 7), -1);   
}