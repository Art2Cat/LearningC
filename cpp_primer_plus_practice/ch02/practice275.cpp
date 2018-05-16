#include <iostream>

double convert(double celsius) { return 1.8 * celsius + 32.0; }
int main(void) {
  double celsius, fahrenheit;
  std::cout << "Please enter a Celsius value: ";
  std::cin >> celsius;
  fahrenheit = convert(celsius);
  std::cout << celsius << " degree Celsius is " << fahrenheit
            << " degree Fahrenheit.\n";
  return 0;
}
