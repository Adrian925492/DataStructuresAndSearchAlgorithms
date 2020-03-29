#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "DecimalBinaryConversion.hpp"

#include <string>

TEST(DecimalBinaryConversion, ConvertDecToBinTest)
{
    /* GIVEN */
    int inputNumber = 0b101001;
    std::string expectedString = "101001";

    /* WHEN */

    /* THEN */
    EXPECT_EQ(convertDecimaToBinary(inputNumber), expectedString);
}

TEST(DecimalBinaryConversion, ConvertBinToDecTest)
{
    /* GIVEN */
    std::string inputtring = "111110100";
    int expectedOutput = 500;

    /* WHEN */

    /* THEN */
    EXPECT_EQ(convertBinaryToDecimal(inputtring), expectedOutput);
}