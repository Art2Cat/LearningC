#include <stdio.h>

void copy_arr(double target[], double source[], int start, int end) {
  int i = 0;
  for (; start < end + 1; start++) {
    target[i++] = source[start];
  }
}

int main(void) {
  double source[7] = {1, 2, 3, 4, 5, 6, 7};
  double target[3];

  copy_arr(target, source, 3, 5);
  for (int i = 0; i < 3; i++) printf("%.1lf  ", target[i]);

  return 0;
}