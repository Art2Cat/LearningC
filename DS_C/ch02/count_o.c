#include <stdio.h>

int maxSubsequenceSum(const int arr[], int n);

int maxSubsequenceSum1(const int arr[], int n);

int maxSubsequenceSum2(const int arr[], int n);

int main(int argc, char **argv) {
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int result = 0;

  result = maxSubsequenceSum(arr, 5);
  printf("result %d\n", result);
  printf("result %d\n", maxSubsequenceSum1(arr, 5));
  printf("result %d\n", maxSubsequenceSum2(arr, 5));
  return 0;
}

int maxSubsequenceSum(const int arr[], int n) {
  int thisSum, maxSum;
  maxSum = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      thisSum = 0;
      for (int k = i; k <= j; k++) {
        thisSum += arr[k];
      }
      if (thisSum > maxSum) {
        maxSum = thisSum;
      }
    }
  }
  return maxSum;
}

int maxSubsequenceSum1(const int arr[], int n) {
  int thisSum, maxSum;
  maxSum = 0;

  for (int i = 0; i < n; i++) {
    thisSum = 0;
    for (int j = i; j < n; j++) {
      thisSum += arr[j];

      if (thisSum > maxSum) {
        maxSum = thisSum;
      }
    }
  }
  return maxSum;
}

int maxSubsequenceSum2(const int arr[], int n) {
  int thisSum, maxSum;
  thisSum = 0;
  maxSum = 0;

  for (int i = 0; i < n; i++) {
    thisSum += arr[i];

    if (thisSum > maxSum) {
      maxSum = thisSum;
    } else if (thisSum < 0) {
      thisSum = 0;
    }
  }

  return maxSum;
}