#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "JumpingSearch.hpp"

using namespace jumpingSearch;

TEST(SearchTest, jumpingSearchTest)
{
    /* GIVEN */
    int inputArray[5] = {1,2,5,6,8};

    /* WHEN */

    /* THEN */
    EXPECT_EQ(Search<int>(inputArray, 0, 4, 1), 0);
    EXPECT_EQ(Search<int>(inputArray, 0, 4, 2), 1);
    EXPECT_EQ(Search<int>(inputArray, 0, 4, 5), 2);
    EXPECT_EQ(Search<int>(inputArray, 0, 4, 6), 3);
    EXPECT_EQ(Search<int>(inputArray, 0, 4, 8), 4);
    EXPECT_EQ(Search<int>(inputArray, 0, 4, 7), -1);   
}