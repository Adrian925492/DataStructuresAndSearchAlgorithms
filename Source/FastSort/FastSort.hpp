
#include <iostream>

namespace fastSort{

/*
Fast sort algorithm
(min - max sorting)

Fast sorting algorithm divides the input array into 2 subarrays. First step is to choose pivot element. It can be 1st element fo the array.
Next the algorithm checks every elements left in array. If the element is less than pivot, it has to stay in left subaray. If the element is
grater, it has to stay in right subarray. If element is less, the id of last element of left subarray is incremented (we increase
left subarray), and the element is swapped with element which has been the fisrt element in right subarray. Thet process is done
for each element in subarray left and is named partitioning. To end partitioning we have to take care the pivot eleent. To do that we swap
last element of left subarray with pivot element. Now, all elements less than pivot are on the left side (left subarray), and grater - 
on right side (right subarray). If the list is not sorted, we call recursively partitioning algorithm on both - left and right subarrays, but wo. pivot element
The recursive call will end when the subarray called to partitioning will have length of 1 - means canot be partitioned any more.


/*
The function partitions the array defined by startIndex up to endIndex
*/
template <typename T>
int Partition(T array[], int startIndex, int endIndex)
{
    int pivot = array[startIndex];      //Pivot choice (dividing element). In that case - 1st element of array

    int middleIndex = startIndex;       //Middle index id. At the begining it is start index, so we have no
                                        //element in left subarray, and whole elements are in right subarray

    for (int i = startIndex + 1; i <= endIndex; ++i)    //We check rest of elements of the array
    {
        if (array[i] < pivot)           //If the element is less than pivot, we just move middle index - so now 
        {                               //the array will be divided in place 1 right 
            ++middleIndex;

            std::swap(array[i], array[middleIndex]);    //And we swap element with middle index element. So the element is now in left subarray.
        }
    }
    
    std::swap(array[middleIndex], array[startIndex]);       //We and partitioning by swapping pivot element with last elem of left subarray

    return middleIndex;         //Return middle index. It will be used in next sorting.
}

template <typename T>
void Sort(T array[], int startIndex, int endIndex)
{
    if (startIndex >= endIndex)
    {
        return;     //Check if array has some elements to sort. If not, return.
    }
    
    int pivotIndex = Partition<T>(array, startIndex, endIndex);     //Make first partitioning

    //Sort left and right partitioned subarray recurively. Skip pivot index.
    Sort<T>(array, startIndex, pivotIndex - 1);

    Sort<T>(array, pivotIndex + 1, endIndex);
}

}