#include <stdio.h>

unsigned int gcd(unsigned int m, unsigned int n);

long int pow1(long int x, unsigned int n);

int main(int argc, char **argv) {
  printf("%u\n", gcd(1989, 1590));
  printf("%ld\n", pow1(2, 10));
  return 0;
}

unsigned int gcd(unsigned int m, unsigned int n) {
  unsigned int rem;
  while (n > 0) {
    rem = m % n;
    m = n;
    n = rem;
  }
  return m;
}

_Bool isEven(unsigned int n) { return n % 2 == 0; }

long int pow1(long int x, unsigned int n) {
  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return x;
  }
  if (isEven(n)) {
    return pow1(x * x, n / 2);
  } else {
    return pow1(x * x, n / 2) * x;
  }
}