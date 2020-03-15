#ifndef __DOUBLE_SIDE_QUEUE_H_
#define __DOUBLE_SIDE_QUEUE_H_

#include <cstdio>

namespace doubleSideQueue
{

template<typename T>
class Queue
{
public:
    Queue(): _length(0) {}
    ~Queue(){}

    T front()
    {
        if (isEmpty())
        {
            return NULL;        //Check if queue is empty
        }
    }

    T back()
    {
        if (isEmpty())
        {
            return NULL;        //Check if queue is empty
        }
    }

    bool isEmpty()
    {
        return (_length == 0);  //Check if queue is empty
    }
private:
    uint32_t _length;
};



}

#endif