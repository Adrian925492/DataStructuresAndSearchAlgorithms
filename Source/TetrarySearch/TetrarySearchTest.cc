#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "TetrarySearch.hpp"

using namespace tetrarySearch;

TEST(SearchTest, tetrarySearchTest)
{
    int inputArray[5] = {1,2,3,4,6};

    EXPECT_EQ(Search<int>(inputArray, 0, 4, 1), 0);
    EXPECT_EQ(Search<int>(inputArray, 0, 4, 2), 1);
    EXPECT_EQ(Search<int>(inputArray, 0, 4, 3), 2);
    EXPECT_EQ(Search<int>(inputArray, 0, 4, 4), 3);
    EXPECT_EQ(Search<int>(inputArray, 0, 4, 6), 4);
    EXPECT_EQ(Search<int>(inputArray, 0, 5, 7), -1);   
}