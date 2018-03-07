#include <stdio.h>
#define ROWS 3
#define COLUMNS 5

void copy_arr(int rows, int columns, double target[rows][columns],
              double source[rows][columns]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      target[i][j] = source[i][j];
    }
  }
}

int main(int argc, char **argv) {
  double source[ROWS][COLUMNS] = {{1.1, 2.2, 3.3, 4.4, 5.5},
                                  {1.1, 2.2, 3.3, 4.4, 5.5},
                                  {1.1, 2.2, 3.3, 4.4, 5.5}};

  double target[ROWS][COLUMNS];
  copy_arr(ROWS, COLUMNS, target, source);

  for (int i = 0; i < 3; i++) {
    printf("source[%d]=%.1lf, target1[%d]=%.1lf\n", i, source[i][i], i,
           target[i][i]);
  }
  return 0;
}