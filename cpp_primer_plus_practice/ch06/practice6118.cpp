#include <fstream>
#include <iostream>

int main() {
  using namespace std;

  ifstream inFile;
  inFile.open("patrons.txt");

  char ch;
  int count = 0;
  while (inFile >> ch)
    count++;

  inFile.close();

  cout << "There are " << count << " characters." << endl;

  return 0;
}
