#include <stdio.h>

int main(int argc, char **argv) {
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j <= i; j++) {
      int result = i * j;
      printf("%d*%d=%-3d", j, i, result);
    }
    printf("\n");
  }
}