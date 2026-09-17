// Sequences.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int array[9] = {2, 3, 1, 5, 9, 13, 7, 8, 11};


int main()
{
    cout << "Hello World!\n";
    //SortArray(array[], 9);
}

int SortArray(int array[], int size) {
    int location = 0;

    for (int i = 0; i = size * 10; i++) {
        if (array[location] > array[location + 1]) {
            SwapInts(array[location], array[location + 1]);
            location++;
        }
    }
}

int FindSequence(int array[], int size) {
    int location;

    int startLocation;

    int tempArray[10] = {};

    startLocation = location;
    for (int i = 0; i = size; i++) {
        if (array[location] < array[location + 1]) {
            tempArray[i] = array[location];
        }
        else break;
        
        location++;
    }
}

int SwapInts(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;

    return a, b;
}

