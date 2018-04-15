#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  time_t t = time(NULL);
  printf("%s\n", asctime(localtime(&t)));

  srand(t);
  printf("%i\n", rand());
}
