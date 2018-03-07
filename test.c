#include <stdio.h>
#include <string.h>

void print(char *text, char *text2) { printf("%d\n", strcmp(text, text2)); }

int main(void) {
  char name[6] = "peter";
  printf("fuck you %s\n", name);
  int len = strlen(name);
  printf("%*s\n", 30, name);
  printf("strlen(name) :  %d\n", len);

  char *test;
  test = "test";
  // test = name;
  printf("%d\n", strcmp(test, "test"));

  printf("%s\n", test);
  print(test, "test");

  char *t1 = "01001001";

  if (t1 == NULL) {
    puts("null");
  }
  int val = 0;
  while (*t1 != '\0') {
    printf("--%c\n", *t1++);
    val = 2 * val + (*t1++ - '0');
    printf("++ %d\n", val);
  }
  printf("%d\n", val);
  return 0;
}
