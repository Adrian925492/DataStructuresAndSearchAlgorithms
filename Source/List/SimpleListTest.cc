#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "SimpleList.hpp"

TEST(SimpleListTest, InitTest)
{
   /* GIVEN */
    SimpleList_t<char> oList;

   /* WHEN */

   /* THEN */
   EXPECT_EQ(oList.length(), 0u);
}

TEST(SimpleListTest, GetElementTest)
{
    /* GIVEN */
    SimpleList_t<char> oList;

    /* WHEN */
    oList.insert('A', 0);
    oList.insert('B', 1);
    oList.insert('C', 2);
    oList.insert('D', 3);

    /* THEN */
    EXPECT_EQ(oList.get(0), 'A');
    EXPECT_EQ(oList.get(1), 'B');
    EXPECT_EQ(oList.get(2), 'C');
    EXPECT_EQ(oList.get(3), 'D');
}

TEST(SimpleListTest, SearchingElementInList)
{
    /* GIVEN */
    SimpleList_t<char> oList;

    /* WHEN */
    oList.insert('A', 0);
    oList.insert('B', 1);
    oList.insert('C', 2);
    oList.insert('D', 3);

    /*THEN */
    EXPECT_EQ(oList.search('A'), 0u);
    EXPECT_EQ(oList.search('D'), 3u);    
}

TEST(SimpleListTest, RemoveElementTest)
{
    /* GIVEN */
    SimpleList_t<char> oList;

    /* WHEN */
    oList.insert('A', 0);
    oList.insert('B', 1);
    oList.insert('C', 2);
    oList.insert('D', 3); 
    oList.remove(1);

    /*THEN */
    EXPECT_EQ(oList.search('A'), 0u);
    EXPECT_EQ(oList.search('C'), 1u);      
    EXPECT_EQ(oList.search('D'), 2u);     
}