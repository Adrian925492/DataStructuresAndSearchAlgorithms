#include <string>
#include <list>

#define HASH_TABLE_SIZE (7)

/* Hash table open adress method 
    With open adress method all data are stored directly inside hash table. If collision occurs, the table uses its search
    of new key algorithm to find new hash index for the data.

    -> line search: new index = (old_index + N) % tableSize; for N starting of 0, increment of 1 untill free index will be found
    -> square search: new_index = (old_index + N^2) % tableSize; for N starting of 0, increment of 1 untill free index will be found
    -> double hashing method: new_index = (old_index + N * old_index) % tableSize; for N starting of 0, increment of 1 untill free index will be found

    In that example line search method is used.

*/

namespace openAdressMethod
{

class HashElement
{
public:
    int key;
    std::string value;

    HashElement(): key(0), value("") {}
    HashElement(int key_, std::string value_) : key(key_), value(value_) {}
};

class HashTable
{
private:
    HashElement* *array;        //Hash table
    HashElement* deletedElement;
    int currentSize;        //Hash table size

    int hashFunction(int key)
    {
        return key % HASH_TABLE_SIZE;       //Hash table key calculation
    }

public:
    HashTable(): currentSize(0) 
    {
        array = new HashElement * [HASH_TABLE_SIZE];  //Allocate space for hash array

        for (int i = 0; i < HASH_TABLE_SIZE; ++i)
        {
            array[i] = nullptr;
        }

        deletedElement = new HashElement(-1, "");
    }
    
    bool isEmpty()
    {
        return currentSize == 0;
    }

    void insert(int key, std::string value)
    {
        if (currentSize >= HASH_TABLE_SIZE)
        {
            return;     //Check size (if we can add element)
        }

        HashElement* temp = new HashElement(key, value);    //Allocate space for new hash element

        int hashIndex = hashFunction(key);      //Get hash key

        while(array[hashIndex] != nullptr &&    //Untill we will find free place in array
                array[hashIndex]->key != key &&
                array[hashIndex]->key != -1)
        {
            ++hashIndex;                        //hashIndex = (hashIndex + n) % table size <- line search algorithm
            hashIndex %= HASH_TABLE_SIZE;
        }

        if (array[hashIndex] == nullptr || array[hashIndex]->key == -1)     //If key has been found
        {
            ++currentSize;              //Increase hash table size
            array[hashIndex] = temp;    //Add data to hash table
        }
    }

    std::string search(int key)
    {
        int hashKey = hashFunction(key);        //Calculate key

        while (array[hashKey] != nullptr && array[hashKey]->key != deletedElement->key)    //Iterate threw table starting for hash key
        {
            if (array[hashKey]->key == key)
            {
                return array[hashKey]->value;
            }
            ++hashKey;          //Line search of next key algorithm
            hashKey %= HASH_TABLE_SIZE;
        }
        return "";  //Return empty string if not found
    }

    void remove(int key)
    {
        int hashKey = hashFunction(key);    //Get hash key

        while(array[hashKey] != nullptr &&
                array[hashKey]->key != deletedElement->key)
        {
            if(array[hashKey]->key == key)  //If element found
            {
                array[hashKey] = deletedElement;    //Mark it as deleted

                --currentSize;          //Decrement size

                return;     //No need to continue search
            }
            ++hashKey;          //Line search of next key algorithm
            hashKey %= HASH_TABLE_SIZE;
        }
    }
};

}