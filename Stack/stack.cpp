// Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "stack.h"

using namespace std;

void Stack::Push(int data) 
{
	Node* pNewNode = new Node(data); // create a new node
	pNewNode->pNext = pTop; // new node's next has to point to the old top Node
	pTop = pNewNode; // make top point to the new Node
}

int Stack::Pop() // calling Pop() for an empty stack is NOT recommended
{
	if (IsEmpty()) // if the stack is empty, just return -1
		return -1;

	Node* pToBeDeleted = pTop; // save curent top pointer
	int value = pToBeDeleted->data; // save deleted data
	pTop = pToBeDeleted->pNext; // update Top-pointer
	delete pToBeDeleted; // remove the node to be deleted

	return value; // return deleted top data
}

int Stack::Top()
{
	if (IsEmpty()) // if the stack is empty, just return -1
		return -1;

	return pTop->data; // return top data
}
