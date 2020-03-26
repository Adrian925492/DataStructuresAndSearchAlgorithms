#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "SearchingPattern.hpp"

TEST(PatternSearch, PatternSearchTest)
{
    std::string inputString = "nie wiem czy tak czy nie";
    std::string target = "nie";

    std::vector<int> expectedOutput(0,21);

    std::vector<int> output = patternSearch(inputString, target);

    EXPECT_EQ(output[0], 0);
    EXPECT_EQ(output[1], 21);
}