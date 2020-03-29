#include "../BST/BST.hpp"

#include <iostream>
using namespace std;

namespace avl{

class Node : public ::bst::Node
{
public:
    Node(): ::bst::Node() {}

    int getHeight(::bst::Node* node)
    {
        return node == nullptr ? 
        -1 :
        node->height;        //Height getter
    }

    ::bst::Node* rotateLeft(::bst::Node* node)
    {
        //The node has to have right child

        ::bst::Node* balancedNode = node->rightChild;  //Right child become "root" node in contex of subtree

        balancedNode->parent = node->parent;    //Assign new subtree root parent
        node->parent = balancedNode;            //Assign parent of our node as new subtree root
        node->rightChild = balancedNode->leftChild; //Move child of balanced node to subnode (old root node)

        if (balancedNode->leftChild != nullptr)     //If balanced node has left child
        {
            balancedNode->leftChild->parent = node; //Assign its parent to node
        }

        balancedNode->leftChild = node;         //And assign old node as left child of balanced node

        node->height = std::max(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;   //Refresh height of the node
        balancedNode->height = std::max(getHeight(balancedNode->leftChild), getHeight(balancedNode->rightChild)) + 1;   //Refresh balanced node height

        return balancedNode;
    }

    ::bst::Node* rotatrRight(::bst::Node* node)
    {
        //The node has to have left child

        ::bst::Node* balancedNode = node->leftChild;  //Right child become "root" node in contex of subtree

        balancedNode->parent = node->parent;   //Assign new subtree root parent
        node->parent = balancedNode;           //Assign parent of our node as new subtree root
        node->leftChild = balancedNode->rightChild;  //Move child of balanced node to subnode (old root node)

        if (balancedNode->rightChild != nullptr)     //If balanced node has right child
        {
            balancedNode->rightChild->parent = node; //Assign its parent to node
        }

        balancedNode->rightChild = node;         //And assign old node as right child of balanced node

        node->height = std::max(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;   //Refresh height of the node
        balancedNode->height = std::max(getHeight(balancedNode->leftChild), getHeight(balancedNode->rightChild)) + 1;   //Refresh balanced node height

        return balancedNode;
    }

    ::bst::Node* Insert(::bst::Node* node, int value)
    {
        if (node == nullptr)       //If node has no child - add node
        {
            node = new ::bst::Node;
            node->leftChild = nullptr;
            node->rightChild = nullptr;
            node->parent = nullptr;
            node->key = value;
            node->height = 0;
        }
        else if (node->key < value)   //If key is less than our key - go to left subtree
        {
            node->rightChild = Insert(node->rightChild, value);  //Call insert recursively - left subtree
            node->rightChild->parent = node;
        }
        else //Key is grater than our key - go to right subtree
        {
            node->leftChild = Insert(node->leftChild, value);  //Call insert recursively - right subtree
            node->leftChild->parent = node;
        }

        int balance = getHeight(node->leftChild) - getHeight(node->rightChild); //Calculate balance

        if (balance == 2)   //Left if overloaded
        {
            int balance2 = getHeight(node->leftChild->leftChild) - getHeight(node->leftChild->rightChild);  //Balance of left subtree

            if (balance2 == 1)  //Left subtree is balanced
            {
                node = rotatrRight(node);
            }
            else    //Left subtree is not balanced
            {
                node->leftChild = rotateLeft(node->leftChild);      //Rotate the left subtree first to balance it
                node = rotatrRight(node);
            }
        }
        else if (balance == -2)     //Right is overloaded
        {
            int balance2 = getHeight(node->rightChild->leftChild) - getHeight(node->rightChild->rightChild);    //Balance of right subtree

            if (balance2 == -1)     //Right subtree is balanced
            {
                node = rotateLeft(node);
            }
            else    //Right subtree is not balanced
            {
                node->rightChild = rotatrRight(node->leftChild);    //Rotate the right tree first to balance it
                node = rotateLeft(node);
            }
        }

        /* Refresh height */
        node->height = std::max(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;

        return node;
    }

    void Insert(int value)
    {
        root = Insert(root, value);
    } 

    /* Remove node */
    ::bst::Node* Remove(::bst::Node* node, int value)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (node->key == value)
        {
            if (node->rightChild == nullptr && node->leftChild == nullptr)
            {
                node = nullptr;        //Case 1: node is leaf
            }
            else if (node->leftChild == nullptr && node->rightChild != nullptr)
            {
                node->parent->rightChild = node->rightChild;
                node = node->rightChild;
            }
            else if (node->leftChild != nullptr && node->rightChild == nullptr)
            {
                node->parent->leftChild = node->leftChild;
                node = node->leftChild;
            }
            else
            {
                int succesorKey = Successor(node);

                node->key = succesorKey;

                node->rightChild = Remove(node->rightChild, succesorKey);
            }
        }
        else if (node->key < value)
        {
            node->rightChild = Remove(node->rightChild, value);     //Look for key in right subtree
        }
        else if (node->key > value)
        {
            node->leftChild = Remove(node->leftChild, value);     //Look for key in right subtree
        }

        if (node != nullptr)    //If root was not removed
        {
            int balance = getHeight(node->leftChild) - getHeight(node->rightChild); //Check balance   

            if (balance == 2)
            {
        /* Example of such balance == 2:        balance == 2
        balance2 = 1 - 0 = 1                    balance2 != 1 - 1 = 0
                3                                   3
               / \                                 /  \
              2   5                               2    5
             /                                   / \
            1                                   1   4
           /                                   /
          0                                   0
          */
                int balance2 = getHeight(node->leftChild->leftChild) - getHeight(node->leftChild->rightChild);

                if (balance2 == 1)
                {
                    node = rotatrRight(node);
                }
                else
                {
                    node->leftChild = rotateLeft(node->leftChild);
                    node = rotatrRight(node);
                }
                
            }
            else if (balance == -2)     //Right is overloaded
            {
                int balance2 = getHeight(node->rightChild->leftChild) - getHeight(node->rightChild->rightChild);    //Balance of right subtree

                if (balance2 == -1)     //Right subtree is balanced
                {
                    node = rotateLeft(node);
                }
                else    //Right subtree is not balanced
                {
                    node->rightChild = rotatrRight(node->leftChild);    //Rotate the right tree first to balance it
                    node = rotateLeft(node);
                }
            }

            /* Refresh height */
            node->height = std::max(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;

        }

        return node;
    }

    void Remove(int value)
    {
        root = Remove(root, value);
    }
};


}