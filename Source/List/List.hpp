#ifndef __LIST_HPP_
#define __LIST_HPP_

namespace list {

//Node implementation
template<typename T>
class Node
{
public:
    Node(): value(0), next(nullptr) {}
    Node(T element): value(element), next(nullptr), previous(nullptr) {}
    ~Node(){}

    T value;
    Node<T>* next;
    Node<T>* previous;
};

//List implementation
template <typename T>
class List
{
public:
    List() : head(nullptr), tail(nullptr), _length(0) {}
    ~List(){}

    //Get node
    T get(uint32_t id)
    {
        if ((id > _length) || (_length == 0))
        {
            return (T)NULL;        //Check if id is right
        }

        Node<T>* node = head;   //Init node

        for (uint32_t i = 0; i < id; ++i)    //Iterate threw list to find element with "id"
        {
            node = node->next;
        }

        return node->value;     //Return node value
    }

    //Insert element to id
    void insert(T element, uint32_t id)
    {
        if (id > _length)
        {
            return;     //Check if id is proper
        }

        if (id == 0)
        {
            insertHead(element);    //Add element to head if id = 0
            return;
        }
        else if (id == _length)
        {
            insertTail(element);    //Add element to tail if id = length
            return;
        }

        //If id point not to head or tail

        //Search for previous node before id
        Node<T>* prevNode = head;       //Start form head

        for(uint32_t i = 0; i < id - 1; ++i)
        {
            prevNode = prevNode->next;
        }

        Node<T>* nextNode = prevNode->next; //Search for next node

        Node<T>* node = new Node<T>(element);  //Allocate memory for element

        node->next = nextNode;          //link new node to next node
        node->previous = prevNode;      //link new node t previous node

        nextNode->previous = node;      //Link next node to new node
        prevNode->next = node;         //link prev node to new node

        _length++;                      //Update list length
    }

    //Search for element
    uint32_t search(T element)
    {
        if(_length != 0)                //Check if lenght is > 0
        {
            Node<T>* node = head;       //Start looking from head node

            for(uint32_t i = 0; i < _length; ++i)
            {
                if(node->value == element)
                {
                    return i;           //If found, return index
                }
                node = node->next;      //set search link to next node
            }
        }
        return (T)NULL;                    //Reurn NUL if not found                           
    }

    //Remove element by id
    void remove(uint32_t id)
    {
        if (_length == 0)
        {
            return;                 //Check if lenght is nonzero
        }
        
        if (id == 0)
        {
            removeHead();           //Remove head if index is 0
            return;
        }

        if (id == _length)
        {
            removeTail();           //Remove tail if index == last
            return;
        }

        Node<T>* prevNode = head;   //Start searching prev node from head
        for (uint32_t i = 0; i < id - 1; ++i)
        {
            prevNode = prevNode->next;
        }

        Node<T>* node = prevNode->next; //Point element to delete
        Node<T>* nextNode = node->next;

        prevNode->next = node->next;    //Assign prev node with next node
        nextNode->previous = prevNode;  //Addign prev node with new one 

        delete node;      //Deallocate memory for delete node
        
        _length--;                  //Decrement length
    }

    //Remove current head
    void removeHead()
    {
        if (_length == 0)
        {
            return;                 //Check if lenght is nonzero
        }
        
        Node<T>* oldHead = head;    //save old head - to delocate it later

        head = head->next;          //Set new head to next node

        delete oldHead;             //Dealocate old head

        _length--;                  //Decrement length

        if (_length != 0)
        {
            head->previous = NULL;  //Set head previous to null if any elements occured
        }
    }

    //Remove current tail
    void removeTail()
    {
        if (_length == 0)
        {
            return;                 //Check if lenght is nonzero
        }

        if (_length == 1)           //If len == 1 tail will be head
        {
            removeHead();  
            return;         
        }

        Node<T>* node = tail;   //Looking for prev node
    
        tail = tail->previous;      //Set new tail
        tail->next = nullptr;       //Set current tail node ptr to null

        delete node;      //Deallocate current tail

        _length--;                  //Decrement length
    }
    
    //Insert element to head
    void insertHead(T element)
    {
        Node<T>* node = new Node<T>(element);       //Allocate memory for new node

        node->next = head;                          //Actual node links to previous node

        if (head != nullptr)
        {
            head->previous = node;                      //Link current head with new one
        }

        head = node;                                //Update head pointer - to point new head node
        head->previous = NULL;                      //Set previous of head to NULL

        if (_length == 0)
        {
            tail = head;                            //If list len is 1 - tail is head
        }

        _length++;                                  //Increment length - by added node
    }

    //Insert element to tail
    void insertTail(T element)
    {
        if (_length == 0)
        {
            insertHead(element);                     //If list len is 1 - tail is head
        }
        else
        {
            Node<T>* node = new Node<T>(element);       //Allocate memory for new node

            tail->next = node;          //Link current tail with new tail
            node->previous = tail;      //Link new node previous to old tail
            tail = node;                //Update tail

            _length++;                  //Update length
        }       
    }

    //Get lenght
    uint32_t length()
    {
        return _length;
    }

    Node<T>* head;          //Pointer to head node
    Node<T>* tail;          //Pointer to tail node

private:
    uint32_t _length;       //List length
};


};

#endif