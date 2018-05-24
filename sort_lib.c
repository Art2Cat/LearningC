#include "sort_lib.h"
#include <stdio.h>

static void swap(int arr[], int x, int y) {
  int temp = arr[x];
  arr[x] = arr[y];
  arr[y] = temp;
}

void bubble_sort(int arr[], int n) {
  // Each time the largest element is "floated" to the end of the array just
  // like a bubble.
  for (int i = 0; i < n - 1; i++) {
    // Compare adjacent two elements in order to move the larger one backward.
    for (int j = 0; j < n - 1 - i; j++) {

      if (arr[j] > arr[j + 1]) {
        swap(arr, j, j + 1);
      }
    }
  }
}

void cocktail_sort(int arr[], int n) {
  int left = 0;
  int right = n - 1;
  while (left < right) {
    // In the first half, put the largest element behind.
    for (int i = left; i < right; i++) {
      if (arr[i] > arr[i + 1]) {
        swap(arr, i, i + 1);
      }
    }
    right--;
    // In the second half, put the smallest element in front.
    for (int j = right; j > left; j--) {
      if (arr[j - 1] > arr[j]) {
        swap(arr, j - 1, j);
      }
    }
    left++;
  }
}

void selection_sort(int arr[], int n) {
  // i is the end of the sorted array.
  for (int i = 0; i < n - 1; i++) {
    int min = i;

    // Unsorted array.
    for (int j = i + 1; j < n; j++) {
      // Find the minimum value in an unsorted array.
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    if (min != i) {
      // Put at the end of the sorted array, this operation is likely to
      // disrupt the stability, so the choice of sorting is unstable sorting.
      swap(arr, min, i);
    }
  }
}
