#include <limits.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  // test basic properties of limits.h macros
  printf("CHAR_BIT = %2i MB_LEN_MAX = %2i\n", CHAR_BIT, MB_LEN_MAX);
  printf("CHAR_MAX = %10i CHAR_MIN = %10i\n", CHAR_MAX, CHAR_MIN);
  printf("SCHAR_MAX = %10i SCHAR_MIN = %10i\n", SCHAR_MAX, SCHAR_MIN);
  printf("UCHAR_MAX = %10u\n", UCHAR_MAX);

  printf("SHRT_MAX = %10i SHRT_MIN = %10i\n", SHRT_MAX, SHRT_MIN);
  printf("USHRT_MAX = %10i\n", USHRT_MAX);
  printf("INT_MAX = %10i INT_MIN = %10i\n", INT_MAX, INT_MIN);
  printf("UINT_MAX = %10u\n", UINT_MAX);
  printf("LONG_MAX = %10li LONG_MIN = %10li\n", LONG_MAX, LONG_MIN);
  printf("ULONG_MAX = %10li\n", ULONG_MAX);

#if CHAR_BIT < 8 || CHAR_MAX < 127 || 0 < CHAR_MIN ||                          \
    CHAR_MAX != SCHAR_MAX && CHAR_MAX != UCHAR_MAX
#error bad char properties
#endif

  return 0;
}
