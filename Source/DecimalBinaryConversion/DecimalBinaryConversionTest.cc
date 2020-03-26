#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "DecimalBinaryConversion.hpp"

#include <string>

TEST(DecimalBinaryConversion, ConvertDecToBinTest)
{
    int inputNumber = 0b101001;
    std::string expectedString = "101001";

    EXPECT_EQ(convertDecimaToBinary(inputNumber), expectedString);
}

TEST(DecimalBinaryConversion, ConvertBinToDecTest)
{
    std::string inputtring = "111110100";
    int expectedOutput = 500;

    EXPECT_EQ(convertBinaryToDecimal(inputtring), expectedOutput);
}