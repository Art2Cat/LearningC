#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 12

struct month {
  char name[14];
  char abb[4];
  int days;
  int index;
};

void printMonthDaySummary(const struct month*, const char*, int len);

int main(int argc, char** argv) {
  struct month months[LEN] = {
      {"January", "JAN", 31, 1},   {"February", "FEB", 28, 2},
      {"March", "MAR", 31, 3},     {"April", "APR", 30, 4},
      {"May", "MAY", 31, 5},       {"June", "JUN", 30, 6},
      {"July", "JUL", 31, 7},      {"August", "AUG", 31, 8},
      {"September", "SEP", 30, 9}, {"October", "OCT", 31, 10},
      {"November", "NOV", 30, 11}, {"December", "DEC", 31, 12},
  };

  struct month* m;

  char input[4];

  printf("input month index:\n");
  while (scanf("%s", input) == 1 && input[0] != 'q') {
    if (input[0] != '\n') printMonthDaySummary(months, input, LEN);

    printf("Next month (q to quit): ");
  }
  return 0;
}

void printMonthDaySummary(const struct month* months, const char* abbs,
                          int len) {
  int sum = 0;
  struct month m;
  for (int i = 0; i < len; i++) {
    if (strncmp(abbs, months[i].abb, 3) == 0) {
      m = months[i];
      break;
    }
  }

  if (m.abb == NULL) {
    printf("Out of Range!");
  }
  for (int j = 0; j < m.index; j++) {
    sum = sum + months[j].days;
  }

  printf("From January to %s totally has %d days.\n", m.name, sum);
}
