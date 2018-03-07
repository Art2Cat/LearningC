#include <limits.h>
#include <stdio.h>

char *itobs(int, char *);
void show_bstr(const char *);

int main(int argc, char **argv) {
  unsigned int val = 60;
  unsigned int val1 = 13;
  char bin_str[CHAR_BIT * sizeof(int) + 1];
  int val2;

  printf("val is: %d\n", val);
  itobs(val, bin_str);
  show_bstr(bin_str);

  printf("val1 is: %d\n", val1);
  itobs(val1, bin_str);
  show_bstr(bin_str);

  val2 = ~val;
  printf("~val is: %d\n", val2);
  itobs(val2, bin_str);
  show_bstr(bin_str);
  val2 = val & val1;
  printf("val & val1 is: %d\n", val2);
  itobs(val2, bin_str);
  show_bstr(bin_str);
  val2 = val | val1;
  printf("val | val1 is: %d\n", val2);
  itobs(val2, bin_str);
  show_bstr(bin_str);
  val2 = val ^ val1;
  printf("val ^ val1 is: %d\n", val2);
  itobs(val2, bin_str);
  show_bstr(bin_str);

  return 0;
}

char *itobs(int n, char *ps) {
  int i;
  const static int size = CHAR_BIT * sizeof(int);

  for (i = size - 1; i >= 0; i--, n >>= 1) {
    ps[i] = (01 & n) + '0';
  }
  ps[size] = '\0';

  return ps;
}

/* show binary string in blocks of 4 */
void show_bstr(const char *str) {
  int i = 0;
  /* not the null character */
  while (str[i]) {
    putchar(str[i]);
    if (++i % 4 == 0 && str[i]) {
      putchar(' ');
    }
  }
  putchar('\n');
}