#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile;
  string line;

  // tree count
  int trees = 0;

  // column iterator
  int col = 0;

  inputFile.open("input.txt");

  while (inputFile >> line) {
    // check column for tree (loop around at end of line)
    if (line.at(col % line.length()) == '#') {
      trees++;
    }
    // go right by slope
    col += 3;
  }

  cout << trees << endl;

  inputFile.close();
  return 0;
}