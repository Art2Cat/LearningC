#include <iostream>

int main(void) {
  int age, hours, minutes;
  std::cout << "Enter your age: ";
  std::cin >> age;
  std::cout << "Enter the number of hours: ";
  std::cin >> hours;
  std::cout << "Enter the number of minutes: ";
  std::cin >> minutes;
  std::cout << age << " years has " << age * 12 << "months\n";
  std::cout << "Time: " << hours << ":" << minutes << std::endl;
  return 0;
}
