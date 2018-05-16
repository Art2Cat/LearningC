#include <assert.h>

typedef struct {
  int a, b;
  double c, d;
  int *efg;
} test_t;

int main(void) {
  test_t t1 = {.b = 1, .c = 2, .d = 3, .efg = (int[]){4, 6, 5}};
  test_t t2 = t1;

  t1.b = 14;
  t1.c = 41;
  t1.efg[0] = 7;

  assert(t2.a == 0);
  assert(t2.b == 1);
  assert(t2.c == 2);
  assert(t2.d == 3);
  assert(t2.efg[0] == 7);
  return 0;
}
