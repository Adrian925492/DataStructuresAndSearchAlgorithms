#include <string>
#include <list>

#define HASH_TABLE_SIZE (7)

namespace chainMethod
{

class HashTable
{
private:
    std::list<std::pair<int, std::string>> table_list[HASH_TABLE_SIZE];     //Hash table
    
    int hashFunction(int key)
    {
        return key % HASH_TABLE_SIZE;       //Hash table key calculation
    }

public:
    HashTable() {}
    
    bool isEmpty()
    {
        int totalElement = 0;

        for (int i = 0; i < HASH_TABLE_SIZE; ++i)       //Check if it is empty by checking all lists in all keys untill get any data
        {
            totalElement += (int)table_list[i].size();

            if (totalElement != 0)
            {
                return false;
            }
        }

        return true;
    }

    void insert(int key, std::string value)
    {
        bool isKeyFound = false;

        int haskKey = hashFunction(key);    //Get key

        for (auto &keyValue : table_list[haskKey])  //Iterate threw list under the key
        {
            if (keyValue.first == key)
            {
                isKeyFound = true;
                keyValue.second = value;        //Key (original big key) has been alread found in list. Update the value.
            }
        }

        if (!isKeyFound)    //Key was not found in list
        {
            table_list[haskKey].emplace_back(key, value);   //Add pair key value to the list
        }
    }

    std::string search(int key)
    {
        int haskKey = hashFunction(key);        //Calculate key

        for (auto& keyValue : table_list[haskKey])  //Iterate threw list of pairs to find the key
        {
            if (keyValue.first == key)
            {
                return keyValue.second;
            }
        }
        return "";  //Return empty string if not found
    }

    void remove(int key)
    {
        int hashKey = hashFunction(key);    //Get hash key

        auto &cell = table_list[hashKey];   //Get cell of data

        for (auto it = cell.begin(); it !=  cell.end(); ++it)  //Iterate threw list of pairs
        {
            if (it->first == key)
            {
                cell.erase(it);
                return;
            }
        }
    }
};

}