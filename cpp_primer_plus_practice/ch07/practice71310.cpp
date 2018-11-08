#include <iostream>

using namespace std;

double add(double, double);
double calculate(double, double, double (*pf)(double, double));

int main() {
  double x, y;
  cout << "Enter two numbers: ";
  cin >> x >> y;
  double q = calculate(x, y, add);
  cout << q << " is the sum of " << x << " and " << y << ".\n";

  return 0;
}

double add(double x, double y) { return x + y; }

double calculate(double x, double y, double (*pf)(double, double)) {
  return pf(x, y);
}
