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

void BST::Print()
{
	PrintTree("", pRoot, false);
}

void BST::PrintTree(const std::string& prefix, const BSTNode* node, bool isLeft)
{
	if (node != nullptr)
	{
		std::cout << prefix;		
		std::cout << (isLeft ? "|---" : "`~");

		// print the value of the node
		std::cout << node->key << std::endl;

		// enter the next tree level - left and right branch (up is left, down is right)
		PrintTree(prefix + (isLeft ? "|   " : "    "), node->pLeft, true);
		PrintTree(prefix + (isLeft ? "|   " : "    "), node->pRight, false);
	}
}

bool BST::Find(int key)
{
	return RecursiveFind(pRoot, key);
}
bool BST::RecursiveFind(BSTNode* pNode, int key)
{
	if (pNode == nullptr || pNode->key == key)	// check if null or the key we're looking for
	{ return pNode;	}

	else if (key < pNode->key)					// check if current key is bigger than we're looking for
	{ return RecursiveFind(pNode->pLeft, key); }

	else										// if current key is smaller than we're looking for
	{ return RecursiveFind(pNode->pRight, key); }
}

int BST::CountNodes()
{
	return RecursiveCountNodes(pRoot);
}
int BST::RecursiveCountNodes(BSTNode* pNode)
{
	if (pNode == nullptr) return 0; // check if null

	return RecursiveCountNodes(pNode->pLeft) + RecursiveCountNodes(pNode->pRight) + 1; 
}

int BST::CountLeaves()
{
	return RecursiveCountLeaves(pRoot);
}
int BST::RecursiveCountLeaves(BSTNode* pNode)
{
	if (pNode == nullptr) return 0; // check if null

	if (pNode->pLeft == nullptr && pNode->pRight == nullptr) return 1; 	//return 1 when no more branches are available

	return RecursiveCountLeaves(pNode->pLeft) + RecursiveCountLeaves(pNode->pRight);
}

bool BST::Delete(int key)
{
	if (!Find(key))
	{ return false; } // check if key to be deleted exists
	else 
	{ pRoot = RecursiveDelete(pRoot, key); }

	return true;
}
BSTNode* BST::RecursiveDelete(BSTNode* root, int key)
{
	if (!root) return root; // if root not found return

	if (key < root->key)  // key is less than root value -> go to left side of root
	{
		root->pLeft = RecursiveDelete(root->pLeft, key);
		return root;
	}

	else if (key > root->key)  // key is greater than root value -> go to right side of root
	{
		root->pRight = RecursiveDelete(root->pRight, key);
		return root;
	}

	if (!root->pLeft) return root->pRight; // no child on left
	if (!root->pRight) return root->pLeft; // no child on right

	BSTNode* node = root->pRight;
	while (node->pLeft) node->pLeft;
	node->pLeft = root->pLeft;
	root = root->pRight;

	return root;
}