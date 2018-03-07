#include <stdio.h>
#include <stdlib.h>

#define LEN 12

struct month {
  char name[14];
  char abb[4];
  int days;
  int index;
};

void printMonthDaySummary(const struct month *, int index);

int main(int argc, char **argv) {
  struct month months[LEN] = {
      {"January", "JAN", 31, 1},   {"February", "FEB", 28, 2},
      {"March", "MAR", 31, 3},     {"April", "APR", 30, 4},
      {"May", "MAY", 31, 5},       {"June", "JUN", 30, 6},
      {"July", "JUL", 31, 7},      {"August", "AUG", 31, 8},
      {"September", "SEP", 30, 9}, {"October", "OCT", 31, 10},
      {"November", "NOV", 30, 11}, {"December", "DEC", 31, 12},
  };

  struct month *m;

  int index;

  printf("input month index:\n");
  while (scanf("%d", &index) != 0) {
    if (index < LEN + 1 && index > 0) {
      m = &months[index - 1];
      printf("month: %s, %s, it has %d days\n", m->name, m->abb, m->days);
      printMonthDaySummary(months, index);
    } else {
      puts("out of range!");
      exit(EXIT_FAILURE);
    }
  }
  return 0;
}

void printMonthDaySummary(const struct month *months, int index) {
  int sum = 0;
  for (int i = 0; i < index; i++) {
    sum = sum + months[i].days;
  }

  const struct month *m = months + (index - 1);
  printf("From January to %s totally has %d days.\n", m->name, sum);
}