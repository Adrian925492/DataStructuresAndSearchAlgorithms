
/* Binary search algorithm

The algorithm divides input array into 2 subarrays in the middle. The first step is to find middle point, for ex. for 5th element
input array middle point will be element with index 2 (ind starts from 0). Then we check if middle point value is equal to searched value.
If yes, we return with middle value id. If it is less, and list is sorted min to max, we recurively call the algorithm on less subarray. If
it is greter, and we have list sorted min-max, we recurively call the algorithm on right subarray. We end ehen we find element of when
we cannot divide array any more. */

namespace binarySearch{

template <typename T>
int Search(T array[], int startIdx, int endIdx, T value)
{
    if (startIdx <= endIdx)
    {        
        int midValue = startIdx + ((endIdx - startIdx)/2);  //Search for middle value

        if (array[midValue] == value)
        {
            return midValue;            //End searching if midValue is searched value
        }
        else if (array[midValue] > value)
        {
            return Search<T>(array, startIdx, midValue - 1, value);    //If value is less than mid value look in left subarray
        }
        else
        {
            return Search<T>(array, midValue + 1, endIdx, value);      //Else if value is grater than mid value look in right subarray
        }
    }   
    return -1;  //Return -1 if no searched
}

}