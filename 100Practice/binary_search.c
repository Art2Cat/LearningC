#include <stdio.h>

int binarySearch(int arr[], int len, int val);

int main(int argc, char **argv) {
  int result;

  int arr1[] = {0, 5, 7, 8, 12, 13, 14, 17, 32, 32, 52};

  int len = sizeof(arr1) / sizeof(arr1[0]);

  result = binarySearch(arr1, len, 17);
  (result == -1) ? printf(
                       "Element is not present"
                       " in array")
                 : printf(
                       "Element is present at "
                       "index %d",
                       result);
  return 0;
}

int binarySearch(int arr[], int len, int val) {
  int low = 0;
  int high = len - 1;
  while (low <= high) {
    int m = low + (high - low) / 2;
    // Check if x is present at mid
    if (arr[m] == val) {
      return m;
    }

    // If x greater, ignore left half
    if (arr[m] < val) {
      low = m + 1;
    } else {
      // If x is smaller, ignore right half
      high = m - 1;
    }
  }
  // if we reach here, then element was
  // not present
  return -1;
}