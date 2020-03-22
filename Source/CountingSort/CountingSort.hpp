

namespace countingSort{

/* Sort by counting algorithm
(min - max sort)

The algorithm is simple. First step is to find min and max value. We have to allocate memory for array, which size woll be
equal to max - min value fount in input array. Then we have to count number of occurences of each value in inpub array
between min and max found in prev steps. Results of searching we paste to allocated array for example number of occurences of
min value we write into 1st position in allocated array, and so on. Than we can use the allocated array to return elements
to input array. We start from min value stored in 1st element of allocated array. Number of occurences writteh in allocated array
is number of fields that will be putted into input array of the vale. We continue process untill we reach max value. */

template <typename T>
void Sort(T array[], int arraySize)
{
    T minVal = array[0];       //Initialize min value
    T maxVal = array[0];       //Initialize max value

    for (int i = 0; i < arraySize; ++i)     //Look for min and max value
    {
        if (array[i] < minVal)
        {
            minVal = array[i];
        }
        else if (array[i] > maxVal)
        {
            maxVal = array[i];
        }
    }

    int nrOfValues = maxVal - minVal;   //Total number of values in input array

    T* countingResults = new T[nrOfValues]();   //allocate space for counting array with zero - initialize

    for (int i = 0; i < arraySize; ++i)
    {
        ++countingResults[array[i] - minVal];   //Calculte nr of occurences
    }

    int arrayCounter = 0;                       //Array counter
    for (int i = 0; i < nrOfValues; ++i)        //Iterate threw counting values array to return values
    {
         while (countingResults[i] > 0)
         {
             array[arrayCounter++] = i + minVal; //Return values to input array
             --countingResults[i];
         }
    }

    delete [] countingResults;
}

}