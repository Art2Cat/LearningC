#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *repstext = getenv("reps");
  int reps = repstext ? atoi(repstext) : 10;

  char *msg = getenv("msg");
  if (!msg) {
    msg = "Hello.";
  }

  for (int i = 0; i < reps; i++) {
    printf("%s\n", msg);
  }
  return 0;
}
