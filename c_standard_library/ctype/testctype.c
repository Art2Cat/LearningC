#include <ctype.h>
#include <stdio.h>

#define SOURCE "Hello,world!\n"

void detect_ctype(char c);

int main(int argc, char **argv) {
  int size = sizeof(SOURCE) / sizeof(SOURCE[0]);
  printf("size: %d\n", size);
  for (int i = 0; i < size; i++) {
    detect_ctype(SOURCE[i]);
  }
  return 0;
}

void detect_ctype(char c) {
  printf("%c satisfy ", c);
  if (isalnum(c) != 0) {
    printf("isalnum ");
  }
  if (isalpha(c) != 0) {
    printf("isalpha ");
  }
  if (iscntrl(c) != 0) {
    printf("iscntrl ");
  }
  if (isdigit(c) != 0) {
    printf("isdigit ");
  }
  if (isgraph(c) != 0) {
    printf("isgraph ");
  }
  if (islower(c) != 0) {
    printf("islower ");
  }
  if (isprint(c) != 0) {
    printf("isprint ");
  }
  if (ispunct(c) != 0) {
    printf("ispunct ");
  }
  if (isspace(c) != 0) {
    printf("isspace ");
  }
  if (isupper(c) != 0) {
    printf("isupper ");
  }
  puts("\n");
}
