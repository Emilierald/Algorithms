// Ackerman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int A(int m, int n) { // Ackerman function

    if (n < 0) // n has to be non-negative
        return -1;

    if (m == 0)
    {
        return n + 1;
    }
    if (n == 0)
    {
        return A(m - 1, 1);
    }
    else A(m - 1, A(m, n - 1));
}


int main()
{
    cout << "Ackerman: " << A(2, 3) << endl;
}
