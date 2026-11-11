#pragma once
#include <vector>

class Heap {
public: 
	
	Heap(int maxSize = 10000000) {
		heapArray.resize(maxSize + 1);
		heapArray[0] = 0;
	}

	void Insert(int key);
	void Print();
	void DeleteMin();
	int Length() { return heapArray[0]; } // just return cuurent length (stored at index 0)

private: 
	
	std::vector<int> heapArray;
};