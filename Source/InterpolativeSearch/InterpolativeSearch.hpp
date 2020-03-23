
namespace interpolativeSearch{

/*
Interpolative search

The interpolative search is very similar to binary search. The only difference is way of looking for divide point. In
interpolative search it is not in the middle, but is calculated due to interpolation formula. The rest of searching mechaism is the
same as in binary search. Due to use of interpolation formula search can be done in less recursive steps than in standard binary
search.

*/

template <typename T>
int Search(T array[], int startIdx, int endIdx, T value)
{
    if (startIdx <= endIdx)
    {        
        int midValue = startIdx + \
        ((value - array[startIdx])*(endIdx - startIdx)/(array[endIdx] - array[startIdx]));  //Search for middle value - interpolation

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