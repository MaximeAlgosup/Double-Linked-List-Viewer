/*!
    \file list.hpp
    \brief A double linked list implementation to store actress data.
    \author Maxime CARON
    \date 01-10-2025
*/

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include "listNode.hpp"

using namespace std;

class List
{
private:
    ListNode *head;
    ListNode *tail;
    int size;

    /*!
        \brief Split the list into two halves.
        \param node The node to split.
        \return The node at the middle of the list.
    */
    ListNode *splitList(ListNode *node);

    /*!
        \brief Merge two sorted lists.
        \param first The first list to merge.
        \param second The second list to merge.
        \return The merged list.
    */
    ListNode *mergeSortedLists(ListNode *first, ListNode *second);
    
    /*!
        \brief Sort the list by rank using merge sort.
        \param node The node to sort.
        
    */
    ListNode *mergeSort(ListNode *node);

    /*!
        \brief Swap two nodes.
        \param a The first node to swap.
        \param b The second node to swap.
    */
    ListNode *partition(ListNode *low, ListNode *high);

    /*!
        \brief Sort the list by number of videos using quick sort.
        \param low The lowest index of the list.
        \param high The highest index of the list.
    */
    void quickSort(ListNode *low, ListNode *high);

    /*!
        \brief Heapify the list.
        \param n The size of the list.
        \param i The index to heapify.
    */
    void heapify(int n, int i);


    /*!
        \brief Build a max heap.
    */
    void buildMaxHeap();

public:
    /*!
        \brief Constructor for the List class.
    */
    List();

    /*!
        \brief Destructor for the List class.
    */
    ~List();

    /*!
        \brief Get the size of the list.
        \return The size of the list.
    */
    int getSize();

    /*!
        \brief Check if the list is empty.
        \return True if the list is empty, false otherwise.
    */
    bool isEmpty();

    /*!
        \brief Push a node to the back of the list.
        \param name The name of the actress.
        \param rank The rank of the actress.
        \param videoNb The number of videos the actress has appeared in.
        \param views The number of views the actress has.
    */
    void pushBack(string name, int rank, int videoNb, unsigned long views);

    /*!
        \brief Push a node to the front of the list.
        \param name The name of the actress.
        \param rank The rank of the actress.
        \param videoNb The number of videos the actress has appeared in.
        \param views The number of views the actress has.
    */
    void pushFront(string name, int rank, int videoNb, unsigned long views);

    /*!
        \brief Insert a node at a specific index.
        \param index The index to insert the node at.
        \param name The name of the actress.
        \param rank The rank of the actress.
        \param videoNb The number of videos the actress has appeared in.
        \param views The number of views the actress has.
    */
    void insert(int index, string name, int rank, int videoNb, unsigned long views);

    /*!
        \brief Remove the node at the back of the list.
    */
    void popBack();

    /*!
        \brief Remove the node at the front of the list.
    */
    void popFront();

    /*!
        \brief Remove the node at a specific index.
        \param index The index of the node to remove.
    */
    void remove(int index);

    /*!
        \brief Remove the node with the specified name.
        \param name The name of the node to remove.
    */
    void removeByName(string name);

    /*!
        \brief Remove the node with the specified rank.
        \param rank The rank of the node to remove.
    */
    void removeByRank(int rank);

    /*!
        \brief Get the node at a specific index.
        \param index The index of the node to get.
        \return The node at the specified index.
    */
    ListNode *getNode(int index);

    /*!
        \brief Print the list.
    */
    void printList();

    /*!
        \brief Check if the list is sorted by rank.
        \return True if the list is sorted by rank, false otherwise.
    */
    bool isSortedByRank();

    /*!
        \brief Sort the list by rank using merge sort.
    */
    void sortByRank();

    /*!
        \brief Check if the list is sorted by name.
        \return True if the list is sorted by name, false otherwise.
    */
    bool isSortedByName();

    /*!
        \brief Sort the list by number of videos using quick sort.
    */
    void sortByVideoNb();

    /*!
        \brief Check if the list is sorted by number of videos.
        \return True if the list is sorted by number of videos, false otherwise.
    */
    bool isSortedByVideoNb();

    /*!
        \brief Sort the list by number of views heap sort.
    */
    void sortByViews();

    /*!
        \brief Check if the list is sorted by number of views.
        \return True if the list is sorted by number of views, false otherwise.
    */
    bool isSortedByViews();

    /*!
        \brief Search for an actress by name.
        \param name The name of the actress to search for.
        \return The node with the specified name.
    */
    ListNode *searchByName(string name);

    /*!
        \brief Search for an actress by rank.
        \param rank The rank of the actress to search for.
        \return The node with the specified rank.
    */
    ListNode *searchByRank(int rank);

    /*!
        \brief Search for an actress by number of videos.
        \param videoNb The number of videos the actress has appeared in.
        \return The node with the specified number of videos.
    */
    ListNode *searchByVideoNb(int videoNb);

    /*!
        \brief Search for an actress by number of views.
        \param views The number of views the actress has.
        \return The node with the specified number of views.
    */
    ListNode *searchByViews(unsigned long views);

    /*!
        \brief Save the list to a file.
        \param filename The name of the file to save the list to.
    */
    void saveListToFile(const string &filename);

    /*!
        \brief Load the list from a file.
        \param filename The name of the file to load the list from.
    */
    void loadListFromFile(const string filename);
};
