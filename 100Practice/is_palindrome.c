#include <stdio.h>

_Bool isPalindrome(long number);
long revert(long number);

int main(void) {
  long origin = -1234321;

  printf("%ld\n", origin);

  if (isPalindrome(origin))
    printf("%ld is palindrome number.", origin);
  else
    printf("%ld is not palindrome number.", origin);

  return 0;
}

/**
 * check palindrome number
 **/
_Bool isPalindrome(long number) { return number == revert(number); }

/**
 * revert number e.g 1234 -> 4321
 **/
long revert(long number) {
  long remainder, reverted = 0;
  while (number != 0) {
    remainder = number % 10;
    reverted = reverted * 10 + remainder;
    number /= 10;
  }
  return reverted;
}