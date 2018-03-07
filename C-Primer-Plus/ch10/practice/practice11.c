#include <stdio.h>

#define ROWS 3
#define COLS 5

void showArray(int arr[][COLS], int rows);
void toDouble(int arr[][COLS], int rows);

int main(int argc, char **argv) {
  int stuff[ROWS][COLS] = {
      {1, 2, 3, 4, 5}, {6, 7, 8, -2, 10}, {11, 12, 13, 14, 15}};
  showArray(stuff, ROWS);
  putchar('\n');
  toDouble(stuff, ROWS);
  showArray(stuff, ROWS);
  return 0;
}

void toDouble(int arr[][COLS], int rows) {
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < COLS; col++) {
      arr[row][col] *= 2;
    }
  }
}

void showArray(int arr[][COLS], int rows) {
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < COLS; col++) {
      printf("%d ", arr[row][col]);
    }
    putchar('\n');
  }
}
