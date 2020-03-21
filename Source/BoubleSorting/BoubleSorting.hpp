
#include <iostream>

namespace boubleSort{

/*
*   Bouble sorting algorithm:
(sort min to max version)
The algorithm goes threw list and checks if current element is grater than the next one. If yes, it
swapes the elements and goes to next pair, untill it reaches end of the list. That is how the maximum
element of the whole list goes to the end of the list. Next, the algorithm considers last element
as sorted, and starts whole procedure with swapping from the beggining, but ends previous sorted elements 
(in case of 2nd iteration - last element is not take into account). The algorithm ends when all
elements are sorted (there is no unsorted pair to swap).


Example:

a = [2,3,1]

//Step1:

Take 1st pair (2,3), and, if element 0 (2) > element2(3) swap it. It is not, so the ousput is still [2,3,1].

//Step2:

Go to the next pair. Now we have (3,1). 3 is grater than 1, so it is swaped. The output is [2,1,3].
Now, we have no next pair, so we start from begining and consider last element (3) as sorted.

//Step 3:

We have only one pair left (2,1), and we swap it, and the output is [1,2,3].

As we have no next pairs, we finist the work.
*/

template <typename T>
void Sort(T array[], int arraySize)
{
    bool isSwaped;

    int unsortedElements = arraySize;   //Number of eleents unsorted yet - array size at the begining

    do
    {
        isSwaped = false;

        for(int i = 0; i < unsortedElements; ++i)
        {
            if (array[i] > array[i+1])          //If current element is > next one
            {
                std::swap(array[i], array[i+1]);    //Move curent element closer to list end by swap elements
                isSwaped = true;    
            }
        }

    } while (isSwaped);     //Continue sorting (liss to sort is shorter) untill no element would be swapped
    
}

}