#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *p1 = (int *)malloc(100 * sizeof(int));
  int *p2 = (int *)calloc(100, sizeof(int));

  printf("p1 = %lu\n", sizeof(p1));
  printf("p2 = %lu\n", sizeof(p2));

  return 0;
}