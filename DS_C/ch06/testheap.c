#include "binheap.h"
#include <stdio.h>

#define MAX_SIZE 1000

int main(void) {
  PriorityQueue H;
  int i, j;

  H = init(MAX_SIZE);
  for (i = 0, j = MAX_SIZE / 2; i < MAX_SIZE; i++, j = (j + 71) % MAX_SIZE) {
    insert(j, H);
  }

  j = 0;
  while (!is_empty(H)) {
    if (delete_min(H) != j++) {
      printf("Error in DeleteMin, %d\n", j);
    }
  }
  printf("Done...\n");
  return 0;
}
