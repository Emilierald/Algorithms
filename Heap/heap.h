#pragma once
#define MAX_SIZE 255

class Heap {
public: 
	
	Heap() {
		heapArray[0] = 0;
	}

	void Insert(int key);
	int Del_min();
	void Print();
	int Length() { return heapArray[0]; } // just return cuurent length (stored at index 0)

private: 
	
	int heapArray[MAX_SIZE + 1];
};