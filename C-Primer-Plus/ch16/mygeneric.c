#include <stdio.h>

#define LEN 30

struct string {
  char String[LEN];
}
#define ITEM(T)                     \
  _Generic((T), struct string       \
           : struct string, default \
           : int, float             \
           : float, double          \
           : double, long           \
           : long)(T)

int main(int argc, char **argv) {
  float x = 45.0f;
  long double y = ITEM(x);

  printf("%.17Lf\n", y);
  return 0;
}