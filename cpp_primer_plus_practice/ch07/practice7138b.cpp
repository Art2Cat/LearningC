#include <iostream>

using namespace std;
const int SEASONS = 4;
const char *S_NAME[SEASONS] = {
    "Spring",
    "Summer",
    "Autumn/Fall",
    "Winter",
};

struct expenses {
  double values[SEASONS];
};

void fill(expenses *);

void show(expenses);

int main() {
  expenses *exp = new expenses;
  fill(exp);
  show(*exp);
  delete exp;
  return 0;
}

void fill(expenses *exp) {
  for (int i = 0; i < SEASONS; i++) {
    cout << "Enter " << S_NAME[i] << " expenses: ";
    cin >> exp->values[i];
  }
}

void show(expenses exp) {
  double total = 0.0;
  cout << "\nEXPENSES\n";
  for (int i = 0; i < SEASONS; i++) {
    cout << S_NAME[i] << ": $" << exp.values[i] << endl;
    total += exp.values[i];
  }
  cout << "Total Expenses: $" << total << endl;
}
