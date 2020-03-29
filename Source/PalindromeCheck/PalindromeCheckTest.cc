#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "PalindromeCheck.hpp"

#include <string>

TEST(StringAlgorithms, CheckPalindromeTest)
{
    /* GIVEN */
    std::string oString1 = "Rotator";

    /* WHEN */

    /* THEN */
    EXPECT_TRUE(CheckPalindrome(oString1));
}