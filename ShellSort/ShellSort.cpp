// ShellSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;
using namespace std::chrono;

void ShellSort(vector<int>& arr, int n) {

    for (int gap = n / 2; gap > 0; gap = gap / 2) { // gap is half of length, halve gap until 1

        for (int i = gap; i < n; i++) { // loop insertion with gap size until at the end

            int temp = arr[i]; // value of element
            int j = i; // index of element
         
            while (j >= gap && arr[j - gap] > temp) { // Shift elements that are greater than temp to make space
                arr[j] = arr[j - gap]; // place element
                j -= gap; // next index
            }

            //sort(arr[i], j); // sort the gap???

            // Place temp in its correct location
            arr[j] = temp;
        }
    }
}

int main()
{
    //int x = 1000;
    //int x = 10000;
    int x = 1000000;

    vector<int> array(x);
    int size = array.size();

    auto start = high_resolution_clock::now(); // start measuring time

    random_device rnd_device;
    // Specify the engine and distribution.
    mt19937 rand{ rnd_device() };  // Generates random integers
    uniform_int_distribution<int> dist{ 1, 1000 };

    for (int i = 0; i < size; ++i) { // add rand values to array
        array[i] = dist(rand);
    }

    ShellSort(array, size);

    //sort(array.begin(), array.end());

    /*
    //print array
    for (int num : array)
        cout << num << " ";
    cout << endl;
    */
    auto end = high_resolution_clock::now(); // stop measuring time

    auto dur = duration<double, milli>((end - start)); // count duration
    cout << "Execution Time: " << dur.count() << " milliseconds" << endl; // duration

}