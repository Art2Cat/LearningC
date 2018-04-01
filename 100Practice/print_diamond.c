#include <math.h>
#include <stdio.h>

int main(int argc, char **argv) {
  void diamond(int times, char symbol);

  diamond(10, '*');

  return 0;
}

void diamond(int times, char symbol) {
  int n, c, k, space = 1;
  n = times;
  space = n - 1;
  for (k = 1; k <= n; k++) {
    for (c = 1; c <= space; c++) {
      printf(" ");
    }

    space--;

    for (c = 1; c <= 2 * k - 1; c++) {
      printf("%c", symbol);
    }

    printf("\n");
  }

  space = 1;

  for (k = 1; k <= n - 1; k++) {
    for (c = 1; c <= space; c++) {
      printf(" ");
    }

    space++;

    for (c = 1; c <= 2 * (n - k) - 1; c++) {
      printf("%c", symbol);
    }

    printf("\n");
  }
}
