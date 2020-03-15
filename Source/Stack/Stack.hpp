#ifndef __STACK_HPP_
#define __STACK_HPP_

#include <cstdint>

namespace stack {

template <typename T>
class Node
{
public:
    Node(): value(NULL), next(nullptr) {}
    ~Node(){}
    T value;
    Node<T>* next;
};

template <typename T>
class Stack
{
public:
    Stack(): _length(0) {}
    ~Stack(){}

    void push(T element)
    {

    }

    void pop()
    {

    }

    T getTop()         //Returns top value of the stack
    {
        if (!isEmpty())   //Check if stack is not empty
        {
            return top->value;
        }
        return NULL;
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