#include <iostream>

const double FACTOR = 0.0166667;

int main(void) {
  double degrees, minutes, seconds;
  std::cout << "Enter a latitude in degrees, minutes, and seconds:"
            << std::endl;
  std::cout << "First, enter the degrees: ";
  std::cin >> degrees;
  std::cout << "Next, enter the minutes of arc: ";
  std::cin >> minutes;
  std::cout << "Finally, enter the secods of arc: ";
  std::cin >> seconds;
  std::cout << degrees << " degrees, ";
  std::cout << minutes << " minutes, ";
  std::cout << seconds << " seconds = ";
  std::cout << degrees + minutes * FACTOR + seconds * FACTOR * FACTOR
            << " degrees" << std::endl;
}
