#include <iostream>
#include <cstdio>
#include "stack.h"

using namespace std;

bool isVoid(string tagName) {
	string voidElements[] = {
		"area"
		"base",
		"br",
		"col",
		"embed",
		"hr",
		"img",
		"input",
		"link",
		"meta",
		"param",
		"source",
		"track",
		"wbr",
	};
	for (string s : voidElements) {
		if (s == tagName) {
			return true;
		}
	}

	return false;
}

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

		Stack<string> stack;
		char c;

		bool insideTag = false;
		bool closeTag = false;
		bool writingTag = false;

		string tagName = "";

		// now start reading the file one char at a time
		while ((c = fgetc(fp)) != EOF) {
			//cout << c;
			if (c == '<') { // if current char is opentag
				insideTag = true;
				tagName = "";
				closeTag = false;
				writingTag = true;

				char nextChar = fgetc(fp);
				if (nextChar == '/') { // if current char is closing tag
					closeTag = true;
				}
				else {
					tagName += nextChar; // start writing tag
				}
			}
			else if (c == '>' && insideTag) {
				insideTag = false;
				writingTag = false;

				if (!tagName.empty() && !isVoid(tagName)) { // if tag is empty or void element
					if (!closeTag) {
						stack.Push(tagName);
					}
					else {
						if (stack.IsEmpty()) {
							cout << "Tag unknown!" << endl;
							fclose(fp);
							return EXIT_FAILURE;
						}
						string recentTag = stack.Pop();
						if (recentTag != tagName) {
							cout << "Tags not matching: " << recentTag << ", " << tagName << endl;
							fclose(fp);
							return EXIT_FAILURE;
						}
					}
				}
			}
			else if (insideTag) {
				if (isspace(c)) { // ignore whitespace
					writingTag = false;
				}
				else if (writingTag) { // write tag down
					tagName += c;
				}
			}
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