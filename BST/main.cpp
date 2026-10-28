#include <iostream>
#include "bst.h"

using namespace std;

int main() {
	BST bst;
	bst.Insert(5);
	bst.Insert(2);
	bst.Insert(8);
	bst.Insert(4);
	bst.Insert(3);
	bst.Insert(7);
	bst.Insert(6);
	bst.Insert(9);
	bst.Insert(10);

	bst.Print();

	if (bst.Find(20))
	{
		cout << endl << "number found" << endl;
	}
	cout << endl << bst.CountNodes() << endl;

	cout << endl << bst.CountLeaves() << endl;

	bst.Delete(7);

	bst.Print();


	return EXIT_SUCCESS;
}