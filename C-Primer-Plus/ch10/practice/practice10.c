#include <stdio.h>
#define SIZE 4

void sum_copy(int size, int target[size], int source[size], int source1[size]);

int main(int argc, char **argv) {
  int source[SIZE] = {2, 4, 5, 8};
  int source1[SIZE] = {1, 0, 4, 6};
  int target[SIZE];
  sum_copy(SIZE, target, source, source1);
  for (int i = 0; i < SIZE; i++) {
    printf("target[%d] = %d\n", i, target[i]);
  }
  return 0;
}

void sum_copy(int size, int target[size], int source[size], int source1[size]) {
  for (int i = 0; i < size; i++) {
    target[i] = source[i] + source1[i];
  }
}