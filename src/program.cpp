#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main() {
  // Input and output file names
  std::string fileName;

  std::cout << "Enter your file name: ";
  std::cin >> fileName;
  string inputFilename = "../input/"+fileName;
  string outputFilename = "../output/"+fileName;

  // Create a set to store unique integers
  set<int> uniqueNumbers;

  // Open the input file
  ifstream inputFile(inputFilename);
  if (!inputFile.is_open()) {
    cerr << "Error opening input file: " << inputFilename << endl;
    return 1;
  }

  // Read integers from the input file and add them to the set
  int number;
  while (inputFile >> number) {
    uniqueNumbers.insert(number);
  }

  inputFile.close();

  // Open the output file for writing
  std::fstream outputFile(outputFilename, std::ios::out | std::ios::app);
  if (!outputFile.is_open()) {
    cerr << "Error opening output file: " << outputFilename << endl;
   outputFile.open(outputFilename,  fstream::in | fstream::out | fstream::trunc);
  }

  // Sort the unique numbers and write them to the output file
  for (int num : uniqueNumbers) {
    outputFile << num << endl;
  }

  outputFile.close();

  cout << "Unique integers written to " << outputFilename << endl;

  return 0;
}