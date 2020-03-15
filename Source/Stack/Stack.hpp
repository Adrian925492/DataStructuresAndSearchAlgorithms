#ifndef __STACK_HPP_
#define __STACK_HPP_

#include <cstdint>

namespace stack {

template <typename T>
class Node
{
public:
    Node(): value(NULL), previous(nullptr) {}
    Node(T element): value(element), previous(nullptr) {}
    ~Node(){}
    T value;
    Node<T>* previous;
};

template <typename T>
class Stack
{
public:
    Stack(): _length(0) {}
    ~Stack(){}

    void push(T element)
    {
        Node<T>* node = new Node<T>(element);       //Allocate memory and create node

        node->previous = top;       //Point new node previous to current top of the stack - add to chain

        top = node;                 //Point top to new node

        _length++;                  //Increment length
    }

    void pop()
    {
        if (!isEmpty())             //Check if stack is not emty
        {
            Node<T>* node = top;        //Remember current top

            top = node->previous;       //Set top to previous one

            delete node;                //Dealloc space for previous node

            _length--;                  //Decrease lenght
        }
    }

    T getTop()         //Returns top value of the stack
    {
        if (!isEmpty())   //Check if stack is not empty
        {
            return top->value;
        }
        return (T)NULL;
    }

    bool isEmpty()
    {
        return (_length == 0);
    }
private:
    uint32_t _length;
    Node<T>* top;
};

}

#endif