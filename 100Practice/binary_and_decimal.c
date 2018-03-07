#include <math.h>
#include <stdio.h>

int binaryToDecimal(long long n);
long long decimalToBinary(int n);

int main(int argc, char** argv) {
  int n = 100;
  long long b = decimalToBinary(n);
  printf("Decimal: %d; Binary: %lld\n", n, b);
  n = binaryToDecimal(b);
  printf("Binary: %lld; Decimal: %d\n", b, n);
  return 0;
}

int binaryToDecimal(long long n) {
  int decimalNumber = 0, i = 0, remainder;
  while (n != 0) {
    remainder = n % 10;
    n /= 10;
    decimalNumber += remainder * pow(2, i);
    ++i;
  }
  return decimalNumber;
}

long long decimalToBinary(int n) {
  long long binaryNumber = 0;
  int remainder, i = 1, step = 1;

  while (n != 0) {
    remainder = n % 2;
    n /= 2;
    binaryNumber += remainder * i;
    i *= 10;
  }
  return binaryNumber;
}