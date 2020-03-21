#include <iostream>

/*
Sort by choose algorithm:
(min to max sort)
As in bouble algorithm, the algorithm divides array into two places - sorted and unsorted yet part.
Sorted part is on tle left side (in that case). The algorithm goes threw each element
of input array looking for minimum value and swapping it to be placed on the first place of unsorted part of
array. The minnimum value id is initially assigned to first element of unsirted part of array. If, during
going threw array, the algorithm find less value, it is swaped and id is assigned to new minimum.

//Step1:
Start looking for min value of the array. Assign id of min value on the first place (id == 0).

//Step2: Go threw each element of unsorted part of array (whole arrayat the begining). If any element is less than element
pointed by id of min value, swap it with 1st element of unsorted part of array and assign its id as min id.

//Step3: After goint to end of array at the first place we have min value. Consider 1st element as sorted part of array
and continue steps 1-3 on unsorted part of array, untill whole array will be sorted.

*/


namespace sortByChoose{

template <typename T>
void Sort(T array[], int arraySize)
{
    int minIndex;       //Index of currently known minimum value from array

    for (int i = 0; i < arraySize - 1; ++i)
    {
        minIndex = i;   //Assign minimum index - first element of unsorted part of array

        for (int j = i + 1; j < arraySize; ++j)     //Iterate threw unsorted array to find nim index
        {
            if (array[j] < array[minIndex])         //If element is < than element with index minIndex
            {
                minIndex = j;                       //Assig new minIndex
                std::swap(array[i], array[minIndex]);     //Swap found element with first from unsirted sublist
            }
        }
    }
}

}