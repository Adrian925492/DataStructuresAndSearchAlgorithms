#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "SublistSearch.hpp"

using namespace sublistSearch;

TEST(SearchTest, sublistSearchTest)
{
    int inputArray[5] = {1,2,5,6,4};

    EXPECT_EQ(Search<int>(inputArray, 0, 5, 1), 0);
    EXPECT_EQ(Search<int>(inputArray, 0, 5, 2), 1);
    EXPECT_EQ(Search<int>(inputArray, 0, 5, 5), 2);
    EXPECT_EQ(Search<int>(inputArray, 0, 5, 6), 3);
    EXPECT_EQ(Search<int>(inputArray, 0, 5, 4), 4);
    EXPECT_EQ(Search<int>(inputArray, 0, 5, 7), -1);   
}