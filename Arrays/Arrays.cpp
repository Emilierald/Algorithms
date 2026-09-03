// Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int lenght = 100;
int highestInt;
int _array[100];


bool AllocateArray(unsigned n) {

    //int _array[100]{};
    //unsigned n = 100;

    cout << "Reserving memory...";
    //int* arrayAllocate = new int[n];
    cout << "Done!" << endl;

    cout << "Assigning data into array...";
    for (int i = 0; i < lenght; i++)
        _array[i] = i;
    cout << "Done!" << endl;

     for (int i = 0; i < lenght; i++)
        cout << "array[" << i << "]: "  << _array[i] << endl;

    //cout << "Freeing memory...";
    //delete[] _array;
    //cout << "Done!" << endl;

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

int Randomize() { //randomizes array

    cout << "MIXING";
    srand(time(0));
    cout << "RAND_MAX" << RAND_MAX << endl;

    unsigned n = 10;

    //int* arr = new int[n];

    for (unsigned i = 0; i < n; i++) {
        _array[i] = rand();
        cout << _array[i] << endl;
    }

    return n;
}

int main()
{

    AllocateArray(lenght);
    Randomize();

    int max = FindMax(_array, lenght);

    cout << "Max: " << FindMax(_array, lenght) << endl;
}
