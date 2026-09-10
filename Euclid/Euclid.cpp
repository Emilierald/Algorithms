// Euclid.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std;

int gcd(int a, int b) { //find the highest remainder

	if (a < b || a == 0 || b == 0)  //check if values are appropiate ( a is bigger than b, values are not 0)
		return 0;

	int r = a % b; //calculate 1st remainder

	while (r > 0) { //loop until remainder = 0
		a = b;		//a <-- b
		b = r;		//b <-- r
		r = a % b;	//remainder
	}

	return b;
}

int main()
{
	int a = 55;
	int b = 30;

	cout << "gcd(" << a << ", " << b << ") = " << gcd(a, b);

	return EXIT_SUCCESS;
}

