#include <iostream>
const int LEN{5};

template <typename T> T max5(T *);

int main() {
  int iArr[LEN] = {11, 32, 34, 14, 25};
  auto max = max5(iArr);
  std::cout << "max = " << max << std::endl;
  double dArr[LEN] = {12.3, 32.2, 13.2, 45.3, 12.6};
  auto max1 = max5(dArr);
  std::cout << "max = " << max1 << std::endl;
  return 0;
}

template <typename T> T max5(T arr[LEN]) {
  T max = arr[0];
  for (int i = 1; i < LEN; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}
