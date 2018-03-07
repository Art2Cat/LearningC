#include <stdio.h>

int find_max(int* source, int length) {
  int max = source[0];
  for (int i = 0; i < length; i++) {
    if (source[i] > max) {
      max = source[i];
    }
  }
  return max;
}

int main(void) {
  int source[10] = {5, 0, 6, 7, 8, 1, 2, 99, 4, 3};
  int max = find_max(source, 10);
  printf("source[10] max number is : %d", max);

  return 0;
}