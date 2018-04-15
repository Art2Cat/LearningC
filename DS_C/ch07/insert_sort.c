#include "print_arr.h"
#include <stdio.h>

void insertion_sort(int *arr, int size) {
  int tmp, j;
  for (int i = 1; i < size; i++) {
    tmp = arr[i];
    for (j = i; j > 0 && arr[j - 1] > tmp; j--) {
      arr[j] = arr[j - 1];
    }
    arr[j] = tmp;
  }
}

int main(void) {
  int origin[] = {34, 8, 64, 51, 23, 21};
  int size = sizeof(origin) / sizeof(origin[0]);
  puts("origin: ");
  print_arr(size, origin);

  insertion_sort(origin, size);

  puts("after sorted: ");
  print_arr(size, origin);
  return 0;
}
