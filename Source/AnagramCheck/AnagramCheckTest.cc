#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <string>
#include "AnagramCheck.hpp"

TEST(StringAlgorithms, AnagramCheckTest)
{
    /* GIVEN */
    std::string oString1 = "Arbuz";
    std::string oString2 = "Burza"; 

    /* WHEN */

    /* THEN */
    EXPECT_TRUE(CheckAnagram(oString1, oString2));
}