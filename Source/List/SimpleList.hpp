#ifndef __SIMPLE_LIST_HPP
#define __SIMPLE_LIST_HPP

#include <cstdint>

/*
*   Simple list implementation - based on standard C array.
* List methods:
* Insert(element, id) <- Adds element to list in specified id
* Remove(id) <- removes element by its id
* Search(element) <- searches for element "element"
* Get(id) <- returns element with "id"
*/

template <typename T>
class SimpleList_t
{
public:
    SimpleList_t(){}
    SimpleList_t(uint32_t len): _length(len)
    {
        _elements = new T[_length];  
    }
    
    T get(uint32_t id)
    {
        if (id < _length)
        {
            return _elements[id];
        }
        return NULL;  //Return NULL if invalid element!
    }
    void insert(T element, uint32_t id)
    {

    }
    int search(T element)
    {

    }
    void remove(uint32_t id)
    {

    }

private:
    uint32_t _length;
    T* _elements;    
};



#endif