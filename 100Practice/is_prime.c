#include <stdbool.h>
#include <stdio.h>

bool is_prime(int n) {
  int i;
  for (i = 2; i < n; i++)
    if (n % i == 0) break;
  if (i == n)
    return true;
  else
    return false;
}

int main(void) {
  int i;
  for (i = 1; i <= 100; i++) {
    if (!is_prime(i)) continue;
    printf("%d\n", i);
  }
  return 0;
}