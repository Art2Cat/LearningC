#include <stdio.h>

int main(void) {
  char *astring = "I am somewhere in memory.";
  size_t location = (size_t)astring;
  printf("%zu\n", location);
  printf("%s\n", (char *)location);
  return 0;
}
