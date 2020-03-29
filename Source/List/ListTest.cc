#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "List.hpp"

using namespace list;

TEST(ListTest, InitTest)
{
   /* GIVEN */
   List<unsigned char> oList;

   /* WHEN */

   /* THEN */
   EXPECT_EQ(oList.head, nullptr);
   EXPECT_EQ(oList.tail, nullptr);
   EXPECT_EQ(oList.length(), 0u);
}

TEST(ListTest, GetElementTest)
{
   /* GIVEN */
   List<unsigned char> oList;

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

TEST(ListTest, SearchingElementInList)
{
    /* GIVEN */
   List<unsigned char> oList;

    /* WHEN */
    oList.insert('A', 0);
    oList.insert('B', 1);
    oList.insert('C', 2);
    oList.insert('D', 3);

    /*THEN */
    EXPECT_EQ(oList.search('A'), 0u);
    EXPECT_EQ(oList.search('D'), 3u);    
}

TEST(ListTest, RemoveHeadElementTest)
{
    /* GIVEN */
   List<unsigned char> oList;

    /* WHEN */
    oList.insert('A', 0);
    oList.insert('B', 1);
    oList.insert('C', 2);
    oList.insert('D', 3); 
    oList.removeHead();

    /*THEN */
    EXPECT_EQ(oList.search('A'), (unsigned char)NULL);
    EXPECT_EQ(oList.search('C'), 1u);      
    EXPECT_EQ(oList.search('D'), 2u);     
}

TEST(ListTest, RemoveTailElementTest)
{
    /* GIVEN */
   List<unsigned char> oList;

    /* WHEN */
    oList.insert('A', 0);
    oList.insert('B', 1);
    oList.insert('C', 2);
    oList.insert('D', 3); 
    oList.removeTail();

    /*THEN */
    EXPECT_EQ(oList.search('A'), 0u);
    EXPECT_EQ(oList.search('B'), 1u);      
    EXPECT_EQ(oList.search('D'), (unsigned char)NULL);     
}

TEST(ListTest, RemoveElementTest)
{
    /* GIVEN */
   List<unsigned char> oList;

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