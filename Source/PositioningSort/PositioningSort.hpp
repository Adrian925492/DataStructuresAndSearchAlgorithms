
namespace positioningSort{

#include "../Queue/DoubleSideQueue.hpp"

/*
Positioning sorting
(min to max)

Good for values from large range (ex. 1 to 99999). The algorithm uses set of double side queues. It has 10 queues alocated. Each
queue is a container for data with curently checked number of 0 - 9. We start checking from least significant number of each value 
in input array For example, least significant number of 1024 will be 4. We put all values with the same least significant numbers to 
queue for the number, but the values has to be putted starting from min value up to max value. After that we dequeue each queue
starting from back (as less value was enqued as first, now it will be dequed as first). We continue process with 2nd, 3rd number
and so on untill we check all values according to most significant value of the largest value in input array. 

*/

template <typename T>
void Sort(T array[], int arraySize)
{
    doubleSideQueue::Queue<int>* buckets = new doubleSideQueue::Queue<int>[10]();  //Allocate space for queues

    T maxElement = array[0];
    for (int i = 0; i < arraySize; ++i)     //Look for max element
    {
        if (array[i] > maxElement)
        {
            maxElement = array[i];
        }
    }

    for (int exp = 1; maxElement/exp > 0; exp *= 10)    //Iterate threw elements using exp value (exp = 1, 10, 100 etc...) untill max element cannot be divided threw it
    {
        for (int i = 0; i < arraySize; ++i)     //Iterate threw array elements
        {  
            buckets[(array[i]/exp)%10].pushToFront(array[i]);     //Enque elements
        }

        int arrCounter = 0;
        for (int i = 0; i < 10; ++i)    //Restore (dequeue) array
        {
            while (!buckets[i].isEmpty())
            {
                array[arrCounter++] = buckets[i].back();    //Deque elements from queues from the bckk

                buckets[i].popBack();       //And populate dequed element
            }
        }
    }

    delete [] buckets;      //Free memory for buckets
}

}