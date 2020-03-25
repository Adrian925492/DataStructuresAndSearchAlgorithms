#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "PalindromeCheck.hpp"

#include <string>

TEST(StringAlgorithms, CheckPalindromeTest)
{
    std::string oString1 = "Rotator";

    EXPECT_TRUE(CheckPalindrome(oString1));
}