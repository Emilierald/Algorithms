#pragma once
#include "node.h"

class Stack {
public: 
	Stack() { pTop = nullptr; }
	bool IsEmpty() { return pTop == nullptr; }
	void Push(int data);
	int Pop();
	int Top();

private:

	Node* pTop;
};