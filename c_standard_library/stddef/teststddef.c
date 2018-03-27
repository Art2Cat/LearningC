#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>

typedef struct {
  char f1;
  struct {
    float flt;
  } f2;
  int f3;
} str_t;

static char *pc = NULL;
static double *pd = NULL;
static size_t offs[] = {offsetof(str_t, f1), offsetof(str_t, f2),
                        offsetof(str_t, f3)};

int main(void) {
  ptrdiff_t pd = &pc[INT_MAX] - &pc[0];
  wchar_t wc = L'Z';
  str_t x = {1, 2, 3};
  char *ps = (char *)&x;

  assert(sizeof(ptrdiff_t) == sizeof(size_t));
  assert(sizeof(size_t) == sizeof(sizeof(char)));
  assert(pd == &pc[INT_MAX] - &pc[0]);
  assert(wc == L'Z');
  assert(offs[0] < offs[1]);
  assert(offs[1] < offs[2]);
  assert(*(char *)(ps + offs[0]) == 1);
  assert(*(float *)(ps + offs[1]) == 2);
  assert(*(int *)(ps + offs[2]) == 3);
  printf("sizeof(size_t) = %lu\n", sizeof(size_t));
  printf("sizeof(wchar_t) = %lu\n", sizeof(wchar_t));
  puts("SUCCESS testing <stddef.h>");
  return 0;
}
