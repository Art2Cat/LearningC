#include <iostream>
#define AST_UNIT 63240;

double convert(double lightYear) { return lightYear * AST_UNIT; }

int main(void) {
  double lightYear;
  std::cout << "Enter the number of light years: ";
  std::cin >> lightYear;
  std::cout << lightYear << " light years = " << convert(lightYear)
            << " astronomical units\n";
  return 0;
}
