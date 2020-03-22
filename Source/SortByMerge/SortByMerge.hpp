
namespace sortByMerge{

/*
SortByMerge
(min to max)

In sort by merge, the algorithm devides (if can) inu array into two subarays, and tha, if it is possible, divides 
each subarray into 2 subarrays untill the subarays cannot be divided (has length of 1). The
array/subarrays are divided only if it can be divided by 2. Than it sorts each divided subarray and merges it into one, sorted
array. The merging algorithm also sorts merged arrays.

The sorting method is efficiendt beacouse sorted are small arrays. Only merge is cost efficient, beacouse during merge the 
elements has to be reordered if needed, but merigng large subarrays they are already sorted, so merging is faster.

//Step1:


Divide array into subarrays if it is possible.

//Step2:
Sort each subarray

//Step3:
Merge smallest subarrays into larger subarrays, reorder elements. Repeat merging untill obtaining 
full merged, sorted array.

*/


/* Merging function. It gets array array[]. strat index is id of 1st element of 1st sorted subarray to merge.
end index is last element of 2nd subarray to merge, and middle index is last element of left subarray to be merged.
Merge functions merges 2 subarrays laying next to each other, which are part of array and has been already sorted. */
template <typename T>
void Merge(T array[], int startIndex, int midIndex, int endIndex)   
{
    int totalElements = endIndex - startIndex + 1;  //Number of elements in both subarrays to merge

    T* tempArray = new T(totalElements);            //Alloc memory for effect of merging - it will be copied here

    int leftIndex = startIndex;                     //Set left index of left subarray - initial start index

    int rightIndex = midIndex + 1;                  //Set 1st element of rignt subarray - middle index + 1

    int mergedIndex = 0;                            //Set merged index - current index of merged table

    while(leftIndex <= midIndex && rightIndex <= endIndex)  //Loop untill reaching end of both subarrays
    {
        if (array[leftIndex] <= array[rightIndex])
        {
            tempArray[mergedIndex] = array[leftIndex];      //If left index if < right index, put element to merged table on the left side
            leftIndex++;                                    //And go to next element of left index
        }    
        else    //If right array element of curr idx is grater than left array element of curr left index
        {
            tempArray[mergedIndex] = array[rightIndex];     //Put right index element to array
            rightIndex++;                                   //And increment right index
        }
        ++mergedIndex;      //Go to next element of merged table
    }

    while(leftIndex <= midIndex)    //If any elemnt left unchecked in left subarray
    {
        tempArray[mergedIndex] = array[leftIndex];    //Assign it to merged array
        ++leftIndex;
        ++mergedIndex;
    }

    //Or

    while(rightIndex <= endIndex)   //If any elemnt right unchecked in left subarray
    {
        tempArray[mergedIndex] = array[rightIndex];  //Assign it to merged array
        ++rightIndex;
        ++mergedIndex;
    }

    //Now we have merged elements in temp array

    //We have to copy temp array to original array
    for (int i = 0; i < totalElements; ++i)
    {
        array[startIndex + i] = tempArray[i];
    }

    delete [] tempArray;     //And dealloc temp array
}

/* Functon that sorts and merges array. The function divides array recursively untill it can be and merges sorted subarrays */
template <typename T>
void Sort(T array[], int startIndex, int endIndex)
{
    if (startIndex >= endIndex)
    {
        return;         //Check if subarray to sort has some length. If not, return
    }

    int middleIndex = (startIndex + endIndex)/2;    //Find 

    Sort<T>(array, startIndex, middleIndex);   //Sort (or merge) left subarray

    Sort<T>(array, middleIndex+1, endIndex);   //Sort (or merge) right subarray

    Merge<T>(array, startIndex, middleIndex, endIndex);     //Merge sorted subarrays
}

}