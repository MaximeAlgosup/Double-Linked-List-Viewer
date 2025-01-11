/*!
    \file main.cpp
    \brief Entry point of the app
    \author Maxime CARON
    \date 01-10-2025
*/

#include "list.hpp"

#include <assert.h>

#define DATA_SET_FILE "/home/carbon/Documents/Algosup/2024_2025/Phase-3/Double-Linked-List-Viewer/formattedData/actressDataSet.csv"

int main(void)
{
    cout << "Welcome to the Double Linked List Viewer!" << endl;
    List *testList = new List();
    cout << "Loading list..." << endl;
    testList->loadListFromFile(DATA_SET_FILE);
    cout << "List sorting by rank using merge sort..." << endl;
    testList->sortByRank();
    assert(testList->isSortedByRank());
    cout << "List sorted by rank." << endl;

    cout << "List sorting by number of videos using quick sort..." << endl;
    testList->sortByVideoNb();
    assert(testList->isSortedByVideoNb());
    cout << "List sorted by number of videos." << endl;

    cout << "List sorting by number of views using heap sort..." << endl;
    testList->sortByViews();
    assert(testList->isSortedByViews());
    cout << "List sorted by number of views." << endl;

    return 0;
}