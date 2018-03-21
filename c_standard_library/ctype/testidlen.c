#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define TEST_STR_A "s_method"
#define TEST_STR_B "method"

size_t idlen(const char *s);

void verify(const char *s, size_t (*idlen)(const char *s)) {
  size_t result = (*idlen)(s);
  if (result == 0) {
    fputs("ERROR string not start as 's'\n", stderr);
  } else {
    printf("%s length is %zu\n", s, result);
  }
}

int main(int argc, char **argv) {

  verify(TEST_STR_A, idlen);
  verify(TEST_STR_B, idlen);

  return 0;
}

size_t idlen(const char *s) {
  size_t result;
  if (s != NULL) {
    if (islower(s[0]) && 's' == s[0]) {
      result = strlen(s);
    }
  }
  return result;
}
