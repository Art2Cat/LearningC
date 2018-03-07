#include <stdio.h>

int factorial(int n) {
  int result = 1;
  while (n > 0) {
    result = result * n;
    n--;
  }
  return result;
}

long int multiplyNumbers(int n) {
  if (n >= 1)
    return n * multiplyNumbers(n - 1);
  else
    return 1;
}

int main(void) {
  printf("%d! = %llu\n", 10, factorial(10));
  printf("%d! = %llu\n", 10, multiplyNumbers(10));
}
