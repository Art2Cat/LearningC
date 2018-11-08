#include "sort_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void swap(int arr[], int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void bubble_sort(int arr[], int n)
{
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

void cocktail_sort(int arr[], int n)
{
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

void selection_sort(int arr[], int n)
{
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

void insertion_sort(int arr[], int n)
{
    // Similar sorting cards.
    for (int i = 1; i < n; i++) {
	// The right hand catches a playing card.
	int get = arr[i];
	// The cards on the left hand are always sorted well.
	int j = i - 1;
	// Compare the captured card with the hand from right to left.
	while (j >= 0 && arr[j] > get) {
	    // If the hand is bigger than the card it grabs, move it right.
	    j--;
	}
	// Until the hand is smaller (or equal) than the card caught, insert the
	// caught card to the right of the hand (the relative order of equal
	// elements is not changed, so the insert sort is stable).
	arr[j + 1] = get;
    }
}

void insertion_sort_dichotomy(int arr[], int n)
{
    for (int i = 1; i < n; i++) {
	// The right hand catches a playing card.
	int get = arr[i];
	// The cards on the left hand are always sorted so
	// that you can use the dichotomy.
	int left = 0;
	// The left and right hand borders are initialized.
	int right = i - 1;
	// Position the new card using the dichotomy.
	while (left <= right) {
	    int mid = (left + right) / 2;
	    if (arr[mid] > get) {
		right = mid - 1;
	    } else {
		left = mid + 1;
	    }
	}
	// Move the card to the right of the new card position by
	// one unit to the right.
	for (int j = i - 1; j >= left; j--) {
	    arr[j + 1] = arr[j];
	}
	// Insert the caught card into the hand.
	arr[left] = get;
    }
}

void shell_sort(int arr[], int n)
{
    int h = 0;
    // Generate initial increments.
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
	// Increment decrement
	h = (h - 1) / 3;
    }
}

static void merge(int arr[], int left, int mid, int right)
{
    int len = right - left + 1;
    int temp[10];
    int index = 0;
    int i = left;
    int j = mid + 1;
    while (i <= mid && j <= right) {
	temp[index++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    }
    while (i <= mid) {
	temp[index++] = arr[i++];
    }
    while (j <= right) {
	temp[index++] = arr[j++];
    }
    for (int k = 0; k < len; k++) {
	arr[left++] = temp[k];
    }
}

void merge_sort(int arr[], int n)
{
    // Subarray index, the previous one is arr[left...mid] and the next subarray
    // is arr[mid+1...right].
    int left, mid, right;
    // The size of the subarray i is initially 1, double each round.
    for (int i = 1; i < n; i *= 2) {
	left = 0;
	// The next sub-array exists (need to merge).
	while (left + i < n) {
	    mid = left + i - 1;
	    // The size of the next subarray may not be enough.
	    right = mid + i < n ? mid + i : n - 1;
	    merge(arr, left, mid, right);

	    // The previous subarray index moves backward.
	    left = right + 1;
	}
    }
}

static void heapify(int arr[], int i, int size)
{
    // left index.
    int left_child = 2 * i + 1;
    // right index.
    int right_child = 2 * i + 2;
    // Select the maximum of the current node and the child.
    int max = i;
    if (left_child < size && arr[left_child] > arr[max]) {
	max = left_child;
    }
    if (right_child < size && arr[right_child] > arr[max]) {
	max = right_child;
    }
    if (max != i) {
	// Exchanges the current node with its largest (direct) child node.
	swap(arr, i, max);
	// Call recursively, continue down heap adjustment from current node.
	heapify(arr, max, size);
    }
}

static int build_heap(int arr[], int n)
{
    int heap_size = n;
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
	heapify(arr, i, heap_size);
    }
    return heap_size;
}

void heap_sort(int arr[], int n)
{
    int heap_size = build_heap(arr, n);
    // The number of elements in the heap (unordered) is greater than 1 and the
    // sort is not completed
    while (heap_size > 1) {
	// Interchange the top element of the heap with the last element of the heap
	// and remove the last element from the heap.
	// The swap operation here is very likely to upset the stability of the
	// following elements, so the heap sort is an unstable sort algorithm.
	swap(arr, 0, --heap_size);
	// Heap adjustment starting from the new heap element, time complexity
	// O(logn).
	heapify(arr, 0, heap_size);
    }
}

static int partition(int arr[], int left, int right)
{
    // Here select the last element as a benchmark each time.
    int pivot = arr[right];
    // Tail is the index of the last element of the sub-array that is less than
    // the reference.
    int tail = left - 1;
    // Traverse other elements outside the datum.
    for (int i = left; i < right; i++) {
	// Put the elements that are less than or equal to the baseline at the end
	// of the previous subarray.
	if (arr[i] <= pivot) {
	    swap(arr, ++tail, i);
	}
    }
    // Finally, place the reference behind the previous subarray. The remaining
    // subarrays are both subarrays larger than the reference. This operation is
    // very likely to disturb the stability of the following elements, so quick
    // sorting is an unstable sorting algorithm.
    swap(arr, tail + 1, right);
    // Returns the index of the benchmark.
    return tail + 1;
}

void quick_sort(int arr[], int left, int right)
{
    if (left > right) {
	return;
    }
    int pivot_index = partition(arr, left, right);
    quick_sort(arr, left, pivot_index - 1);
    quick_sort(arr, pivot_index + 1, right);
}

static int *copy_array(const int *arr, int n) {
  int *arr_copy = (int *)calloc(n, sizeof(int));
  memcpy(arr_copy, arr, sizeof(int) * n);
  return arr_copy;
}

void count_sort(int *arr, int n) {

  int max = arr[0];
  int min = arr[0];
  for (int i = 0; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  int range = max - min;
  int count[range + 1];
  memset(count, 0, sizeof(count));
  //int *count = (int *)calloc(range + 1, sizeof(int));
  for (int i = 0; i < n; i++) {
    ++count[arr[i]];
  }

  for (int i = 1; i < range + 1; i++) {
    count[i] += count[i - 1];
  }

  int *copy_of_array = (int *)calloc(n, sizeof(int));
  memcpy(copy_of_array, arr, sizeof(int) * n);
  for (int i = n - 1; i >= 0; i--) {
    arr[count[copy_of_array[i] - min] - 1] = copy_of_array[i];
    count[copy_of_array[i] - min]--;
  }
  free(copy_of_array);
  //free(count);
}
