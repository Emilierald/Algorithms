// ArraysHome.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
using namespace std;

int main()
{
    int arrayStatic[10] = { 0 };

    for (int i = 0; i < 10; i++) { //tulosta taulukko
        cout << "array[" << i << "]: " << arrayStatic[i] << endl;
    }

    for (int i = 0; i < 10; i++) { //laita taulukkoon arvot
        arrayStatic[i] = i;
        cout << "array[" << i << "]: " << arrayStatic[i] << endl;
    }

    for (int i = 0; i < 20; i++) { //lue taulukon ohi (antaa normiarvojen jälkeen 5 x -858993460, 1 x 10 ja sitten 4 x -858993460)
                                    //jos tekee arraystä static int, ohi luetut arvot ovat nollia
        cout << "array[" << i << "]: " << arrayStatic[i] << endl;
    }

    for (int i = 0; i < 20; i++) {  //kirjoita taulukon ohi 
                                    //(tulee error: Run-Time Check Failure #2 - Stack around the variable 'arrayStatic' was corrupted.)
                                    // exited with code -1 (0xffffffff). (Eli ei onnistu)
        arrayStatic[i] = i;         // jos tekee arraysta static int, arrayhin jatketaan kirjoittamista loogisesti, ei tule erroria
        cout << "array[" << i << "]: " << arrayStatic[i] << endl;
    }
}

