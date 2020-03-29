#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "HashTableChain.hpp"
#include "HashTableOpenAdress.hpp"

TEST(HashTableChain, InitTest)
{
    /* GIVEN */
    ::chainMethod::HashTable oHashTable;

    /* WHEN */

    /* THEN */
    EXPECT_TRUE(oHashTable.isEmpty());
}

TEST(HashTableChain, InsertSearchTest)
{
    /* GIVEN */
    ::chainMethod::HashTable oHashTable;

    /* WHEN */
    oHashTable.insert(128, "Opel");
    oHashTable.insert(332, "Skoda");
    oHashTable.insert(391, "Fiat");
    oHashTable.insert(895, "Toyota");   //391 and 895 has collision if hash table size is 7

    /* THEN */
    EXPECT_FALSE(oHashTable.isEmpty());
    EXPECT_EQ(oHashTable.search(128), "Opel");
    EXPECT_EQ(oHashTable.search(332), "Skoda");
    EXPECT_EQ(oHashTable.search(391), "Fiat");
    EXPECT_EQ(oHashTable.search(895), "Toyota");
}

TEST(HashTableChain, RemoveTest)
{
    /* GIVEN */
    ::chainMethod::HashTable oHashTable;

    /* WHEN */
    oHashTable.insert(128, "Opel");
    oHashTable.insert(332, "Skoda");
    oHashTable.insert(391, "Fiat");
    oHashTable.insert(895, "Toyota");   //391 and 895 has collision if hash table size is 7
    oHashTable.remove(895);

    /* THEN */
    EXPECT_FALSE(oHashTable.isEmpty());
    EXPECT_EQ(oHashTable.search(128), "Opel");
    EXPECT_EQ(oHashTable.search(332), "Skoda");
    EXPECT_EQ(oHashTable.search(391), "Fiat");
    EXPECT_EQ(oHashTable.search(895), "");
}

TEST(HashTableOpenAdress, InitTest)
{
    /* GIVEN */
    ::openAdressMethod::HashTable oHashTable;

    /* WHEN */

    /* THEN */
    EXPECT_TRUE(oHashTable.isEmpty());
}

TEST(HashTableOpenAdress, InsertSearchTest)
{
    /* GIVEN */
    ::openAdressMethod::HashTable oHashTable;

    /* WHEN */
    oHashTable.insert(128, "Opel");
    oHashTable.insert(332, "Skoda");
    oHashTable.insert(391, "Fiat");
    oHashTable.insert(895, "Toyota");   //391 and 895 has collision if hash table size is 7

    /* THEN */
    EXPECT_FALSE(oHashTable.isEmpty());
    EXPECT_EQ(oHashTable.search(128), "Opel");
    EXPECT_EQ(oHashTable.search(332), "Skoda");
    EXPECT_EQ(oHashTable.search(391), "Fiat");
    EXPECT_EQ(oHashTable.search(895), "Toyota");
}

TEST(HashTableOpenAdress, RemoveTest)
{
    /* GIVEN */
    ::openAdressMethod::HashTable oHashTable;

    /* WHEN */
    oHashTable.insert(128, "Opel");
    oHashTable.insert(332, "Skoda");
    oHashTable.insert(391, "Fiat");
    oHashTable.insert(895, "Toyota");   //391 and 895 has collision if hash table size is 7
    oHashTable.remove(895);

    /* THEN */
    EXPECT_FALSE(oHashTable.isEmpty());
    EXPECT_EQ(oHashTable.search(128), "Opel");
    EXPECT_EQ(oHashTable.search(332), "Skoda");
    EXPECT_EQ(oHashTable.search(391), "Fiat");
    EXPECT_EQ(oHashTable.search(895), "");
}