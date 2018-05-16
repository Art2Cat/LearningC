#include <iostream>

void printMice();
void miceRun();

using namespace std;

int main(void) {
  std::cout << "hello world" << std::endl;
  printMice();
  printMice();
  miceRun();
  miceRun();
  return 0;
}

void printMice() { cout << "Three blind mice\n"; }

void miceRun() { cout << "See how they run\n"; }
