#include <cstring>
#include <iostream>

const int STR_LEN = 30;
using namespace std;
template <typename T> T maxn(T *, int);

template <> const char *maxn(const char **ss, int n);
int main() {
  int iArr[7] = {
      1, 43, 2, 34, 12, 53, 22,
  };
  double dArr[4] = {
      2.3,
      4.2,
      15.2,
      2.1,
  };

  const char *cArr[5] = {"teststring1", "teststring", "teststiring", "dd12",
                         "etesf"};
  auto len = sizeof(iArr) / sizeof(iArr[0]);
  auto max_i = maxn(iArr, len);
  cout << "max i = " << max_i << endl;
  auto len1 = sizeof(dArr) / sizeof(dArr[0]);
  auto max_d = maxn(dArr, len1);
  cout << "max d = " << max_d << endl;
  auto max_str = maxn(cArr, 5);
  cout << "max s = " << max_str << endl;
  return 0;
}

template <typename T> T maxn(T *arr, int n) {
  T max = arr[0];
  for (int i = 1; i < n; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}

template <> const char *maxn<const char *>(const char **arr, int n) {
  int max = strlen(arr[0]);
  int max_idx = 0;
  for (int i = 1; i < n; i++) {
    int tmp = strlen(arr[i]);
    if (max < tmp) {
      max = tmp;
      max_idx = i;
    }
  }
  return arr[max_idx];
}
