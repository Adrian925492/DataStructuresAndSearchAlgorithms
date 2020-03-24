
#include "../BinarySearch/BinarySearch.hpp"
#include <iostream>

/* Expotential search

Similar to jumping search. Here the algorithm also divides input array into sections, but subsections has expotentially
growing length. Start sublist lenght is 1 (0,1), next is *2 (2,3,4,5), and so on... If the element will be identified as existing
inside sublist, the algorithm uses binary search to localise it in sublist. Sorted list (min-max in that case) is required as input.*/

namespace expotentialSearch{

template <typename T>
int Search(T array[], int startIdx, int endIdx, T value)
{
    if (endIdx <= startIdx)
    {
        return -1;      //Return -1 if array has lenght 0
    }

    int arraySize = (endIdx - startIdx) + 1;  //Calculate array size

    int blockIndex = 1;     //Initial block index

    while(blockIndex < arraySize && array[blockIndex] < value)
    {
        blockIndex *= 2;        //Expotentially increment block index untill end of list
    }

    return binarySearch::Search<T>(array, blockIndex/2, std::min(blockIndex, arraySize), value);       //Recursive call binary search on searched block

}

}