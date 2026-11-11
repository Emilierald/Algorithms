#include "heap.h"
#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;


int main() {

	Heap myHeap;

	int heapSizes[] = { 100000, 1000000, 10000000 }; 

	for (int a : heapSizes) {

		//randomize values
		mt19937 seed(5);
		uniform_int_distribution<int> dist(1, 1000);

		vector<int> data(a);
		for (int i = 0; i < a; ++i)
		{
			data[i] = dist(seed);
		}

		//add random values
		for (int i = 0; i < a; ++i)
		{
			myHeap.Insert(data[i]);
		}

		auto start = high_resolution_clock::now(); // start measuring time

		for (int i = 0; i < a; i++) {
			myHeap.DeleteMin();
		}

		auto end = high_resolution_clock::now(); // stop measuring time

		auto dur = duration<double, milli>((end - start)); // count duration
		cout << "Execution Time: " << dur.count() << " microseconds" << endl; // duration

	}

	/*
	myHeap.Insert(17);
	myHeap.Insert(11);
	myHeap.Insert(6);
	myHeap.Insert(14);
	myHeap.Insert(22);
	myHeap.Insert(8);
	myHeap.Insert(1);
	myHeap.Insert(16);
	myHeap.Insert(10);
	myHeap.Insert(19);
	myHeap.Insert(12);
	myHeap.Insert(3);
	myHeap.Insert(5);
	myHeap.Insert(15);
	myHeap.Insert(13);

	myHeap.Print();

	myHeap.DeleteMin();

	myHeap.Print();
	*/
	return EXIT_SUCCESS;
}