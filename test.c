#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int *copy_array(const int *arr, int n) {
  int *arr_copy = (int *)calloc(n, sizeof(int));
  memcpy(arr_copy, arr, sizeof(int) * n);
  return arr_copy;
}
int main(void) {
  int arr[5] = {1, 2, 3, 4, 5};

  int *arr_copy = copy_array(arr, 5);
  for (int i = 0; i < 5; i++) {
    printf("%d : %d\n", arr[i], arr_copy[i]);
  }
  return 0;
}
