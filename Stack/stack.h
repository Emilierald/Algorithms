#pragma once
#include "node.h"

template<typename T> class Stack {
public: 
	Stack() { pTop = nullptr; }


	bool IsEmpty() { return pTop == nullptr; }


	void Push(T data)
	{
		Node<T>* pNewNode = new Node<T>(data); // create a new node
		pNewNode->pNext = pTop; // new node's next has to point to the old top Node
		pTop = pNewNode; // make top point to the new Node
	}


	T Pop() // calling Pop() for an empty stack is NOT recommended
	{
		if (IsEmpty()) // if the stack is empty, just return -1
			return static_cast<T>(-1);

		Node<T>* pToBeDeleted = pTop; // save curent top pointer
		T value = pToBeDeleted->data; // save deleted data
		pTop = pToBeDeleted->pNext; // update Top-pointer
		delete pToBeDeleted; // remove the node to be deleted

		return value; // return deleted top data
	}


	T Top()
	{
		if (IsEmpty()) // if the stack is empty, just return -1
			return static_cast<T>(-1);

		return pTop->data; // return top data
	}

private:

	Node<T>* pTop;
};