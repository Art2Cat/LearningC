#include "sort_lib.h"
#include <stdio.h>

void print_array(const int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  puts("\n");
}

void test_bubble_sort() {
  int arr[10] = {
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
  int arr[10] = {
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
  int arr[10] = {
      6, 5, 3, 1, 8, 11, 7, 2, 4, 9,
  };
  printf("Origin: ");
  int n = sizeof(arr) / sizeof(int);
  print_array(arr, n);
  selection_sort(arr, n);
  printf("Selection sort result: ");
  print_array(arr, n);
}

void test_insertion_sort() {
  int arr[10] = {
      6, 5, 3, 1, 8, 11, 7, 2, 4, 9,
  };
  printf("Origin: ");
  int n = sizeof(arr) / sizeof(int);
  print_array(arr, n);
  selection_sort(arr, n);
  printf("Insertion sort result: ");
  print_array(arr, n);
}

void test_insertion_sort_dichotomy() {
  int arr[10] = {
      6, 5, 3, 1, 8, 11, 7, 2, 4, 9,
  };
  printf("Origin: ");
  int n = sizeof(arr) / sizeof(int);
  print_array(arr, n);
  insertion_sort_dichotomy(arr, n);
  printf("Insertion sort dichotomy result: ");
  print_array(arr, n);
}

void test_shell_sort() {
  int arr[10] = {
      6, 5, 3, 1, 8, 11, 7, 2, 4, 9,
  };
  printf("Origin: ");
  int n = sizeof(arr) / sizeof(int);
  print_array(arr, n);
  shell_sort(arr, n);
  printf("Shell sort result: ");
  print_array(arr, n);
}

void test_merge_sort() {
  int arr[10] = {
      6, 5, 3, 1, 8, 11, 7, 2, 4, 9,
  };
  printf("Origin: ");
  int n = sizeof(arr) / sizeof(int);
  print_array(arr, n);
  merge_sort(arr, n);
  printf("Merge sort result: ");
  print_array(arr, n);
}

void test_heap_sort() {
  int arr[10] = {
      6, 5, 3, 1, 8, 11, 7, 2, 4, 9,
  };
  printf("Origin: ");
  int n = sizeof(arr) / sizeof(int);
  print_array(arr, n);
  heap_sort(arr, n);
  printf("Heap sort result: ");
  print_array(arr, n);
}

void test_quick_sort() {
  int arr[10] = {
      6, 5, 3, 1, 8, 11, 7, 2, 4, 9,
  };
  printf("Origin: ");
  int n = sizeof(arr) / sizeof(int);
  print_array(arr, n);
  quick_sort(arr, 0, n - 1);
  printf("Quick sort result: ");
  print_array(arr, n);
}

void test_count_sort() {
  int arr[10] = {
      6, 5, 3, 1, 8, 0, 7, 2, 4, 9,
  };
  printf("Origin: ");
  print_array(arr, 10);
  count_sort(arr, 10);
  printf("Count sort result: ");
  print_array(arr, 10);
}

int main(void) {
  test_bubble_sort();
  test_cocktail_sort();
  test_selection_sort();
  test_insertion_sort();
  test_insertion_sort_dichotomy();
  test_shell_sort();
  test_merge_sort();
  test_heap_sort();
  test_quick_sort();
  test_count_sort();
  return 0;
}
