#include "LinkedList.h"
#include <iostream>

using namespace std;

int main() {
	LinkedList ll;	// calls constructor

	int count = 99;

	cout << "IsEmpty(): " << ll.IsEmpty() << endl; 

	//ll.Insert(100);
	//ll.Insert(10);
	//ll.Insert(500);

	for (int i = 1; i < count; i++) {
		ll.Insert(i);
	}
	
	ll.Print();

	cout << "Find(): " << ll.Find(22) << endl;
	cout << "Find(): " << ll.Find(100) << endl;

	cout << "Delete():" << ll.Delete(42) << endl;
	cout << "Delete():" << ll.Delete(120) << endl;


	for (int i = count; i >= 1; i--) {
		ll.Delete(i);
	}

	ll.Print();

	cout << "IsEmpty(): " << ll.IsEmpty() << endl;


	return EXIT_SUCCESS;
}