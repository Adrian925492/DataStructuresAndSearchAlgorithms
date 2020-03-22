
namespace lineSearch{

/*
Line search

Line search is very simple algorithm. It iterates threw whole list. If elemnt is found, it returns its id and breakse iteration.
If element is not found and iteration reaches end of the list, the algorithm returns -1. The position of element in list influences
how fast it will be found - closer to beginig of iteration - faster founded. In worst case - there is no element on the list - 
the algorithm will iterate times equal array length 
*/

template <typename T>
int Search(T array[], int startIdx, int endIdx, T value)
{
    for (int i = startIdx; i < endIdx; ++i)         //Iterate threw whle list
    {
        if (array[i] == value)          //If element found
        {
            return i;                   //Break search and return id
        }
    }
    return -1;      //If not, return -1
}

}