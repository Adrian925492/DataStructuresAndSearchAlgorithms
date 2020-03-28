#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "AVL.hpp"

using namespace avl;

TEST(AVL, AVL_initTest)
{
    Node* oAVL = new Node;

    EXPECT_EQ(oAVL->key, 0u);
    EXPECT_EQ(oAVL->leftChild, nullptr);
    EXPECT_EQ(oAVL->parent, nullptr);
    EXPECT_EQ(oAVL->rightChild, nullptr);
}

TEST(AVL, AVL_insertTest)
{
    /* GIVEN */
    Node* oAVL = new Node;
    
    /* WHEN */
    /* Create tree (after rotation):
        2
      /   \
     1     3
            \
             4
    */

    oAVL->Insert(1);
    oAVL->Insert(2);
    oAVL->Insert(3);
    oAVL->Insert(4);

    /* THEN */
    EXPECT_EQ(oAVL->root->key, 2u);
    EXPECT_EQ(oAVL->root->rightChild->key, 3u);
    EXPECT_EQ(oAVL->root->rightChild->rightChild->key, 4u);
    EXPECT_EQ(oAVL->root->leftChild->key, 1u);
}

TEST(AVL, AVL_getAllElementsTest)
{
    /* GIVEN */
    Node* oAVL = new Node;
    std::vector<int> output;

    /* WHEN */
    /* Create tree:
        2
      /   \
     1     3
            \
             4
    */

    oAVL->Insert(2);
    oAVL->Insert(3);
    oAVL->Insert(1);
    oAVL->Insert(4);
    oAVL->GetAllEements(&output);

    /* THEN */
    EXPECT_EQ(output[0], 1u);
    EXPECT_EQ(output[1], 2u);
    EXPECT_EQ(output[2], 3u);
    EXPECT_EQ(output[3], 4u);
}

TEST(AVL, AVL_searchTest)
{
    /* GIVEN */
    Node* oAVL = new Node;
    
    /* WHEN */
    /* Create tree:
        2
      /   \
     1     3
            \
             4
    */

    oAVL->Insert(2);
    oAVL->Insert(3);
    oAVL->Insert(1);
    oAVL->Insert(4);

    /* THEN */
    EXPECT_TRUE(oAVL->Search(2));
    EXPECT_TRUE(oAVL->Search(4));
    EXPECT_TRUE(oAVL->Search(3));
    EXPECT_TRUE(oAVL->Search(1));
    EXPECT_FALSE(oAVL->Search(8));
}

TEST(AVL, AVL_searchMaximumTest)
{
    /* GIVEN */
    Node* oAVL = new Node;
    
    /* WHEN */
    /* Create tree:
        2
      /   \
     1     3
            \
             4
    */

    oAVL->Insert(2);
    oAVL->Insert(3);
    oAVL->Insert(1);
    oAVL->Insert(4);

    /* THEN */
    EXPECT_EQ(oAVL->SearchMaxValue(), 4u);
}

TEST(AVL, AVL_searchMinimumTest)
{
    /* GIVEN */
    Node* oAVL = new Node;
    
    /* WHEN */
    /* Create tree:
        2
      /   \
     1     3
            \
             4
    */

    oAVL->Insert(2);
    oAVL->Insert(3);
    oAVL->Insert(1);
    oAVL->Insert(4);

    /* THEN */
    EXPECT_EQ(oAVL->SearchMinValue(), 1u);
}

TEST(AVL, AVL_searchSuccessorTest)
{
    /* GIVEN */
    Node* oAVL = new Node;
    
    /* WHEN */
    /* Create tree:
        2
      /   \
     1     3
            \
             4
    */

    oAVL->Insert(2);
    oAVL->Insert(3);
    oAVL->Insert(1);
    oAVL->Insert(4);

    /* THEN */
    EXPECT_EQ(oAVL->Successor(oAVL->root), 3);
    EXPECT_EQ(oAVL->Successor(oAVL->root->leftChild), 2);
    EXPECT_EQ(oAVL->Successor(oAVL->root->rightChild->rightChild), -1);
}

TEST(AVL, AVL_searchPredeccessorTest)
{
    /* GIVEN */
    Node* oAVL = new Node;
    
    /* WHEN */
    /* Create tree:
        2
      /   \
     1     3
            \
             4
    */

    oAVL->Insert(2);
    oAVL->Insert(3);
    oAVL->Insert(1);
    oAVL->Insert(4);

    /* THEN */
    EXPECT_EQ(oAVL->Predeccesor(oAVL->root), 1);
    EXPECT_EQ(oAVL->Predeccesor(oAVL->root->rightChild), 2);
    EXPECT_EQ(oAVL->Predeccesor(oAVL->root->leftChild), -1);
}

TEST(AVL, AVL_removeNodeTest)
{
    /* GIVEN */
    Node* oAVL = new Node;
    
    /* WHEN */
    /* Create tree:   After remove and rotate:
        2                   3
      /   \               /   \
     1     3        =>   2     4
            \
             4
    */

    oAVL->Insert(1);
    oAVL->Insert(2);
    oAVL->Insert(3);
    oAVL->Insert(4);
    oAVL->Remove(1);

    /* THEN */
    EXPECT_EQ(oAVL->root->key, 3u);
    EXPECT_EQ(oAVL->root->rightChild->key,4u);
    EXPECT_EQ(oAVL->root->leftChild->key, 2u);
}