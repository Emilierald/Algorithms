#include <iostream>
#include "stack.h"

using namespace std;


int main(int argc, char** argv) {

	Stack<int> stack; // stack

	for (int i = 0; i < 10; i++) { // push data in (0-9)
		stack.Push(i);
		cout << stack.Top() << endl;
	}

	cout << "---- end push -------- begin pop -----" << endl;

	for (int i = 0; i < 10; i++) { // pop data out (9-0)
		int  value = stack.Pop();
		cout << value << endl;
	}

	return EXIT_SUCCESS;
}