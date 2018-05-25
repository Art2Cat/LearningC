#ifndef __SORT_LIB_H__
#define __SORT_LIB_H__

/**
 * Categories -------------- Internal Compare Sorting
 * data structure ---------- array
 * Worst time complexity ---- O(n^2)
 * Optimal time complexity ---- If you can use the internal flag for the first
 * run of the internal loop, use a flag to indicate whether there is a need for
 * swapping. You can reduce the optimal time complexity to O(n). Average time
 * complexity ---- O(n^2) Required auxiliary space ------ O(1) Stability
 * ------------ Stability
 */
void bubble_sort(int arr[], int n);

/*
 * Classification -------------- Internal Compare Sort
 * data structure ---------- array
 * Worst time complexity ---- O(n^2)
 * Optimal time complexity ---- If the sequence has been mostly sorted at the
 * beginning, it will be close to O(n) Average time complexity ---- O(n^2)
 * Required auxiliary space ------ O(1)
 * Stability ------------ Stability
 */
void cocktail_sort(int arr[], int n);

/**
 * Classification -------------- Internal Compare Sort
 * data structure ---------- array
 * Worst time complexity ---- O(n^2)
 * Optimal time complexity ---- O(n^2)
 * Average time complexity ---- O(n^2)
 * Required auxiliary space ------ O(1)
 * Stability ------------ Instability
 */
void selection_sort(int arr[], int n);

/**
 * Classification ------------- Internal Compare Sort
 * data structure ---------- array
 * Worst time complexity - The worst case is that the input sequence is in
 *descending order, and the time complexity is O(n^2) Optimal time complexity
 *---- The best case is that the input sequence is in ascending order, the time
 *complexity O(n) Average time complexity ---- O(n^2) Required auxiliary space
 *------ O(1) Stability ------------ Stability
 */
void insertion_sort(int arr[], int n);

/**
 * Classification -------------- Internal Compare Sort
 * data structure ---------- array
 * Worst time complexity ---- O(n^2)
 * Optimal time complexity ---- O(nlogn)
 * Average time complexity ---- O(n^2)
 * Required auxiliary space ------ O(1)
 * Stability ------------ Stability
 */
void insertion_sort_dichotomy(int arr[], int n);

/**
 * Classification -------------- Internal Compare Sort
 * data structure ---------- array
 * The worst time complexity varies depending on the sequence of steps. The best
 * known O(n(logn)^2) Optimal time complexity ---- O(n) The average time
 * complexity varies according to the sequence of steps. Required auxiliary
 * space ------ O(1) Stability ------------ Instability
 */
void shell_sort(int arr[], int n);

/**
 * Classification -------------- Internal comparison
 * Data Structure ---------- Array
 * Worst time complexity ---- O(nlogn)
 * Optimal time complexity ---- O(nlogn)
 * Average time complexity ---- O(nlogn)
 * Required auxiliary space ------ O(n)
 * Stability ------------ Stable
 */
void merge_sort(int arr[], int n);

/**
 * Classification -------------- Internal Compare Sort
 * data structure ---------- array
 * Worst time complexity ---- O(nlogn)
 * Optimal time complexity ---- O(nlogn)
 * Average time complexity ---- O(nlogn)
 * Required auxiliary space ------ O(1)
 * Stability ------------ Instability
 */
void heap_sort(int arr[], int n);

/**
 * Classification ------------ Internal Compare Sort
 * data structure --------- array
 * Worst time complexity - Each time the selected reference is the largest (or
 * smallest) element, resulting in only one partition at a time, n-1 partitions
 * are needed to end the recursion. Time complexity O(n^2) Optimal time
 * complexity ---- Each time you select the benchmark is a median, so that each
 * time you divide the two partitions evenly, you only need logn times to end
 * the recursion. The time complexity is O ( Nlogn) Average time complexity ----
 * O(nlogn) The required auxiliary space ------ is mainly due to the use of the
 * stack space caused by recursion (used to save local variables such as left
 * and right), depending on the depth of the recursive tree, generally O (logn),
 * the worst O(n) stability ---------- unstable
 */
void quick_sort(int arr[], int n, int m);
#endif
