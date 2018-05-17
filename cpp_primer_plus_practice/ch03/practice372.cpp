#include <iostream>

const double FOOT_TO_INCHE = 12;
const double INCHE_TO_METER = 0.0254;
const double POUND_TO_KG = 0.4536;

int main(void) {
  using namespace std;
  double kilogram, pound, feet, inches, height;
  cout << "Enter your height(feet):";
  cin >> feet;
  cout << "Enter your height(inches):";
  cin >> inches;
  height = (feet * FOOT_TO_INCHE + inches) * INCHE_TO_METER;
  cout << "Enter your weight(pound):";
  cin >> pound;
  kilogram = pound * POUND_TO_KG;
  cout << "Your BMI is " << kilogram / (height * height) << endl;
  return 0;
}
