#include <stdio.h>

int binarySearch(const int *, int len, int x);

int main(int argc, char **argv) {
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int len = sizeof(arr) / sizeof(arr[0]);
  printf("number 5 position is %d.\n", binarySearch(arr, len, 5));
  return 0;
}

int binarySearch(const int *arr, int len, int x) {
  int low, mid, high;
  low = 0;
  high = len - 1;
  while (low <= high) {
    mid = (high + low) / 2;
    if (arr[mid] < x) {
      low = mid + 1;
    } else if (arr[mid] > x) {
      high = mid - 1;
    } else {
      return mid;
    }
  }
  return -1;
}