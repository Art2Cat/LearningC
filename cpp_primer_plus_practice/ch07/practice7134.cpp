#include <iostream>

using namespace std;
long double probability(unsigned numbers, unsigned picks);

int main() {
  double total = 47, choices = 5;
  double sp_total = 27, sp_choices = 1;

  cout << "You have on chance in "
       << probability(total, choices) * probability(sp_total, sp_choices)
       << " of winning." << endl;
  return 0;
}

long double probability(unsigned numbers, unsigned picks) {
  long double result = 1.0;
  long double n;
  unsigned p;
  for (n = numbers, p = picks; p > 0; n--, p--) {
    result = result * n / p;
  }
  return result;
}
