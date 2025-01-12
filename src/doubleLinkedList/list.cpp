/*!
    \file list.cpp
    \brief A double linked list implementation to store actress data.
    \author Maxime CARON
    \date 01-11-2025
*/

#include "list.hpp"
#include <iostream>
#include <fstream>

using namespace std;

List::List()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

int List::getSize()
{
    return size;
}

bool List::isEmpty()
{
    return size == 0;
}

void List::pushBack(string name, int rank, int videoNb, unsigned long views)
{
    ListNode *node = new ListNode(name, rank, videoNb, views);
    if (isEmpty())
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->setNext(node);
        node->setPrev(tail);
        tail = node;
    }
    size++;
}

void List::pushFront(string name, int rank, int videoNb, unsigned long views)
{
    ListNode *node = new ListNode(name, rank, videoNb, views);
    if (isEmpty())
    {
        head = node;
        tail = node;
    }
    else
    {
        node->setNext(head);
        head->setPrev(node);
        head = node;
    }
    size++;
}

void List::insert(int index, string name, int rank, int videoNb, unsigned long views)
{
    if (index < 0 || index > size)
    {
        cout << "Index out of bounds" << endl;
        return;
    }
    if (index == 0)
    {
        pushFront(name, rank, videoNb, views);
        return;
    }
    if (index == size)
    {
        pushBack(name, rank, videoNb, views);
        return;
    }
    ListNode *node = new ListNode(name, rank, videoNb, views);
    ListNode *current = getNode(index);
    node->setNext(current);
    node->setPrev(current->getPrev());
    current->getPrev()->setNext(node);
    current->setPrev(node);
    size++;
}

void List::popBack()
{
    if (isEmpty())
    {
        cout << "List is empty" << endl;
        return;
    }
    if (size == 1)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        ListNode *node = tail;
        tail = tail->getPrev();
        tail->setNext(nullptr);
        delete node;
    }
    size--;
}

void List::popFront()
{
    if (isEmpty())
    {
        cout << "List is empty" << endl;
        return;
    }
    if (size == 1)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        ListNode *node = head;
        head = head->getNext();
        head->setPrev(nullptr);
        delete node;
    }
    size--;
}

void List::remove(int index)
{
    if (index < 0 || index >= size)
    {
        return;
    }
    if (index == 0)
    {
        popFront();
        return;
    }
    if (index == size - 1)
    {
        popBack();
        return;
    }
    ListNode *node = getNode(index);
    node->getPrev()->setNext(node->getNext());
    node->getNext()->setPrev(node->getPrev());
    delete node;
    size--;
}

void List::removeByName(string name){
    ListNode *current = head;
    while (current != nullptr)
    {
        if (current->getName().compare(name) == 0)
        {
            if (current == head)
            {
                popFront();
            }
            else if (current == tail)
            {
                popBack();
            }
            else
            {
                current->getPrev()->setNext(current->getNext());
                current->getNext()->setPrev(current->getPrev());
                delete current;
                size--;
            }
            return;
        }
        current = current->getNext();
    }
}

void List::removeByRank(int rank){
    ListNode *current = head;
    while (current != nullptr)
    {
        if (current->getRank() == rank)
        {
            if (current == head)
            {
                popFront();
            }
            else if (current == tail)
            {
                popBack();
            }
            else
            {
                current->getPrev()->setNext(current->getNext());
                current->getNext()->setPrev(current->getPrev());
                delete current;
                size--;
            }
            return;
        }
        current = current->getNext();
    }
}

ListNode *List::getNode(int index)
{
    if (index < 0 || index >= size)
    {
        // cout << "Index out of bounds" << endl;
        return nullptr;
    }
    ListNode *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->getNext();
    }
    return current;
}

void List::printList()
{
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << "Name: " << current->getName() << "\tRank: " << current->getRank() << "\tVideoNb: " << current->getVideoNb() << "\tViews: " << current->getViews() << endl;
        current = current->getNext();
    }
}

bool List::isSortedByRank()
{
    ListNode *current = head;
    while (current->getNext() != nullptr)
    {
        if (current->getRank() > current->getNext()->getRank())
        {
            return false;
        }
        current = current->getNext();
    }
    return true;
}

ListNode *List::splitList(ListNode *node)
{
    ListNode *slow = node;
    ListNode *fast = node;

    while (fast && fast->getNext() && fast->getNext()->getNext())
    {
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
    }

    ListNode *secondHalf = slow->getNext();
    slow->setNext(nullptr);
    if (secondHalf) secondHalf->setPrev(nullptr);

    return secondHalf;
}

ListNode *List::mergeSortedLists(ListNode *first, ListNode *second)
{
    if (!first)
        return second;
    if (!second)
        return first;

    if (first->getRank() <= second->getRank())
    {
        first->setNext(mergeSortedLists(first->getNext(), second));
        first->getNext()->setPrev(first);
        first->setPrev(nullptr);
        return first;
    }
    else
    {
        second->setNext(mergeSortedLists(first, second->getNext()));
        second->getNext()->setPrev(second);
        second->setPrev(nullptr);
        return second;
    }
}

