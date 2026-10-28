#pragma once
#include "bstnode.h"

class BST
{
public: 
	BST() { pRoot = nullptr;  } // constructor, just set the root-node to null

	bool IsEmpty() { return pRoot == nullptr;  } // returns true if pRoot is null
	void Insert(int key);

	void Print();
	bool Find(int key);

	int CountNodes();
	int CountLeaves();

	bool Delete(int key);

private:

	BSTNode* pRoot; // popinter to the root-node of the BST

	void PrintTree(const std::string& prefix, const BSTNode* node, bool isLeft);

	bool RecursiveFind(BSTNode* pNode, int key);

	int RecursiveCountNodes(BSTNode* pNode);

	int RecursiveCountLeaves(BSTNode* pNode);

	BSTNode* RecursiveDelete(BSTNode* root, int key);

};

