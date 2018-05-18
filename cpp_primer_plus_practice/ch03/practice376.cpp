#include <iostream>

int main(void) {
  const double GALLON_TO_LITER = 3.78541;
  const double MILE_TO_KM = 1.60934;
  using namespace std;
  cout << "Enter your car mileage(mile): ";
  double mileage, gallon;

  cin >> mileage;
  cout << "Enter the gasoline usage(gallon): ";
  cin >> gallon;
  double perGallonOfMile;
  perGallonOfMile = mileage / gallon;
  cout << "Your car fuel consumption of US standards is " << perGallonOfMile
       << " miles of per gallon.\n";
  cout << "Do your want to show the EU standards?(y/n): ";
  char option;
  cin >> option;
  if (option == 'y') {
    double km = mileage * MILE_TO_KM;
    double liter = (gallon * GALLON_TO_LITER / km) * 100;
    cout << "Your car fuel consumption of EU standards is " << liter
         << " liters of 100 kilometers.\n";
  }
  return 0;
}
