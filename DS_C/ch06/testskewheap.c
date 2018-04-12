#include "skewheap.h"
#include <stdio.h>

#define MAX_SIZE 5000

int main(void) {
  PriorityQueue p;
  int j;

  p = init();
  for (int i = 0, j = MAX_SIZE / 2; i < MAX_SIZE;
       i++, j = (j + 17) % MAX_SIZE) {
    insert(j, p);
  }

  j = 0;
  while (!is_empty(p)) {
    if (find_min(p) != j++) {
      printf("Error in delete min, %d\n", j);
    } else {
      p = delete_min(p);
    }
  }

  puts("Done...\n");
  return 0;
}
