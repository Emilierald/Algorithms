// SortAlgoTime.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;



void SimpleSort(vector<float>& a, int n) {

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (a[j] < a[i])
				swap(a[j], a[i]);
}

bool MeasureSimpleSort(vector<float> arr, int lenght) {

	int n = lenght; //length

	auto start = high_resolution_clock::now(); // start measuring time

	SimpleSort(arr, n);

	auto end = high_resolution_clock::now(); // stop measuring time

	auto duration = duration_cast<microseconds>((end - start)); // count duration
	cout << "Execution Time: " << duration.count() << " microseconds" << endl; // duration

	return true;
}


// MAIN
int main()
{
	//make array 1 (100 000)
	const int minValue1 = 0;
	const int maxValue1 = 100000;
	const int size1 = 100000;

	std::vector<float> array1(size1);

	mt19937 prng1(std::random_device{}());
	uniform_int_distribution<int> dist1(minValue1, maxValue1);

	for (auto& i : array1) {
		i = dist1(prng1);
	}
	
	//make array 2 (1 000 000)
	const int minValue2 = 0;
	const int maxValue2 = 1000000;
	const int size2 = 100000;

	std::vector<float> array2(size2);

	mt19937 prng2(std::random_device{}());
	uniform_int_distribution<int> dist2(minValue2, maxValue2);

	for (auto& i : array2) {
		i = dist2(prng2);
	}
	

	
	//make array 3 (10 000 000)
	const int minValue3 = 0;
	const int maxValue3 = 10000000;
	const int size3 = 1000000;

	std::vector<float> array3(size3);

	mt19937 prng3(std::random_device{}());
	uniform_int_distribution<int> dist3(minValue3, maxValue3);

	for (auto& i : array3) {
		i = dist3(prng3);
	}
	

	// 
	cout << endl << "LIST LENGHT OF 100 000: " << endl;
	MeasureSimpleSort(array1, size1);
	cout << endl << "LIST LENGHT OF 1 000 000: " << endl;
	MeasureSimpleSort(array2, size2);
	cout << endl << "LIST LENGHT OF 10 000 000: " << endl;
	MeasureSimpleSort(array3, size3);

	cout << endl;

	return EXIT_SUCCESS;
}


