#include <math.h>
#include <stdio.h>
/**
 * clang erf.c -o erf -lm -g -Wall -O3 -std=c11
 *
 * the -o flag gives the output name; otherwise, we'd get the default executable
 * name of a.out. the -lc flag asking the linker to link the standard libc. the
 * -lglib-2.0 flag asking the linker to link the library GLib 2.0. the -lgsl
 * flag asking the linker to link the GNU Scientific library. the -lm flag
 * asking the linker to link the math.h library. the -g adds symbols for
 * debugging. the -O3 indicates optimization level three, which tries every
 * trick known to build faster code. the -Wall adds compiler warnings.
 */
int main(void) {
  printf("The integral of a Normal(0,1) distribution "
         "between -1.96 and 1.96 is: %g\n",
         erf(1.96 * sqrt(1 / 2.)));
  return 0;
}