ListNode *List::mergeSort(ListNode *node)
{
    if (!node || !node->getNext())
        return node;

    ListNode *secondHalf = splitList(node);
    node = mergeSort(node);
    secondHalf = mergeSort(secondHalf);

    return mergeSortedLists(node, secondHalf);
}

void List::sortByRank()
{
    head = mergeSort(head);

    ListNode *temp = head;
    while (temp && temp->getNext())
    {
        temp = temp->getNext();
    }
    tail = temp;
}

bool List::isSortedByName()
{
    ListNode *current = head;
    while (current->getNext() != nullptr)
    {
        if (current->getName().compare(current->getNext()->getName()) > 0)
        {
            return false;
        }
        current = current->getNext();
    }
    return true;
}

ListNode* List::partition(ListNode* low, ListNode* high) {
    int pivot = high->getVideoNb();
    ListNode* i = low->getPrev();

    for (ListNode* j = low; j != high; j = j->getNext()) {
        if (j->getVideoNb() < pivot) {
            i = (i == nullptr) ? low : i->getNext();
            i->swapData(j);
        }
    }

    i = (i == nullptr) ? low : i->getNext();
    i->swapData(high);
    return i;
}


void List::quickSort(ListNode *low, ListNode *high)
{
    if(high != nullptr && low != high && low != high->getNext())
    {
        ListNode *pivot = partition(low, high);
        quickSort(low, pivot->getPrev());
        quickSort(pivot->getNext(), high);
    }
}

void List::sortByVideoNb()
{
    quickSort(head, tail);
}

bool List::isSortedByVideoNb(){
    ListNode *current = head;
    while (current->getNext() != nullptr)
    {
        if (current->getVideoNb() > current->getNext()->getVideoNb())
        {
            return false;
        }
        current = current->getNext();
    }
    return true;
}

bool List::isSortedByViews()
{
    ListNode *current = head;
    while (current->getNext() != nullptr)
    {
        if (current->getViews() > current->getNext()->getViews())
        {
            return false;
        }
        current = current->getNext();
    }
    return true;
}

void List::heapify(int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    ListNode *largestNode = getNode(largest);
    ListNode *lNode = getNode(l);
    ListNode *rNode = getNode(r);


    if (l < n && lNode->getViews() > largestNode->getViews()){
        largest = l;
        largestNode = lNode;
    }

    if (r < n && rNode->getViews() > largestNode->getViews()){
        largest = r;
        largestNode = rNode;
    }

    if (largest != i){
        largestNode->swapData(getNode(i));
        heapify(n, largest);
    }
}

void List::buildMaxHeap(){
    for (int i = size / 2 - 1; i >= 0; i--){
        heapify(size, i);
    }
}

void List::sortByViews()
{
    buildMaxHeap();

    for (int i = size - 1; i > 0; i--){
        getNode(0)->swapData(getNode(i));
        heapify(i, 0);
    }
}

ListNode *List::searchByName(string name)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        if (current->getName().compare(name) == 0)
        {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

ListNode *List::searchByRank(int rank)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        if (current->getRank() == rank)
        {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

ListNode *List::searchByVideoNb(int videoNb)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        if (current->getVideoNb() == videoNb)
        {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

ListNode *List::searchByViews(unsigned long views)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        if (current->getViews() == views)
        {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

void List::saveListToFile(const string &filename)
{
    FILE *file = fopen(filename.c_str(), "wb");
    if (!file)
    {
        cout << "Error: Could not open file." << endl;
        return;
    }
    ListNode *current = head;
    while (current != nullptr)
    {
        string toWrite = current->getName() + "," + to_string(current->getRank()) + "," + to_string(current->getVideoNb()) + "," + to_string(current->getViews()) + "\n";
        fwrite(toWrite.c_str(), sizeof(char), toWrite.size(), file);
        current = current->getNext();
    }
    fclose(file);
}

void List::loadListFromFile(const string filename)
{
    string separator = ",";
    ifstream input(filename);
    if (!input)
    {
        cout << "Error: file \'" << filename << "\' doesn't exist or is not accessible" << endl;
        return;
    }

    for (string line; getline(input, line);)
    {
        size_t pos = 0;
        size_t tokenNb = 0;
        string token;
        string nodeName;
        int nodeRank;
        int nodevideoNb;
        unsigned long nodeviews;

        while ((pos = line.find(separator)) != std::string::npos || tokenNb < 4)
        {
            token = line.substr(0, pos);
            switch (tokenNb)
            {
            case 0:
                nodeName = token;
                break;
            case 1:
                nodeRank = stoi(token);
                break;
            case 2:
                nodevideoNb = stoi(token);
                break;
            case 3:
                nodeviews = stoul(token);
                break;
            default:
                break;
            }
            line.erase(0, pos + 1);
            ++tokenNb;
        }
        pushFront(nodeName, nodeRank, nodevideoNb, nodeviews);
    }
}
