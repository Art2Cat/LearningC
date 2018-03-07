#include <stdbool.h>
#include <stdio.h>

bool is_even(int x) {
  if (x % 2 == 0) {
    return true;
  } else {
    return false;
  }
}

int main(int argc, char **argv) {
  // bool is_even(int x);
  if (is_even(8)) {
    printf("%d is even.\n", 8);
  }
}