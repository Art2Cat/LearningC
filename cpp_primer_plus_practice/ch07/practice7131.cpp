#include <iostream>

using namespace std;
const double FACTORY = 2.0;

double average(double, double);

int main() {
  double x = 0, y = 0;
  while (true) {
    cout << "Enter two numbers(use space to seperate): ";
    cin >> x >> y;
    if (x == 0 || y == 0) {
      break;
    }

    cout << "the average of reciprocal is :" << average(x, y) << endl;
  }
  cout << "exit!" << endl;
  return 0;
}

double average(double x, double y) { return FACTORY * x * y / (x + y); }
