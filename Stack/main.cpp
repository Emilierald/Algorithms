#include <iostream>
#include <cstdio>
#include "stack.h"

using namespace std;


int main(int argc, char** argv) {

	//check amount of parameters (argc)
	if (argc < 2) {
		cout << "Not enough arguments! You called: " << argv[0] << endl;
		return EXIT_FAILURE;
	}
	else {
		cout << "OK, you called: " << argv[0] << " " << argv[1] << endl;

		FILE* fp = NULL;
		errno_t error = fopen_s(&fp, argv[1], "r");

		if (fp == NULL) {
			cout << "Error opening file: " << argv[1] << endl;
			return EXIT_FAILURE;
		} 

		// now start reading the file one char at a time
		while (char c = fgetc(fp) != NULL) {
			cout << c;
		}
		cout << endl;

		fclose(fp); // remember to close the file!!

		return EXIT_SUCCESS;
	}

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