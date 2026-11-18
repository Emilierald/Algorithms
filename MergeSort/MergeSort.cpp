// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;
using namespace std::chrono;

void MergingAndSorting(vector<int>& vec, int left, int mid, int right) {

    int i, j, k; //
    int n1 = mid - left + 1; // left half
    int n2 = right - mid; // right half

    vector<int> leftList(n1), rightList(n2); // temp vectors for left and right

    for (i = 0; i < n1; i++) // add data to left vector
        leftList[i] = vec[left + i];
    for (j = 0; j < n2; j++) // add data to right vector
        rightList[j] = vec[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) { // merge so that smaller element is left
        if (leftList[i] <= rightList[j]) {
            vec[k] = leftList[i];
            i++;
        }
        else {
            vec[k] = rightList[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vec[k] = leftList[i];
        i++;
        k++;
    }

    while (j < n2) {
        vec[k] = rightList[j];
        j++;
        k++;
    }
}

// The subarray to be sorted is in the index range [left..right]
void MergeSort(vector<int>& vec, int left, int right) {

    if (left < right) {
     
        int mid = left + (right - left) / 2; // get middle

        MergeSort(vec, left, mid); // get first half
        MergeSort(vec, mid + 1, right); // get second half

        MergingAndSorting(vec, left, mid, right); // merge and sort the halves
    }
}

int main()
{
    //int x = 1000;
    //int x = 10000;
    int x = 1000000;

    vector<int> array(x);
    int size = array.size();

    random_device rnd_device;
    // Specify the engine and distribution.
    mt19937 rand{ rnd_device() };  // Generates random integers
    uniform_int_distribution<int> dist{ 1, 1000 };

    for (int i = 0; i < size; ++i) { // add rand values to array
        array[i] = dist(rand);
    }

    auto start = high_resolution_clock::now(); // start measuring time

    MergeSort(array, 0, size - 1);

    //sort(array.begin(), array.end());

    /*
    //print array
    for (int num : array)
        cout << num << " ";
    cout << endl;*/

    auto end = high_resolution_clock::now(); // stop measuring time

    auto dur = duration<double, milli>((end - start)); // count duration
    cout << "Execution Time: " << dur.count() << " milliseconds" << endl; // duration

}