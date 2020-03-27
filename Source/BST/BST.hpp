#include <vector>

namespace bst{

class Node
{
public:
    Node* root;
    Node* leftChild;
    Node* rightChild;
    Node* parent;
    int key;

    Node(): root(nullptr), leftChild(nullptr), rightChild(nullptr), parent(nullptr), key(0) {}

    Node* Insert(Node* node, int value)
    {
        if (node == nullptr)       //If node has no child - add node
        {
            node = new Node;
            node->leftChild = nullptr;
            node->rightChild = nullptr;
            node->parent = nullptr;
            node->key = value;
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

        return node;
    }

    Node* Insert(int value)     //Overload the function - for comfort use
    {
        root = Insert(root, value);
    }

    /* Get all elements (min to max) */
    void GetAllEements(Node* node, std::vector<int>* output)
    {
        if (node == nullptr)
        {
            return;     //No more nodes to present so return
        }

        GetAllEements(node->leftChild, output);     //Firsty get element from left child

        output->push_back(node->key);               //Than attach current key

        GetAllEements(node->rightChild, output);    //Get elements from right child
    }

    void GetAllEements(std::vector<int>* output)
    {
        GetAllEements(root, output);
    }

    /* Search for value in BST */
    Node* Search(Node* node, int value)
    {
        if (node == nullptr)
        {
            return nullptr;   //Return false, element not found
        }

        else if (node->key == value)
        {
            return node;    //Return true - element found
        }

        else if (node->key < value)
        {
            return Search(node->rightChild, value);    //Binary search - if value is grater than key, look for it in right subarray
        }
        else if(node->key > value)
        {
            return Search(node->leftChild, value);     //Bianry search - of value is less than key, search it in left subarray
        }
    }

    bool Search(int value)
    {
        if(Search(root, value) != nullptr)
        {
            return true;
        }
        return false;
    }

    //Look for min value in tree
    int SearchMinValue(Node* node)
    {
        if (node == nullptr)
        {
            return -1;      //Tree is empty, so return -1
        }  

        if (node->leftChild != nullptr)
        {
            return SearchMinValue(node->leftChild);     //Have some left child - search in it
        }
        else
        {
            return node->key;           //No more left child - here we have min value!
        }    
    }

    int SearchMinValue(void)
    {
        return SearchMinValue(root);
    }

    //Look for max value in tree
    int SearchMaxValue(Node* node)
    {
        if (node == nullptr)
        {
            return -1;      //Tree is empty, so return -1
        }
        if (node->rightChild != nullptr)
        {
            return SearchMaxValue(node->rightChild);     //Have some right child - search in it
        }
        else
        {
            return node->key;           //No more right child - here we have min value!
        }
    }

    int SearchMaxValue(void)
    {
        return SearchMaxValue(root);
    }
};

}