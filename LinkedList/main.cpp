#include "LinkedList.h"
#include <iostream>

using namespace std;

int main() {
	LinkedList ll;	// calls constructor

	cout << "IsEmpty(): " << ll.IsEmpty() << endl; 

	//ll.Insert(100);
	//ll.Insert(10);
	//ll.Insert(500);

	for (int i = 1; i < 20; i++) {
		ll.Insert(i);
	}

	ll.Print();

	cout << "IsEmpty(): " << ll.IsEmpty() << endl;


	return EXIT_SUCCESS;
}