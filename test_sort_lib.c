#include "sort_lib.h"
#include <stdio.h>

void print_array(const int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  puts("\n");
}

void test_bubble_sort() {

  int arr[] = {
      6, 5, 3, 1, 8, 11, 7, 2, 4, 9,
  };
  printf("Origin: ");
  int n = sizeof(arr) / sizeof(int);
  print_array(arr, n);
  bubble_sort(arr, n);
  printf("Bubble sort result: ");
  print_array(arr, n);
}

void test_cocktail_sort() {

  int arr[] = {
      6, 5, 3, 1, 8, 11, 7, 2, 4, 9,
  };
  printf("Origin: ");
  int n = sizeof(arr) / sizeof(int);
  print_array(arr, n);
  cocktail_sort(arr, n);
  printf("Cocktail sort result: ");
  print_array(arr, n);
}

void test_selection_sort() {

  int arr[] = {
      6, 5, 3, 1, 8, 11, 7, 2, 4, 9,
  };
  printf("Origin: ");
  int n = sizeof(arr) / sizeof(int);
  print_array(arr, n);
  selection_sort(arr, n);
  printf("Cocktail sort result: ");
  print_array(arr, n);
}
int main(void) {
  test_bubble_sort();
  test_cocktail_sort();
  test_selection_sort();
  return 0;
}
