// LinearSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int gcd(int a, int b) { //find the highest remainder

	if (a < b || a == 0 || b == 0)  //check if values are appropiate ( a is bigger than b, values are not 0)
		return -1;

	int r = a % b; //calculate 1st remainder

	while (r > 0) { //loop until remainder = 0
		a = b;		//a <-- b
		b = r;		//b <-- r
		r = a % b;	//remainder
	}

	return b;
}

//
//linear search assumes that a[] is in ascending order!!!
int LinearSearch(int* a, int x, int n) { //find the index of the given value

	int i = 0;	//index for going through the array
	while (i < n && a[i] <= x) {	// index less than size of array, x can still be found
		if (a[i] == x) return i;	// we found our x --> return the index
		i++;						// x not yet found, increase the index
	}

	return -1; // not found, return -1
}

//binary search assumes that a[] is in ascending order!!!
long long unsigned BinarySearch(long long int* a, long long  int x, long long int n) {//find the index of the given value more efficiently

	long long left, right, mid; // left and right indexes of current search area
	left = 0; right = n - 1;

	while (left != right) {
		mid = (left + right) / 2; //find the midpoint

		if (a[mid] == x) return mid; //optional check (will this speed up the search or not?)
		if (a[mid] > x) { //middle item is bigger
			//choose the left part
			right = mid - 1;
		}
		else { //middle item is smaller
			left = mid + 1; //or with the optional check: left = mid + 1
		}
	}
	if (a[mid] == x) return mid;

	return -1;
}

static int* AllocateArray(int n) { // add values to p array and allocate memory

	cout << "Reserving memory...";
	int* arrayAllocate = new int[n];
	cout << "Done!" << endl;

	cout << "Assigning data into array...";
	for (int i = 0; i < n; i++)
		arrayAllocate[i] = i;
	cout << "Done!" << endl;

	//for (int i = 0; i < 100; i++)
	//	cout << "array[" << i << "]: " << arrayAllocate[i] << endl;

	//cout << "Freeing memory...";
	//delete[] arrayAllocate;
	//cout << "Done!" << endl;

	return arrayAllocate;
}

static long long int* AllocateArrayLong(long long int n) { // add values to p array and allocate memory

	cout << "Reserving memory...";
	long long int* arrayAllocate = new long long int[n];
	cout << "Done!" << endl;

	cout << "Assigning data into array...";
	for (long long int i = 0; i < n; i++)
		arrayAllocate[i] = i;
	cout << "Done!" << endl;

	return arrayAllocate;
}

//
// MAIN
//
int main()
{
	int a = 55;
	int b = 30;

	cout << "gcd(" << a << ", " << b << ") = " << gcd(a, b) << endl;

	//int n = 100000000000; //length
	//int* arr = AllocateArray(n); //array
	//int x = 43; //element to find

	//cout << "Linear search(a," << x << ", " << n << ") = " << LinearSearch(arr, x, n) << endl;

	long long int n = 100000000; //length
	long long int* arrr = AllocateArrayLong(n); //array
	long long int x = 43; //element to find

	cout << "Binary search(a, " << x << ", " << n << ") = " << BinarySearch(arrr, x, n) << endl;

	return EXIT_SUCCESS;
}
//
//
//



