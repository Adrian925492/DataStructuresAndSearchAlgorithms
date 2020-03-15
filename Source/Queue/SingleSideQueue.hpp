#ifndef __SINGLE_SIDE_QUEUE_HPP_
#define __SINGLE_SIDE_QUEUE_HPP_

#include <cstdint>

namespace singleSideQueue
{

template <typename T>
class Node
{
public:
    Node(T element): value(element), next(nullptr){}
    Node(): value(NULL), next(nullptr){}
    ~Node(){}
    T value;
    Node<T>* next;
};

template <typename T>
class Queue
{
public:
    Queue(): _length(0), _front(nullptr) {}
    ~Queue(){}

    void enqueue(T element)
    {
        Node<T>* node = new Node<T>(element);   //Allocate space for new node
        
        if (_length == 0)       //Check if new node is the first one
        {
            _front = node;
        }
    }

    T front()
    {
        if (isEmpty())
        {
            return NULL;    //Return NULL if queue is empty
        }
        return _front->value;   //Return front node value
    }

    bool isEmpty()
    {
        return (_length == 0);  //Return true if queue is empty
    }
private:
    uint32_t _length;
    Node<T>* _front;
};

}

#endif