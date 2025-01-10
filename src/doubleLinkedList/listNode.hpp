/*!
    \file listNode.hpp
    \brief A double linked list node implementation to store actress data.
    \author Maxime CARON
    \date 01-10-2025
*/

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class ListNode
{
private:
    string name;
    int rank;
    int videoNb;
    unsigned long views;
    ListNode *next;
    ListNode *prev;

public:
    /*!
        \brief Constructor for the ListNode class.
        \param name The name of the actress.
        \param rank The rank of the actress.
        \param videoNb The number of videos the actress has appeared in.
        \param views The number of views the actress has.
    */
    ListNode(string name, int rank, int videoNb, unsigned long views);

    /*!
        \brief Get the name of the actress.
        \return The name of the actress.
    */
    string getName();

    /*!
        \brief Get the rank of the actress.
        \return The rank of the actress.
    */
    int getRank();

    /*!
        \brief Get the number of videos the actress has appeared in.
        \return The number of videos the actress has appeared in.
    */
    int getVideoNb();

    /*!
        \brief Get the number of views the actress has.
        \return The number of views the actress has.
    */
    unsigned long getViews();

    /*!
        \brief Get the next node in the list.
        \return The next node in the list.
    */
    ListNode *getNext();

    /*!
        \brief Get the previous node in the list.
        \return The previous node in the list.
    */
    ListNode *getPrev();

    /*!
        \brief Set the next node in the list.
        \param next The next node in the list.
    */
    void setNext(ListNode *next);

    /*!
        \brief Set the previous node in the list.
        \param prev The previous node in the list.
    */
    void setPrev(ListNode *prev);

};

