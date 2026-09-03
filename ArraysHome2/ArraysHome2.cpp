// ArraysHome2.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
using namespace std;

int main()
{
    int firstSize = 10;
    int secondSize = 20;

    int* arrayFirst = new int[firstSize] {};

    cout << "Taulukko: " << endl;
    for (int i = 0; i < firstSize; i++) { //tulosta taulukko
        cout << "array[" << i << "]: " << arrayFirst[i] << endl;
    }
    cout << " " << endl;

    cout << "Taulukko uusilla arvoilla:  " << endl;
    for (int i = 0; i < firstSize; i++) { //muuta taulukon arvoja, tulosta
        arrayFirst[i] = i;
        cout << "array[" << i << "]: " << arrayFirst[i] << endl;
    }
    cout << " " << endl;

    int* arrayNew = new int[secondSize] {}; //uusi isompi array

    copy(arrayFirst, arrayFirst + 10, arrayNew); //kopioi vahna array uuteen

    delete[] arrayFirst; //poista vanha array
    arrayFirst = arrayNew; //laita uusi array vanhan paikalle

    cout << "Vanhat arvot uudessa listassa:  " << endl;
    for (int i = 0; i < secondSize; i++) { //tulosta vanhasta arraysta siiretyt arvot
        cout << "array[" << i << "]: " << arrayFirst[i] << endl;
    }
    cout << " " << endl;

    cout << "Uudet arvot uudessa listassa:  " << endl;
    for (int i = firstSize; i < secondSize; i++) { //aseta uudet arvot, tulosta
        arrayFirst[i] = i;
        cout << "array[" << i << "]: " << arrayFirst[i] << endl;
    }
    cout << " " << endl;

    cout << "Kaikki arvot uudessa listassa:  " << endl;
    for (int i = 0; i < secondSize; i++) { //tulosta kaikki arvot
        cout << "array[" << i << "]: " << arrayFirst[i] << endl;
    }
}

