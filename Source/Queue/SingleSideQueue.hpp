#ifndef __SINGLE_SIDE_QUEUE_HPP_
#define __SINGLE_SIDE_QUEUE_HPP_

#include <cstdint>

namespace singleSideQueue
{

template <typename T>
class Node
{
public:
    Node(T element): value(element), previous(nullptr){}
    Node(): value(NULL), previous(nullptr){}
    ~Node(){}
    T value;
    Node<T>* previous;
};

template <typename T>
class Queue
{
public:
    Queue(): _length(0), _front(nullptr), _back(nullptr) {}
    ~Queue(){}

    void enqueue(T element)
    {
        Node<T>* node = new Node<T>(element);   //Allocate space for new node
        
        if (isEmpty())       //Check if new node is the first one
        {
            _front = node;      //Both front and back is now node
            _back = _front;   
        }
        else
        {
            _back->previous = node;     //Assign previous back as next node to new node 

            _back = node;           //Assign back pointer to node
        }       
        _length++;              //Increment lenght
    }

    void dequeue()
    {
        if (isEmpty())
        {
            return;             //Return if queue is empty
        }

        Node<T>* node = _front; //Remember old front

        _front = node->previous;  //Link next after front as new front

        delete node;            //Deallocate old front

        _length--;              //Reduce length
    }

    T front()
    {
        if (isEmpty())
        {
            return (T)NULL;    //Return NULL if queue is empty
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
    Node<T>* _back;
};

}

#endif