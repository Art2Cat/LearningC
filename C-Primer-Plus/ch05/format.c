#include <stdio.h>

int main(int argc, char **argv) {
  int num = 10;
  printf("%d\n", ++num);
  printf("%d\n", num++);
  printf("%d\n", num--);
  printf("%d\n", --num);
  printf("%d\n", num);
}