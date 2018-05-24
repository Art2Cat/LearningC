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

void insertion_sort(int arr[], int n) {
  // Similar sorting cards
  for (int i = 1; i < n; i++) {
    // The right hand catches a playing card
    int get = arr[i];
    // The cards on the left hand are always sorted well
    int j = i - 1;
    // Compare the captured card with the hand from right to left
    while (j >= 0 && arr[j] > get) {
      // If the hand is bigger than the card it grabs, move it right
      j--;
    }
    // Until the hand is smaller (or equal) than the card caught, insert the
    // caught card to the right of the hand (the relative order of equal
    // elements is not changed, so the insert sort is stable)
    arr[j + 1] = get;
  }
}

void insertion_sort_dichotomy(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    // The right hand catches a playing card
    int get = arr[i];
    // The cards on the left hand are always sorted so
    // that you can use the dichotomy.
    int left = 0;
    // The left and right hand borders are initialized
    int right = i - 1;
    // Position the new card using the dichotomy
    while (left <= right) {
      int mid = (left + right) / 2;
      if (arr[mid] > get) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    // move the card to the right of the new card position by
    // one unit to the right
    for (int j = i - 1; j >= left; j--) {
      arr[j + 1] = arr[j];
    }

    arr[left] = get; // Insert the caught card into the hand
  }
}

void shell_sort(int arr[], int n) {
  int h = 0;
  // generate initial increments.
  while (h <= n) {
    h = 3 * h + 1;
  }
  while (h >= 1) {
    for (int i = h; i < n; i++) {
      int j = i - h;
      int get = arr[i];
      while (j >= 0 && arr[j] > get) {
        arr[j + h] = arr[j];
        j = j - h;
      }
      arr[j + h] = get;
    }
    // increment decrement
    h = (h - 1) / 3;
  }
}
