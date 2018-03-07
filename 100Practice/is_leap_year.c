#include <stdio.h>

int main(int argc, char **argv) {
  int is_leap_year(int year);

  int year = 2018;

  if (is_leap_year(year) == 1) {
    printf("%d is leap year", year);
  } else {
    printf("%d is not leap year", year);
  }
  return 0;
}

int is_leap_year(int year) {
  if (year % 4 == 0 && year % 100 != 0) {
    return 1;
  } else if (year % 400 == 0) {
    return 1;
  } else {
    return -1;
  }
}