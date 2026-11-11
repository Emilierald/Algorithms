// Heap.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "heap.h"


void Heap::Insert(int key)
{
    //if head is empty
    if (Length() < 1) {
        heapArray[1] = key; // put the key into index 1
        heapArray[0]++;
        return;
    }

    // otherwise ...

    // 1. insert the key into first available slot
    int index = Length() + 1;
    heapArray[index] = key;

    // 2. increment length of the heap
    heapArray[0]++;

    // 3. while heaporder not guaranteed AND we are not at root yet: 
    //      - track the newly inserted element
    //      - swap places with parent
    int parent_index = index / 2;
    while (heapArray[parent_index] > heapArray[index] && index > 1) {
        int temp = heapArray[parent_index];
        heapArray[parent_index] = heapArray[index];
        heapArray[index] = temp;
        // done
        // update indices
        index = parent_index;
        parent_index = index / 2;
    }
}

void Heap::Print()
{
    for (int i = 1; i <= Length(); i++) {
        std::cout << heapArray[i];
        if (i < Length()) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
    return;
}

void Heap::DeleteMin()
{
    // Get the last element
    int lastElement = heapArray[Length()];

    // Replace root with last element
    heapArray[1] = lastElement;

    // Decrease size of heap
    heapArray[0]--;

    while (true) 
    {
        int root = 1;
        int child1 = 2 * 1;
        int child2 = 2 * 1 + 1;

        // If left child is larger than root
        if (child1 <= Length() && heapArray[child1] < heapArray[root])
            root = child1;

        // If right child is larger than largest so far
        if (child2 <= Length() && heapArray[child2] < heapArray[root])
            root = child2;

        // If largest is not root
        if (root != 1) {
            std::swap(heapArray[1], heapArray[root]);
        }
        else { break; } //if root is 1
    }
}