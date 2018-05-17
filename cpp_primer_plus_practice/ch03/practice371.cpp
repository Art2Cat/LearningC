#include <iomanip>
#include <iostream>

const double FACTOR = 0.0833;

int main(void) {
  std::cout << "Enter your height(inches):________\b\b\b\b\b\b\b\b";
  double height;
  std::cin >> height;
  std::cout << std::setprecision(5) << "Your heigh is " << height * FACTOR
            << " feet.\n";
  std::cout << "Hello World" << std::endl;
  return 0;
}
