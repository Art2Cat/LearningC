#include <stdio.h>

double max_diff(const double* source, int length) {
  double max = source[0];
  double min = source[0];
  for (int i = 0; i < length; i++) {
    if (source[i] > max) {
      max = source[i];
    } else if (source[i] < min) {
      min = source[i];
    }
  }
  printf("max = %.1lf\n", max);
  printf("min = %.1lf\n", min);
  return max - min;
}

int main(void) {
  double source[10] = {5.2, -1.1, 5.6, 7.2, 1.8, 1, 0.2, 9.9, 0.4, 0.3};
  double max = max_diff(source, 10);
  printf("source[10] max number index is : %.1lf", max);
  return 0;
}