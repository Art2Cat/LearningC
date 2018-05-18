#include <iostream>

int main(void) {
  const double GALLON_TO_LITER = 3.78541;
  const double MILE_TO_KM = 1.60934;
  using namespace std;
  cout << "Enter your car fuel consumption of EU standards: ";
  double euConsumption, usConsumption;
  double mile, gallon;

  cin >> euConsumption;
  mile = 100 / MILE_TO_KM;
  gallon = euConsumption / GALLON_TO_LITER;
  usConsumption = mile / gallon;

  cout << "Your car fuel consumption of US standards is " << usConsumption
       << " miles of per gallon.\n";
  return 0;
}
