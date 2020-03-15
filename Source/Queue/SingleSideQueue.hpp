#ifndef __SINGLE_SIDE_QUEUE_HPP_
#define __SINGLE_SIDE_QUEUE_HPP_

#include <cstdint>

namespace singleSideQueue
{

template <typename T>
class Queue
{
public:
    Queue(): _length(0) {}
    ~Queue(){}

    T front()
    {
        if (isEmpty())
        {
            return NULL;    //Return NULL if queue is empty
        }
    }

    bool isEmpty()
    {
        return (_length == 0);  //Return true if queue is empty
    }
private:
    uint32_t _length;
};

}

#endif