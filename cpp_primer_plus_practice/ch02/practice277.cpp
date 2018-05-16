#include <iostream>

void printTime(int hours, int minutes);

int main(void) {
  int hours, minutes;
  std::cout << "Enter the number of hours: ";
  std::cin >> hours;
  std::cout << "Enter the number of minutes: ";
  std::cin >> minutes;
  printTime(hours, minutes);
  return 0;
}

void printTime(int hours, int minutes) {
  std::cout << "Time: " << hours << ":" << minutes << std::endl;
}
