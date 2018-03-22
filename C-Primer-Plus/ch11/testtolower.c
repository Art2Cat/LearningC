#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char *str_to_lower(int size, char str[size]) {
  char *str_r = (char *)malloc((sizeof(char) * size));
  for (int i = 0; i < size; i++) {
    str_r[i] = tolower(str[i]);
  }
  return str_r;
}

int main(int argc, char **argv) {
  char str[16] = "TUTORIALS POINT";
  int i = 0;
  char *str_r = NULL;
  int size = (sizeof(str)) / (sizeof(str[0]));
  printf("%d\n", size);
  while (str[i]) {
    putchar(tolower(str[i]));
    i++;
  }
  puts("\n");

  str_r = str_to_lower(size, str);
  printf("%s\n", str_r);
  if (str_r != NULL) {
    free(str_r);
  }
  return 0;
}
