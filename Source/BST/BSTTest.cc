#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "BST.hpp"

using namespace bst;

TEST(BST, BST_initTest)
{
    Node* oBst = new Node;

    EXPECT_EQ(oBst->key, 0u);
    EXPECT_EQ(oBst->leftChild, nullptr);
    EXPECT_EQ(oBst->parent, nullptr);
    EXPECT_EQ(oBst->rightChild, nullptr);
}

TEST(BST, BST_insertTest)
{
    /* GIVEN */
    Node* oBst = new Node;
    
    /* WHEN */
    /* Create tree:
        2
      /   \
     1     3
            \
             4
    */

    oBst->Insert(2);
    oBst->Insert(3);
    oBst->Insert(1);
    oBst->Insert(4);

    /* THEN */
    EXPECT_EQ(oBst->root->key, 2u);
    EXPECT_EQ(oBst->root->rightChild->key, 3u);
    EXPECT_EQ(oBst->root->rightChild->rightChild->key, 4u);
    EXPECT_EQ(oBst->root->leftChild->key, 1u);
}

TEST(BST, BST_searchTest)
{
    /* GIVEN */
    Node* oBst = new Node;
    
    /* WHEN */
    /* Create tree:
        2
      /   \
     1     3
            \
             4
    */

    oBst->Insert(2);
    oBst->Insert(3);
    oBst->Insert(1);
    oBst->Insert(4);

    /* THEN */
    EXPECT_TRUE(oBst->Search(2));
    EXPECT_TRUE(oBst->Search(4));
    EXPECT_TRUE(oBst->Search(3));
    EXPECT_TRUE(oBst->Search(1));
    EXPECT_FALSE(oBst->Search(8));
}

TEST(BST, BST_searchMaximumTest)
{
    /* GIVEN */
    Node* oBst = new Node;
    
    /* WHEN */
    /* Create tree:
        2
      /   \
     1     3
            \
             4
    */

    oBst->Insert(2);
    oBst->Insert(3);
    oBst->Insert(1);
    oBst->Insert(4);

    /* THEN */
    EXPECT_EQ(oBst->SearchMaxValue(), 4u);
}

TEST(BST, BST_searchMinimumTest)
{
    /* GIVEN */
    Node* oBst = new Node;
    
    /* WHEN */
    /* Create tree:
        2
      /   \
     1     3
            \
             4
    */

    oBst->Insert(2);
    oBst->Insert(3);
    oBst->Insert(1);
    oBst->Insert(4);

    /* THEN */
    EXPECT_EQ(oBst->SearchMinValue(), 1u);
}