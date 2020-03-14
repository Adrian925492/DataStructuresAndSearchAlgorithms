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
   
   SimpleList_t(): _length(0), _elements(nullptr){}
    ~SimpleList_t(){}

    T get(uint32_t id)
    {
        if (id < _length)
        {
            return _elements[id];
        }
        return (T)(NULL);  //Return NULL if invalid element!
    }

    void insert(T element, uint32_t id)
    {
        if (id > _length)
        {
            return;                 //Return if wrong id typed
        }
        
        T* oldArray = _elements;    //Copy old table

        _elements = new T[_length + 1]; //Allocate size for new array

        //Copy data to new array
        for (uint32_t i = 0, j = 0; i < _length + 1; ++i)
        {
            if (id == i)
            {
                _elements[i] = element;
            }
            else
            {
                _elements[i] = oldArray[j];
                ++j;
            }   
        }

        if (_length > 0)
        {
            delete [] oldArray;         //Dealloc old array
        }

        _length++;                  //Increment list size
    }
    int search(T element)
    {
        for(uint32_t i = 0; i < _length; ++i)
        {
            if (_elements[i] == element)
            {
                return i;
            }
        }
        return NULL;
    }
    void remove(uint32_t id)
    {
        if (id > _length)
        {
            return;     //Check if id is in bounds
        }

        T* oldArray = _elements;    //Copy elements

        _elements = new T[_length - 1];     //Allocate space

        //Copy elements
        for (uint32_t i = 0, j = 0; i < _length - 1; ++i, ++j)
        {
            if (id == j)
            {
                ++j;
            }
                _elements[i] = oldArray[j];          
        }

        if (_length > 0)
        {
            delete [] oldArray;     //Deallocate space
        }

        _length--;
    }

private:
    uint32_t _length;
    T* _elements;    
};



#endif