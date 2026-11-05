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

    return;
}

int Heap::Del_min()
{
    return 0;
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
