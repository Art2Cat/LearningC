#include <stdio.h>

void print_arr(int size, const int arr[size]) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  puts("\n");
}
