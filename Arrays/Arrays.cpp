// Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool allocate_array(unsigned n) {


    //int _array[100]{};
    //unsigned n = 100;

    cout << "Reserving memory...";
    int* _array = new int[n];
    cout << "Done!" << endl;

    cout << "Assigning data into array...";
    for (int i = 0; i < 100; i++)
        _array[i] = i;
    cout << "Done!" << endl;

    // for (int i = 0; i < 100000; i++)
    //    cout << "array[" << i << "]: "  << _array[i] << endl;

    cout << "Freeing memory...";
    delete[] _array;
    cout << "Done!" << endl;



    return true;
}

int main()
{
    for (int i = 0; i < 100; i++) {
        allocate_array(10000000);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
