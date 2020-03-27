
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
};

}