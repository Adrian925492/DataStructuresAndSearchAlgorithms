
namespace jumpingSearch{

#include "../LineSearch/LineSearch.hpp"
#include <iostream>

/* Jumping search

The algorithm divides input array into several equal blocks (subarrays). The input array has to be sorted (in the exmple min to max).
Then, the algorithm starts from last element of first subarray and checks if it is less than searched value. If tyes, it goes to next
block and checks last element of next block and so on, untill i finds element which is grater than searched for. If it finds it,
the algorithm uses line search and passes to line search last block (the one for which last value was grater than looked for value).

*/

template <typename T>
int Search(T array[], int startIdx, int endIdx, T value)
{
    int arrayLength = (endIdx - startIdx) + 1;        //Find array lenght (+1 - array indexing starts from 0)

    if (arrayLength <= 0)
    {
        return -1;      //Break if array size is zero or less
    }

    int step = sqrt(arrayLength);   //Find number of blocks

    int blockIdx = startIdx;               //Start compare from index equal to end

    while(blockIdx < arrayLength && array[blockIdx] <= value)
    {
        blockIdx += step;   //Decrement block index by block step as long as index value is less than searched value     
    }
    return lineSearch::Search<T>(array, blockIdx - step, std::min(blockIdx, arrayLength), value);   //Use line search for found block
}

}