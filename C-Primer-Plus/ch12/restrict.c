#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int arr[10];
  int *restrict restarr = (int *)malloc(10 * sizeof(int));
  int *par = arr;

  for (int i = 0; i < 5; i++) {
    par[i] += 5;
    restarr[i] += 5;
    arr[i] = 2;
    par[i] += 3;
    restarr[i] += 3;
  }

  printf("arr[0] = %d\n", arr[0]);
  printf("restarr[0] = %d\n", restarr[0]);
  printf("par[0] = %d\n", par[0]);
  return 0;
}