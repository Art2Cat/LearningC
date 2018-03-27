#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct {
  char c;
} c_t;

static int tryit(const char *fmt, ...) {
  int ctr = 0;
  va_list ap;
  va_start(ap, fmt);
  for (; *fmt; ++fmt) {
    switch (*fmt) {
    case 'i':
      assert(va_arg(ap, int) == ++ctr);
      break;
    case 'd':
      assert(va_arg(ap, double) == ++ctr);
      break;
    case 'p':
      assert(va_arg(ap, char *)[0] == ++ctr);
      break;
    case 's':
      assert(va_arg(ap, c_t).c == ++ctr);
      break;
    }
  }
  va_end(ap);
  return ctr;
}

int main(void) {
  c_t x = {3};

  assert(tryit("iisdi", '\1', 2, x, 4.0, 5) == 5);
  assert(tryit("") == 0);
  assert(tryit("pdp", "\1", 2.0, "\3") == 3);
  printf("sizeof(va_list)= %lu\n", sizeof(va_list));
  puts("SUCCESS testing <stdarg.h>");
  return 0;
}
