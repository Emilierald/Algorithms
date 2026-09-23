// Fibonacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


int FibonacciRecursive(int n) { 

    if (n == 1 || n == 0) //f(1) = 1, f(0) = 1
        return 1;

    if (n < 0) // n has to be bigger than 1
        return -1;

    else
        return FibonacciRecursive(n - 1) + FibonacciRecursive(n - 2);
}

int Fibonacci(int n) { 

    if (n == 1 || n == 0) //f(1) = 1, f(0) = 1
        return 1;

    if (n < 0) // n has to be bigger than 1
        return -1;

    int nMinus2, nMinus1 = 0, currentN = 1;
    
    for (int i = 1; i < n + 1; i++)
    {
        nMinus2 = nMinus1;
        nMinus1 = currentN;
        currentN = nMinus2 + nMinus1;
    }
    return currentN;
}


int main()
{
    cout << "Fibonacci (recursive): " << FibonacciRecursive(4) << endl;
    cout << "Fibonacci: " << Fibonacci(4) << endl;
}