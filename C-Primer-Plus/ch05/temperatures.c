#include <stdio.h>

#define CTK 273.16
double fahrenheitToCelsius(double fahrenheit);
double celsiusToKelvin(double celsius);

int main(int argc, char **argv) {
  const double a = -5, b = 380;
  printf("%.2f\n", fahrenheitToCelsius(b));
  printf("%.2f\n", celsiusToKelvin(a));
}

double fahrenheitToCelsius(double fahrenheit) {
  return 5.0 / 9.0 * (fahrenheit - 32);
}

double celsiusToKelvin(double celsius) { return celsius + CTK; }