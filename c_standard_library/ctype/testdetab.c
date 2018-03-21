#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST_STR "this is \t test string"

size_t detab(char **dest, const char *src);

int main(int argc, char **argv) {
  char *str = NULL;
  str = (char *)calloc(30, sizeof(char));
  printf("origin string length: %zu\n", strlen(TEST_STR));
  printf("origin: %s\n", TEST_STR);
  printf("new string length: %zu \n", detab(&str, TEST_STR));
  printf("new string: %s\n", str);

  if (str != NULL) {
    fputs("free str!\n", stdout);
    free(str);
  }
  return 0;
}

size_t detab(char **dest, const char *src) {

  size_t len;
  int tmp = 0;
  strcpy(*dest, src);

  for (int i = 0; src[i] != '\0'; i++) {
    if (src[i] == '\t') {
      (*dest)[i] = ' ';
      (*dest)[i + 1] = ' ';
      (*dest)[i + 2] = ' ';
      (*dest)[i + 3] = ' ';

      tmp = 1;
    } else {
      if (tmp == 1) {
        (*dest)[i + 3] = src[i];
      } else {
        (*dest)[i] = src[i];
      }
    }
  }
  len = strlen(*dest);
  return len;
}
