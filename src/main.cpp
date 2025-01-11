/*!
    \file main.cpp
    \brief Entry point of the app
    \author Maxime CARON
    \date 01-10-2025
*/

#include "list.hpp"

#define DATA_SET_FILE "/home/carbon/Documents/Algosup/2024_2025/Phase-3/Double-Linked-List-Viewer/formattedData/actressDataSet.csv"

int main(void)
{
    List *testList = new List();
    testList->loadListFromFile(DATA_SET_FILE);

    testList->printList();

    return 0;
}