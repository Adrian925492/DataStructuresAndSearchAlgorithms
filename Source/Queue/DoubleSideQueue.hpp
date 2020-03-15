#ifndef __DOUBLE_SIDE_QUEUE_H_
#define __DOUBLE_SIDE_QUEUE_H_

#include <cstdio>

namespace doubleSideQueue
{

template <typename T>
class Node
{
public:
    Node(): value(NULL), next(nullptr), previous(nullptr) {}    
    Node(T element): value(element), next(nullptr), previous(nullptr) {}
    ~Node(){}

    T value;
    Node<T>* next;
    Node<T>* previous;
};

template<typename T>
class Queue
{
public:
    Queue(): _length(0), _front(nullptr), _back(nullptr) {}
    ~Queue(){}

    void pushToFront(T element)
    {
        Node<T>* node = new Node<T>(element);  //Allocate memory for new node

        if (isEmpty())  //Check if queue is empty
        {
            _front = node;              // New node is now front and back
            _back = node;
        }
        else
        {
            _front->next = node;        //Link current front to new node

            node->previous = _front;    //Lint new front node to current one

            _front = node;              //Move front link to new node
        }
        _length++;      //Increment nr of items
    }

    void pushToBack(T element)
    {
        Node<T>* node = new Node<T>(element);  //Allocate memory for new node

        if (isEmpty())  //Check if queue is empty
        {
            _front = node;              // New node is now front and back
            _back = node;                   
        }
        else
        {
            _back->previous = node;     //Assign previous back node to new node

            node->next = _back;         //Assign new node to previous back node

            _back = node;               //Move back node pointer to new back node
        }
        _length++;      //Increment nr of items
    }

    void popFront()
    {
        if (isEmpty())
        {
            return;        //Check if queue is empty
        }
        
        Node<T>* node = _front; //Save current front

        _front = _front->previous;  //Move current front one backward

        _front->next = nullptr;     //Set current front next to nullptr

        delete node;            //Dealloc memory for last front

        _length--;              //Decrement queue length
    }

    void popBack()
    {
        if (isEmpty())
        {
            return;        //Check if queue is empty
        }
        
        Node<T>* node = _back; //Save current back

        _back = _back->next;  //Move current front one backward

        _back->previous = nullptr;  //Set current back previous to nullptr

        delete node;            //Dealloc memory for last back

        _length--;              //Decrement queue length
    }

    T back()
    {
        if (isEmpty())
        {
            return NULL;        //Check if queue is empty
        }
        return _back->value;   //Return value
    }

    T front()
    {
        if (isEmpty())
        {
            return NULL;        //Check if queue is empty
        }
        return _front->value;   //Return value
    }

    bool isEmpty()
    {
        return (_length == 0);  //Check if queue is empty
    }
private:
    uint32_t _length;
    Node<T>* _front;
    Node<T>* _back;
};



}

#endif