#include <iostream>

using namespace std;
const int SEASONS = 4;
const char *S_NAME[SEASONS] = {
    "Spring",
    "Summer",
    "Autumn/Fall",
    "Winter",
};

void fill(double da[SEASONS]);

void show(const double da[SEASONS]);

int main() {
  double *expenses = new double[SEASONS];
  fill(expenses);
  show(expenses);
  delete[] expenses;
  return 0;
}

void fill(double da[SEASONS]) {
  for (int i = 0; i < SEASONS; i++) {
    cout << "Enter " << S_NAME[i] << " expenses: ";
    cin >> da[i];
  }
}

void show(const double da[SEASONS]) {
  double total = 0.0;
  cout << "\nEXPENSES\n";
  for (int i = 0; i < SEASONS; i++) {
    cout << S_NAME[i] << ": $" << da[i] << endl;
    total += da[i];
  }
  cout << "Total Expenses: $" << total << endl;
}
