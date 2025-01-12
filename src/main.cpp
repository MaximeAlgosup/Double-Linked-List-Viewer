/*!
    \file main.cpp
    \brief Entry point of the app
    \author Maxime CARON
    \date 01-10-2025
*/

#include "list.hpp"

#include <assert.h>

#define DATA_SET_FILE "../formattedData/actressDataSet.csv"

int main(void)
{
    List list;
    list.loadListFromFile(DATA_SET_FILE);

    char option;
    while (true)
    {
        cout << "Welcome to the Double Linked List Viewer!" << endl;
        cout << "Select an option:" << endl;
        cout << "1. Print data set" << endl;
        cout << "2. Sort by rank" << endl;
        cout << "3. Sort by number of videos" << endl;
        cout << "4. Sort by number of views" << endl;
        cout << "5. Search by rank" << endl;
        cout << "6. Search by number of videos" << endl;
        cout << "7. Search by number of views" << endl;
        cout << "8. Remove by name" << endl;
        cout << "9. Remove by rank" << endl;
        cout << "q. Exit" << endl;
        cout << "Enter an option: ";
        cin >> option;
        cin.ignore();

        switch (option)
        {
        case '1':
            list.printList();
            break;
        case '2':
            list.sortByRank();
            break;
        case '3':
            list.sortByVideoNb();
            break;
        case '4':
            list.sortByViews();
            break;
        case '5':
        {
            int rank;
            cout << "Enter the rank to search: ";
            cin >> rank;
            cin.ignore();
            ListNode *node = list.searchByRank(rank);
            if (node)
            {
                cout << "Actress found: " << node->getName() << endl;
            }
            else
            {
                cout << "Actress not found" << endl;
            }
            break;
        }
        case '6':
        {
            int videoNb;
            cout << "Enter the number of videos to search: ";
            cin >> videoNb;
            cin.ignore();
            ListNode *node = list.searchByVideoNb(videoNb);
            if (node)
            {
                cout << "Actress found: " << node->getName() << endl;
            }
            else
            {
                cout << "Actress not found" << endl;
            }
            break;
        }
        case '7':
        {
            unsigned long views;
            cout << "Enter the number of views to search: ";
            cin >> views;
            cin.ignore();
            ListNode *node = list.searchByViews(views);
            if (node)
            {
                cout << "Actress found: " << node->getName() << endl;
            }
            else
            {
                cout << "Actress not found" << endl;
            }
            break;
        }
        case '8':
        {
            string name;
            cout << "Enter the name to remove: ";
            getline(cin, name);
            list.removeByName(name);
            break;
        }
        case '9':
        {
            int rank;
            cout << "Enter the rank to remove: ";
            cin >> rank;
            cin.ignore();
            list.removeByRank(rank);
            break;
        }
        case 'q':
            return 0;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    }

    return 0;
}