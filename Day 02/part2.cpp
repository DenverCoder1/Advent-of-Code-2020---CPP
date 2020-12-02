#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main() {
	ifstream inputFile;

  inputFile.open("input.txt");

  string range, start = "", end = "", pw = "";
	char letter;
	int validCount = 0;

	while (inputFile >> range) {
		// start at beginning of range
		auto p = range.begin();
		start = "", end = "";
		// read characters into start until reach a '-'
		while (*p != '-') {
			start += *p;
			++p;
		}
		// skip the '-'
		++p;
		// read characters into end until end of range string
		while (p < range.end()) {
			end += *p;
			++p;
		}
		// take next character as required letter
		inputFile >> letter;
		// take colon to discard
		inputFile >> pw;
		// read password into pw
		inputFile >> pw;

		// now all the info for the line is stored in variables
		if ((pw.at(stoi(start)-1) == letter) ^ (pw.at(stoi(end)-1) == letter)) {
			++validCount;
		}
	}

	cout << validCount << endl;

  inputFile.close();
  return 0;
}
