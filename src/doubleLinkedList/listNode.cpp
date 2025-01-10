/*!
    \file listNode.cpp
    \brief A double linked list node implementation to store actress data.
    \author Maxime CARON
    \date 01-10-2025
*/

#include "listNode.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

ListNode::ListNode(string name, int rank, int videoNb, unsigned long views){
    this->name = name;
    this->rank = rank;
    this->videoNb = videoNb;
    this->views = views;
    this->next = nullptr;
    this->prev = nullptr;
}

string ListNode::getName(){
    return name;
}

int ListNode::getRank(){
    return rank;
}

int ListNode::getVideoNb(){
    return videoNb;
}

unsigned long ListNode::getViews(){
    return views;
}

ListNode *ListNode::getNext(){
    return next;
}

ListNode *ListNode::getPrev(){
    return prev;
}

void ListNode::setNext(ListNode *next){
    this->next = next;
}

void ListNode::setPrev(ListNode *prev){
    this->prev = prev;
}