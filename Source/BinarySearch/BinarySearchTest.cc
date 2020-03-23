#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "BinarySearch.hpp"

using namespace binarySearch;

TEST(SearchTest, binarySearchTest)
{
    int inputArray[5] = {1,2,3,4,6};

    EXPECT_EQ(Search<int>(inputArray, 0, 5, 1), 0);
    EXPECT_EQ(Search<int>(inputArray, 0, 5, 2), 1);
    EXPECT_EQ(Search<int>(inputArray, 0, 5, 3), 2);
    EXPECT_EQ(Search<int>(inputArray, 0, 5, 4), 3);
    EXPECT_EQ(Search<int>(inputArray, 0, 5, 6), 4);
    EXPECT_EQ(Search<int>(inputArray, 0, 5, 7), -1);   
}