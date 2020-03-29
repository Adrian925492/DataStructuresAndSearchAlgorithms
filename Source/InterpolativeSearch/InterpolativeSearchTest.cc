#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "InterpolativeSearch.hpp"

using namespace interpolativeSearch;

TEST(SearchTest, interpolativeSearchTest)
{
    /* GIVEN */
    int inputArray[9] = {1,2,3,4,6,8,9,10,11};

    /* WHEN */

    /* THEN */
    EXPECT_EQ(Search<int>(inputArray, 0, 8, 1), 0);
    EXPECT_EQ(Search<int>(inputArray, 0, 8, 2), 1);
    EXPECT_EQ(Search<int>(inputArray, 0, 8, 3), 2);
    EXPECT_EQ(Search<int>(inputArray, 0, 8, 4), 3);
    EXPECT_EQ(Search<int>(inputArray, 0, 8, 6), 4);
    EXPECT_EQ(Search<int>(inputArray, 0, 8, 5), -1);   
}