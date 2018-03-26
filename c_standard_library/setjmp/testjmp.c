#include <assert.h>
#include <setjmp.h>
#include <stdio.h>

static int ctr;
static jmp_buf b0;
static char ch;

static void jmpto(int n) { longjmp(b0, n); }

static char *stackptr() { return (&ch); }

static int tryit() {
  jmp_buf b1;
  char *sp = stackptr();
  ctr = 0;
  switch (setjmp(b0)) {
  case 0:
    assert(sp == stackptr());
    assert(ctr == 0);
    ++ctr;
    jmpto(0);
    break;
  case 1:
    assert(sp == stackptr());
    assert(ctr == 1);
    ++ctr;
    jmpto(2);
    break;
  case 2:
    assert(sp == stackptr());
    assert(ctr == 2);
    ++ctr;
    switch (setjmp(b1)) {
    case 0:
      assert(sp == stackptr());
      assert(ctr == 3);
      ++ctr;
      longjmp(b1, -7);
      break;
    case -7:
      assert(sp == stackptr());
      assert(ctr == 4);
      ++ctr;
      jmpto(3);
    case 5:
      return 13;
    default:
      return 0;
    }
  case 3:
    longjmp(b1, 5);
    break;
  }
  return -1;
}

int main(void) {
  assert(tryit() == 13);
  printf("sizeof(jmp_buf) = %lu\n", sizeof(jmp_buf));
  puts("SUCCESS testing <setjmp.h>");
  return 0;
}
