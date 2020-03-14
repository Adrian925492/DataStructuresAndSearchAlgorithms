#include <iostream>

#include "SimpleList.hpp"

using namespace std;


void listExample(void)
{
    /* Simple list example */
    cout << "Simple list example: /n/n";

    SimpleList_t<unsigned char> simpleList;
    simpleList.insert('A', 0);

}