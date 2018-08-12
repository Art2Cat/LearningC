#include <iostream>

using namespace std;
const int MAX = 5;
double *fill_array(double arr[], int limit);

void show_array(const double *arr, const double *n);

void revalue(double r, double *arr, const double *n);

int main() {
  double properties[MAX];
  double *size = fill_array(properties, MAX);

  show_array(properties, size);

  if (size != NULL) {
    cout << "Enter revaluation factor: ";
    double factor;
    while (!(cin >> factor)) {
      cin.clear();
      while (cin.get() != '\n') {
        continue;
      }
      cout << "Bad input; Please enter a number: ";
    }
    revalue(factor, properties, size);
    show_array(properties, size);
  }
  cout << "Done." << endl;
  return 0;
}

double *fill_array(double arr[], int limit) {
  double tmp;
  int i;
  for (i = 0; i < limit; i++) {
    cout << "Enter value #" << i << ": ";
    cin >> tmp;
    if (!cin) {
      cin.clear();
      while (cin.get() != '\n') {
        continue;
      }
      cout << "Bad input; input process terminated." << endl;
      break;
    } else if (tmp < 0) {
      break;
    }
    arr[i] = tmp;
  }
  return &arr[i];
}

void show_array(const double *arr, const double *n) {
  for (int i = 0; arr < n; arr++, i++) {
    cout << "Property #" << i << ": $";
    cout << *arr << endl;
  }
}

void revalue(double r, double *arr, const double *n) {
  for (; arr < n; arr++) {
    *arr = (*arr) * r;
  }
}
