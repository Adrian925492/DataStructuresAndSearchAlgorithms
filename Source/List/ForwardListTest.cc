#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "ForwardList.hpp"

using namespace forwardList;

TEST(ForwardListTest, InitTest)
{
   /* GIVEN */
   ForwardList<unsigned char> oList;

   /* WHEN */

   /* THEN */
   EXPECT_EQ(oList.head, nullptr);
   EXPECT_EQ(oList.tail, nullptr);
   EXPECT_EQ(oList.length(), 0u);
}

TEST(ForwardListTest, GetElementTest)
{
   /* GIVEN */
   ForwardList<unsigned char> oList;

   /* WHEN */
    oList.insertHead('A');
    oList.insert('C', 1);
    oList.insert('B', 1);
    oList.insert('D', 3);

    /* THEN */
    EXPECT_EQ(oList.get(0), 'A');
    EXPECT_EQ(oList.get(1), 'B');
    EXPECT_EQ(oList.get(2), 'C');
    EXPECT_EQ(oList.get(3), 'D');
}

TEST(ForwardListTest, SearchingElementInList)
{
    /* GIVEN */
   ForwardList<unsigned char> oList;

    /* WHEN */
    oList.insert('A', 0);
    oList.insert('B', 1);
    oList.insert('C', 2);
    oList.insert('D', 3);

    /* THEN */
    EXPECT_EQ(oList.search('A'), 0u);
    EXPECT_EQ(oList.search('D'), 3u);    
}

TEST(ForwardListTest, RemoveHeadElementTest)
{
    /* GIVEN */
   ForwardList<unsigned char> oList;

    /* WHEN */
    oList.insert('A', 0);
    oList.insert('B', 1);
    oList.insert('C', 2);
    oList.insert('D', 3); 
    oList.removeHead();

    /* THEN */
    EXPECT_EQ(oList.search('A'), (unsigned char)NULL);
    EXPECT_EQ(oList.search('C'), 1u);      
    EXPECT_EQ(oList.search('D'), 2u);     
}

TEST(ForwardListTest, RemoveTailElementTest)
{
    /* GIVEN */
   ForwardList<unsigned char> oList;

    /* WHEN */
    oList.insert('A', 0);
    oList.insert('B', 1);
    oList.insert('C', 2);
    oList.insert('D', 3); 
    oList.removeTail();

    /* THEN */
    EXPECT_EQ(oList.search('A'), 0u);
    EXPECT_EQ(oList.search('B'), 1u);      
    EXPECT_EQ(oList.search('D'), (unsigned char)NULL);     
}

TEST(ForwardListTest, RemoveElementTest)
{
    /* GIVEN */
   ForwardList<unsigned char> oList;

    /* WHEN */
    oList.insert('A', 0);
    oList.insert('B', 1);
    oList.insert('C', 2);
    oList.insert('D', 3); 
    oList.remove(1);

    /* THEN */
    EXPECT_EQ(oList.search('A'), 0u);
    EXPECT_EQ(oList.search('C'), 1u);      
    EXPECT_EQ(oList.search('D'), 2u);     
}