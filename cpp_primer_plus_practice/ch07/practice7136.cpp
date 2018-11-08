#include <iostream>

using namespace std;

void fill_array(double *, const int);

void show_array(const double *, const int);

void reverse_array(double *, const int);

int main() {
  int len = 0;
  cout << "Enter the array length: ";
  cin >> len;
  double *arr = new double[len];
  fill_array(arr, len);
  show_array(arr, len);
  reverse_array(arr, len);
  show_array(arr, len);
  delete[] arr;
  return 0;
}

void fill_array(double *arr, const int len) {

  for (int i = 0; i < len; i++) {
    cout << "Enter numbers: ";
    if (cin >> arr[i]) {
      cin.clear();
    } else if (cin.fail()) {
      break;
    }
  }
}

void show_array(const double *arr, const int len) {
  cout << "Your array is [";
  for (int i = 0; i < len; i++) {
    cout << arr[i] << ", ";
  }
  cout << "]" << endl;
}

void reverse_array(double *arr, const int len) {
  if (len < 4) {
    return;
  }
  for (int i = 1, j = len - 2; i < j; i++, j--) {
    double tmp;
    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  }
}
