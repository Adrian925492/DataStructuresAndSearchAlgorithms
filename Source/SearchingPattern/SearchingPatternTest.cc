#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "SearchingPattern.hpp"

TEST(PatternSearch, PatternSearchTest)
{
    /* GIVEN */
    std::string inputString = "nie wiem czy tak czy nie";
    std::string target = "nie";

    /* WHEN */
    std::vector<int> output = patternSearch(inputString, target);

    /* THEN */
    EXPECT_EQ(output[0], 0);
    EXPECT_EQ(output[1], 21);
}