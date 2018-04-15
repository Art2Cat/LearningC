#include "print_arr.h"
#include <stdio.h>

void insert_sort(int *arr, int size) {
  int tmp, j;
  for (int i = 1; i < size; i++) {
    tmp = arr[i];
    for (j = i; j > 0 && arr[j - 1] > tmp; j--) {
      arr[j] = arr[j - 1];
    }
    arr[j] = tmp;
  }
}

void swap(int *x, int *y) {
  *x = *x ^ *y;
  *y = *x ^ *y;
  *x = *x ^ *y;
}

int median(int *arr, int left, int right) {
  int center = (left + right) / 2;
  if (arr[left] > arr[center]) {
    swap(&arr[left], &arr[center]);
  }
  if (arr[left] > arr[right]) {
    swap(&arr[left], &arr[right]);
  }
  if (arr[center] > arr[right]) {
    swap(&arr[center], &arr[right]);
  }
  swap(&arr[center], &arr[right - 1]);
  return arr[right - 1];
}

void q_sort(int *arr, int left, int right) {
  int i, j, privot;
  if (left + 3 <= right) {
    privot = median(arr, left, right);
    i = left;
    j = right - 1;
    while (1) {
      while (arr[++i] < privot) {
      }
      while (arr[--j] > privot) {
      }
      if (i < j) {
        swap(&arr[i], &arr[j]);
      } else {
        break;
      }
    }
    swap(&arr[i], &arr[right - 1]);
    q_sort(arr, left, i - 1);
    q_sort(arr, i + 1, right);
  } else {
    insert_sort(arr + left, right - left + 1);
  }
}

void quick_sort(int size, int arr[size]) { q_sort(arr, 0, size - 1); }

int main(void) {
  int origin[] = {34, 8, 64, 51, 23, 21};
  int size = sizeof(origin) / sizeof(origin[0]);
  puts("origin: ");
  print_arr(size, origin);

  quick_sort(size, origin);

  puts("after sorted: ");
  print_arr(size, origin);
  return 0;
}
