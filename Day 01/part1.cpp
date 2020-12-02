#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile;
  string line;
  // can be made more space efficient with unordered set
  int seen[10000] = { 0 };

  inputFile.open("input.txt");

  while (inputFile >> line) {
    // convert to int
    int num = stoi(line);
    // if the 2020 - num has been seen, we found the pair
    if (seen[2020 - num]) {
      cout << num << "*" << (2000 - num);
      cout << " = " << (num * (2000 - num));
      break;
    }
    // mark current number as seen
    seen[num] = 1;
  }

  inputFile.close();
  return 0;
}