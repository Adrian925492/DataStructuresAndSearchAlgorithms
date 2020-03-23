
namespace tetrarySearch{

/* Tetrary search

The algorithm divides input array into 3 equal subarrays. If the searched value is one of divide points, the dcoressponding divide point
id is returned. Otherwise, the algorithm checks in which subarray the searched value lays, and than, recursively calls itself on
searched subarray.

*/

template <typename T>
int Search(T array[], int startIdx, int endIdx, T value)
{
    if (startIdx <= endIdx)     //Check if start odx is not grater then end
    {
        int leftMidId = startIdx + ((endIdx - startIdx)/3);         //Find left middle index
        int rightMidId = startIdx + (2*((endIdx - startIdx)/3));    //Find right middle index

        if(array[leftMidId] == value)
        {
            return leftMidId;       //If left mid index is looked for value, return if
        }
        else if (array[rightMidId] == value)
        {
            return rightMidId;      //If right mid index is looked for value, return it
        }
        else if (value < array[leftMidId])  //If value is less than left divide point
        {
            return Search<T>(array, startIdx, leftMidId - 1, value);    //Recurively call algorithm on left subarray
        }
        else if (value > array[rightMidId]) //If the value is grater than right divide point
        {
            return Search<T>(array, rightMidId + 1, endIdx, value);     //Recursively call algorithm on rigth subarray
        }
        else        //If the value is in the middle between left and right middle index values
        {
            return Search<T>(array, leftMidId + 1, rightMidId - 1, value);  //Recursively call algorithm on middle subarray
        }
        
    }
    return -1;
}

}