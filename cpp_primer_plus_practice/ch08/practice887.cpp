#include <iostream>

using namespace std;

template <typename T> double sumArray(T *arr, int n);

template <typename T> double sumArray(T *arr[], int n);
struct debts {
  char name[50];
  double amount;
};

int main() {
  int things[6] = {
      13, 31, 103, 301, 310, 130,
  };

  debts mr_a[3] = {
      {"Ima Wolfe", 2400.2}, {"Ura Foxe", 1300.0}, {"Iby Stout", 1800.0}};

  double *pd[3];
  for (int i = 0; i < 3; i++) {
    pd[i] = &mr_a[i].amount;
  }

  cout << sumArray(things, 6) << endl;
  cout << sumArray(pd, 3) << endl;
  return 0;
}

template <typename T> double sumArray(T *arr, int n) {
  auto max = arr[0];
  for (int i = 1; i < n; i++) {
    max += arr[i];
  }
  return max;
}

template <typename T> double sumArray(T *arr[], int n) {
  auto max = *arr[0];
  for (int i = 1; i < n; i++) {
    max += *arr[i];
  }
  return max;
}
