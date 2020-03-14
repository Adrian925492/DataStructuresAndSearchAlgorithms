#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "SimpleList.hpp"

TEST(SimpleListTest, GetElementTest)
{
    /* GIVEN */
    SimpleList_t<char> oList;

    /* WHEN */
    oList.insert(0, 'A');
    oList.insert(1, 'B');
    oList.insert(2, 'C');
    oList.insert(3, 'D');

    /* THEN */
    EXPECT_EQ(oList.get(0), 'A');
    EXPECT_EQ(oList.get(1), 'B');
    EXPECT_EQ(oList.get(2), 'C');
    EXPECT_EQ(oList.get(3), 'D');
}