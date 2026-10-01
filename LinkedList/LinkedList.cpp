// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"

using namespace std;



bool LinkedList::IsEmpty()
{
    return this->pHead == nullptr; // if pHead is empty, return true (1)
}

void LinkedList::Insert(int value)
{
    if (IsEmpty()) { // make sure that list is empty

        Node* pNewNode = new Node(value); // create new node

        this->pHead = pNewNode; // update pHead to new node

    }
    else { // list not empty
        Node* pNewNode = new Node(value); // create new node

        pNewNode->pNext = pHead; //set new node's pNext to equal pHead

        pHead = pNewNode; // set pHead to point to equal pHead

    }
}

void LinkedList::Print()
{
    Node* pTemp = this->pHead; // create temp p, assing head p

    while (pTemp != nullptr) { // do until no more nodes left

        cout << pTemp->data << endl; // print node data

        pTemp = pTemp->pNext; // set p to next node
    }
}

bool LinkedList::Find(int value)
{
    Node* pTemp = this->pHead; // create temp p, assing head p

    while (value != pTemp->data) { // do until value matches target

        pTemp = pTemp->pNext; // set p to next node

    }

    return false;
}

bool LinkedList::Delete(int value)
{
    return false;
}

