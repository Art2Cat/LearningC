#include <stdio.h>

int find_max_index(double* source, int length) {
  double max = source[0];
  int index = 0;
  for (int i = 0; i < length; i++) {
    if (source[i] > max) {
      max = source[i];
      index = i;
    }
  }
  return index;
}

int main(void) {
  double source[10] = {5.2, 1.0, 0.6, 7.7, 8.8, 1.1, 0.22, 1.99, 0.4, 0.3};
  int max = find_max_index(source, 10);
  printf("source[10] max number index is : %d", max);
  return 0;
}