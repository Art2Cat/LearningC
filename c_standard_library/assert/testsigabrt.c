#include <assert.h>
#include <ctype.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int val = 0;

static void test_abort(int sig) {
  if (val == 1) {
    puts("SUCCESS testing");
    exit(EXIT_SUCCESS);
  } else {
    fputs("FAILURE testing", stderr);
    exit(EXIT_FAILURE);
  }
}

char *str_to_lower(int size, char *);

int main(int argc, char **argv) {
  char words[4];
  puts("Continue(y/n)?");
  while (fgets(words, 4, stdin) != NULL && words[0] != '\0') {
    char *tmp = str_to_lower(4, words);
    if (strcmp(tmp, "yes") || strcmp(tmp, "y")) {
      assert(signal(SIGABRT, &test_abort) != SIG_ERR);
      fputs("Error!", stderr);
      exit(EXIT_FAILURE);
    } else {
      puts("Continue(y/n)?");
    }
  }
}

char *str_to_lower(int size, char *str) {
  char *str_r = (char *)malloc((sizeof(char) * size));
  for (int i = 0; i < size; i++) {
    str_r[i] = tolower(str[i]);
  }
  return str_r;
}
