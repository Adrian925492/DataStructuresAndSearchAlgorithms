#include "../List/List.hpp"

namespace sublistSearch{

/* Sublist search

The sublist search is different than other algorithms. It looks for sublist in other list, not for concrete
element in container. The algorithm iterates threw input list nodes comparing if the node value is equal to 1st node value of 
sublist looked for. If no, it goes to next node of list. If yes, it goes to next node of list and sublist and compares
next node of sublist with node of the list. The comparison ends when sublist has no more nodes to compare and all
nodes comparison were succesed (sublist searched - the algorithm teruens true), or if we go to end of input list and
no sublist were searched (algorithm returns false than) */

bool CompareAllMatchedElements(list::Node<int>* inputList, list::Node<int>* searchedSublist)
{
    if (searchedSublist != nullptr && inputList == nullptr)
    {
        return false;       //Check if input list has not ended
    }

    if (searchedSublist == nullptr)
    {
        return true;        // searched list ended
    }

    if (inputList->value == searchedSublist->value)
    {
        return CompareAllMatchedElements(inputList->next, searchedSublist->next);   //Check next node
    }
    else
    {
        return false;       //Return false if not - fitted element found
    }
    
}

bool Search(list::Node<int>* inputList, list::Node<int>* searchedSublist)
{
    if (inputList == nullptr && searchedSublist == nullptr)
    {
        return true;    //Return true if both list are null - means were already compared
    }

    if (inputList == nullptr && searchedSublist != nullptr)
    {
        return false;   //Return false if inputlist has been searched and searched list has not been found
    }
 
    if (inputList->value == searchedSublist->value)
    {
        if (CompareAllMatchedElements(inputList, searchedSublist))
        {
            return true;        //Compare sublist if 1st element fits. Return true if coparison returned true.
        }
    }

    return Search(inputList->next, searchedSublist);
}

}