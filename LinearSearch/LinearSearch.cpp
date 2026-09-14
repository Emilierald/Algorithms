// LinearSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

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
unsigned BinarySearch( int* a, int x, int n) {//find the index of the given value more efficiently

	int left, right, mid; // left and right indexes of current search area
	left = 0; right = n - 1;

	while (left != right) {
		mid = (left + right) / 2; //find the midpoint

		if (a[mid] == x) return mid; //optional check 
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

//binary search assumes that a[] is in ascending order!!!
long long unsigned BinarySearchLongLong(long long int* a, long long  int x, long long int n) {//find the index of the given value more efficiently

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

	//cout << "Reserving memory...";
	int* arrayAllocate = new int[n];
	//cout << "Done!" << endl;

	//cout << "Assigning data into array...";
	for (int i = 0; i < n; i++)
		arrayAllocate[i] = i;
	//cout << "Done!" << endl;

	//for (int i = 0; i < 100; i++)
	//	cout << "array[" << i << "]: " << arrayAllocate[i] << endl;

	//cout << "Freeing memory...";
	//delete[] arrayAllocate;
	//cout << "Done!" << endl;

	return arrayAllocate;
}

static long long int* AllocateArrayLong(long long int n) { // add values to p array and allocate memory (with long long)

	cout << "Reserving memory...";
	long long int* arrayAllocate = new long long int[n];
	cout << "Done!" << endl;

	cout << "Assigning data into array...";
	for (long long int i = 0; i < n; i++)
		arrayAllocate[i] = i;
	cout << "Done!" << endl;

	return arrayAllocate;
}

int timesExecuted = 10; //how many times the searches are repeated

bool MeasureLinearSearch(int lenght, int x) {

	int n = lenght; //length
	int* arr = AllocateArray(n); //array
	//int x = 43; //element to find

	auto start = high_resolution_clock::now(); // start measuring time

	for (int i = 0; i < timesExecuted; i++) {
		LinearSearch(arr, x, n); // execute linear search
		//cout << "Linear search(a, " << x << ", " << n << ") = " << LinearSearch(arr, x, n) << endl; // execute linear search
	}

	auto end = high_resolution_clock::now(); // stop measuring time

	auto duration = duration_cast<microseconds>((end - start) / timesExecuted); // count duration
	cout << "Linear search execution Time: " << duration.count() << " microseconds" << endl; // duration

	return true;
}

bool MeasureBinarySearch(int length, int x) {
	int n = length; //length
	int* arr = AllocateArray(n); //array
	//int x = 43; //element to find

	auto start = high_resolution_clock::now(); // start measuring time

	for (int i = 0; i < timesExecuted; i++) {
		BinarySearch(arr, x, n); // execute binary search
		//cout << "Binary search(a, " << x << ", " << n << ") = " << BinarySearch(arr, x, n) << endl; // execute binary search
	}

	auto end = high_resolution_clock::now(); // stop measuring time

	auto duration = duration_cast<microseconds>((end - start) / timesExecuted); // count duration
	cout << "Binary search execution Time: " << duration.count() << " microseconds" << endl; // duration

	return true;
}

// MAIN
int main()
{
	// Get a different random number each time the program runs
	srand(time(0));
	int randInt1 = rand() % 100001;
	int randInt2 = rand() % 1000001;
	int randInt3 = rand() % 10000001;

	// LINEAR SEARCH
	cout << endl << "LINEAR SEARCH WITH LIST LENGHT OF 100 000: " << endl;
	MeasureLinearSearch(100000, randInt1);
	cout << endl << "LINEAR SEARCH WITH LIST LENGHT OF 1 000 000: " << endl;
	MeasureLinearSearch(1000000, randInt2);
	cout << endl << "LINEAR SEARCH WITH LIST LENGHT OF 10 000 000: " << endl;
	MeasureLinearSearch(10000000, randInt3);

	cout << endl;

	// BINARY SEARCH
	cout << endl << "BINARY SEARCH WITH LIST LENGHT OF 100 000: " << endl;
	MeasureBinarySearch(100000, randInt1);
	cout << endl << "BINARY SEARCH WITH LIST LENGHT OF 1 000 000: " << endl;
	MeasureBinarySearch(1000000, randInt2);
	cout << endl << "BINARY SEARCH WITH LIST LENGHT OF 10 000 000: " << endl;
	MeasureBinarySearch(10000000, randInt3);

	return EXIT_SUCCESS;
}


