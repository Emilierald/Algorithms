// Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
using namespace std;

int length = 100;
int highestInt;

int arrayMixed[100];
int* arrayAllocate = new int[100];


bool AllocateArray(unsigned n) { // add values to p array and allocate memory

    //int _array[100]{};
    //unsigned n = 100;

    cout << "Reserving memory...";
    int* arrayAllocate = new int[n];
    cout << "Done!" << endl;

    cout << "Assigning data into array...";
    for (int i = 0; i < length; i++)
        arrayAllocate[i] = i;
    cout << "Done!" << endl;

     for (int i = 0; i < length; i++)
        cout << "array[" << i << "]: "  << arrayAllocate[i] << endl;

    cout << "Freeing memory...";
    delete[] arrayAllocate;
    cout << "Done!" << endl;

    return true;
}

bool AssignArray(int arrayAdd[], unsigned n) { // add values to p array

    cout << "Assigning data into array...";
    for (int i = 0; i < length; i++)
        arrayAdd[i] = i;
    cout << "Done!" << endl;

    for (int i = 0; i < length; i++)
        cout << "array[" << i << "]: " << arrayAdd[i] << endl;

    cout << "Freeing memory...";
    delete[] arrayAdd;
    cout << "Done!" << endl;

    return true;
}

int FindMax(int arrayMax[], int size) { //finds the highest array value

    highestInt = arrayMax[0];

    for (int i = 0; i < size; i++) {
        if (arrayMax[i] > highestInt) {
            highestInt = arrayMax[i];
        }
    }
    //cout << "Highest: " << highestInt << endl;
    return highestInt;
}

int Randomize(int arrayMix[], int size) { //add random values and randomizes array

    cout << "MIXING!" << endl;
    srand(time(0));
    //cout << "RAND_MAX" << RAND_MAX << endl;
    //unsigned n = 10;
    //int* arr = new int[n];

    for (int i = 0; i < size; i++) {
        arrayMix[i] = rand();
        cout << arrayMix[i] << endl;
    }

    return size;
}

int main()
{
    //AllocateArray(length);
    //AssignArray(arrayAllocate, length);
    //Randomize(arrayMixed, length);

    //int max = FindMax(arrayMixed, length);

    //cout << "Max in arrayMixed: " << FindMax(arrayMixed, length) << endl;


}
