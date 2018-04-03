#include <stdio.h>

int main(int argc, char **argv) {
  int code;
  printf("Please enter ASCII code:\n");
  scanf("%d", &code);
  char ch = code;
  printf("Character is %c\n", ch);
  return 0;
}
