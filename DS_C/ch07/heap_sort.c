#include <stdio.h>

#define LEFT_CHILD(i) (2 * (i) + 1)

void swap(int *x, int *y) {
  *x = *x ^ *y;
  *y = *x ^ *y;
  *x = *x ^ *y;
}

void perc_down(int arr[], int i, int size) {
  int child;
  int tmp;

  for (tmp = arr[i]; LEFT_CHILD(i) < size; i = child) {
    child = LEFT_CHILD(i);
    if (child != size - 1 && arr[child + 1] > arr[child])
      child++;
    if (tmp < arr[child])
      arr[i] = arr[child];
    else
      break;
  }
  arr[i] = tmp;
}

void Heapsort(int arr[], int size) {
  int i;

  for (i = size / 2; i >= 0; i--)
    perc_down(arr, i, size);
  for (i = size - 1; i > 0; i--) {
    swap(&arr[0], &arr[i]);
    perc_down(arr, 0, i);
  }
}
