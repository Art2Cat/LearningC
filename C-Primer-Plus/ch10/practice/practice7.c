#include <stdio.h>

void copy_arr(double target[3][5], double source[3][5], int row, int column) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      *(*(target + i) + j) = *(*(source + i) + j);
    }
  }
}

void copy_ptr(double *(*target), double **source, int row, int column) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      *(*(target + i) + j) = *(*(source + i) + j);
    }
  }
}

int main(void) {
  double source[3][5] = {{1.1, 2.2, 3.3, 4.4, 5.5},
                         {1.1, 2.2, 3.3, 4.4, 5.5},
                         {1.1, 2.2, 3.3, 4.4, 5.5}};

  double target[3][5];
  copy_arr(target, source, 3, 5);

  copy_ptr((double **)target, (double **)source, 3, 5);
  for (int i = 0; i < 3; i++) {
    printf("source[%d]=%.1lf, target1[%d]=%.1lf\n", i, source[i][i], i,
           target[i][i]);
  }

  return 0;
}