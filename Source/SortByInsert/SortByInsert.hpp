
/*
Sort by Insert
(min to max)

In algorithm we also divide input array into sorted and unsorted subarray. Sorted subarray is on the left. The
1st value after sorted array is called reference value. When we start, we assume 1st element as sorted subarray, and 2nd
element of the array as reference value. Than, we go threw sorted part of array starting from element closest to
reference value. If reference value is less than currently iterated element of sorted subarray, the value is copied to place on the right.
Than we chech again if next value after copy is grater as algorithm does. If it is not grater, than the check is break without
checking rest of sorted subarray. The reference valur is copied to place of last copied value, means last
checked value + 1. If last checked value was value just after reference, the reference value will be 
just copied to its original place (j+1). The sorted subarray is extendedn by last ref vale and next reference value is choosen and whole
proces is done again, untill reaching end of array (untill reference value will be last value of the array).

//Step1:
Consider 1st element of the array as sorted subarray

//Step2:
Consider next element after end of sorted subarray as reference value (2nd element). Remember reference value.

//Step3:
Go threw sorted subarray and compare reference value with values from sorted subarray. Stert from value closest
to reference value ang go with checking up to 1st element of the sorted subarray.
If currently checked value of sorted subarray is grater than current reference value, copy the checked value into
place on the right of it. Continue procedure untill reach element in sorted subarray which is not grater than reference value.
Than assign reference value to place of last copied element of sorted array (currently checked + 1).

//Step4:
Continue step 3 untill reaching end of array (ref value will be last value)

*/

namespace sortByInsert{

template <typename T>
void Sort(T array[], int arraySize)
{
    T refValue;      

    for (int i = 0; i < arraySize; ++i)
    {
        refValue = array[i];  //Assign reference value

        int j;
        for (j = i - 1; j >= 0; --j)
        {
            if (array[j] > refValue)    //If current checked val is  ref val
            {
                array[j+1] = array[j];   //Move curr checked val into palce of ref val
            }
            else
            {
                break;      //Else break the loop
            }
        }
        array[j + 1] = refValue;        //Move value just before braking the loop to ref val place
    }
}

}