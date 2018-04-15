#include "print_arr.h"
#include <stdio.h>

void shell_sort(int *arr, int size) {
  int increment, j, tmp;
  for (increment = size / 2; increment > 0; increment /= 2) {
    for (int i = increment; i < size; i++) {
      tmp = arr[i];
      for (j = i; j >= increment; j -= increment) {
        if (tmp < arr[j - increment]) {
          arr[j] = arr[j - increment];
        } else {
          break;
        }
      }
      arr[j] = tmp;
    }
  }
}

int main(void) {
  int origin[] = {81, 94, 11, 96, 34, 8, 64, 51, 23, 35, 28, 95, 41, 15, 21};
  int size = sizeof(origin) / sizeof(origin[0]);
  puts("origin: ");
  print_arr(size, origin);

  shell_sort(origin, size);

  puts("after sorted: ");
  print_arr(size, origin);
  return 0;
}
