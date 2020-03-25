#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "SublistSearch.hpp"

#include "../List/List.hpp"

using namespace sublistSearch;

TEST(SearchTest, sublistSearchTest)
{
    list::List<int> oInputList;
    oInputList.insert(5, 0);
    oInputList.insert(6, 1);
    oInputList.insert(1, 2);
    oInputList.insert(2, 3);
    oInputList.insert(3, 4);
    oInputList.insert(8, 5);

    list::List<int> oLookedForList;
    oLookedForList.insert(1, 0);
    oLookedForList.insert(2, 1);
    oLookedForList.insert(3, 2);

    EXPECT_TRUE(Search(oInputList.head, oLookedForList.head));
}