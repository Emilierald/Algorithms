#include <iostream>
#include "bst.h"

using namespace std;


void BST::Insert(int key) // inserts smaller values left, and equal or greater than values to the right
{
	BSTNode* pNewNode = new BSTNode(key); // create a new node

	if (IsEmpty()) { // if the tree is empty

		// set the new node as the root node
		pRoot = pNewNode;
		return;
	}
	else { // if the tree is not empty
		
		BSTNode* pCurrent = pRoot;
		BSTNode* pCandidate = pRoot;


		while (pCandidate != nullptr) {
			pCurrent = pCandidate;
			if (pNewNode->key < pCurrent->key) {
				pCandidate = pCurrent->pLeft;
			}
			else {
				pCandidate = pCurrent->pRight;
			}
			if (pCandidate != nullptr) {
				pCurrent = pCandidate;
			}
		}


		// check which direction we need to put the new node
		if (pNewNode->key < pCurrent->key) {
			pCurrent->pLeft = pNewNode;
		}
		else {
			pCurrent->pRight = pNewNode;
		}

	}
}
