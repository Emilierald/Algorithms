#pragma once
#include "bstnode.h"

class BST
{
public: 
	BST() { pRoot = nullptr;  } // constructor, just set the root-node to null

	bool IsEmpty() { return pRoot == nullptr;  } // returns true if pRoot is null
	void Insert(int key);

private:

	BSTNode* pRoot; // popinter to the root-node of the BST
};

