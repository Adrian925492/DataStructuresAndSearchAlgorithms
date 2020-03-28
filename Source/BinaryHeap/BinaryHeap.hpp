#include <vector>

class BinaryHeap
{
private:
    std::vector<int> vect;
    int heapSize;

    int divByTwo(int i) {return i >> 1;}        //i / 2
    int multiplyByTwo(int i) {return i << 1;}   //i *= 2
    int divByTwoPlusOne(int i) {return (i<<1)+1;}   //i/2 + 1

    void shiftUp(int i)
    {
        if (i == 1)     //Do nothing, we are already in root and cannot swap
        {
            return;
        }

        if (vect[i] > vect[divByTwo(i)])
        {
            std::swap(vect[i], vect[divByTwo(i)]);
            shiftUp(divByTwo(i));
        }
    }

    void shiftDown(int i)
    {
        if (i>heapSize)
        {
            return; //Do nothing, if indes does not exist
        }

        int swapId = i;

        if (multiplyByTwo(i) <= heapSize && vect[i] < vect[multiplyByTwo(i)])   //Compare with left child (if exists)
        {
            swapId = divByTwoPlusOne(i);
        }

        if (swapId != i)
        {
            std::swap(vect[i], vect[swapId]);

            shiftDown(swapId);
        }
    }

public:
    BinaryHeap(): heapSize(0) {}

    bool IsEmpty()
    {
        return heapSize == 0;
    }

    void Insert(int key)
    {
        if (heapSize + 1 >= (int)vect.size())
        {
            vect.push_back(0);    //Increment vetor size
        }
        vect[++heapSize] = key;   //Add key to vector
        shiftUp(heapSize);        //Shift up
    }

    int ExtractMax()
    {
        int maxVal = vect[1];

        std::swap(vect[1], vect[heapSize--]);   //Swap last and first element, decrement heap size

        shiftDown(1);       //Shift element to reorganize heap

        return maxVal;
    }

    int GetMax()
    {
        return vect[1];     //!ST ELEMENT IN VECTOR IS MAX (IT IS MAX BINARY HEAP)
    }
};