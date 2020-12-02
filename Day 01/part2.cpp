#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main() {
  const int LINES = 200;
  ifstream inputFile;
  string line;
  int input[LINES] = { 0 };

  inputFile.open("input.txt");

  // collect file into array
  for (int i = 0; i < LINES; ++i) {
    inputFile >> line;
    // store as a number
    input[i] = stoi(line);
  }

  int remaining1, remaining2;

  for (int i = 0; i < LINES; ++i) {
    remaining1 = 2020 - input[i];
    for (int j = i + 1; j < LINES; ++j) {
      remaining2 = remaining1 - input[j];
      for (int k = j + 1; k < LINES; ++k) {
        if (input[k] == remaining2) {
          cout << input[i] << "*" << input[j] << "*" << input[k];
          cout << " = " << (input[i] * input[j] * input[k]);
        }
      }
    }
  }

  inputFile.close();
  return 0;
}