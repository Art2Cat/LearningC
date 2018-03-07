#include <stdio.h>

#define MONTHS 12
#define YEARS 5

void show_sum(float* total, float* subtot, const float rain[YEARS][MONTHS]);
void show_average(float* subtot, const float rain[YEARS][MONTHS]);

int main(void) {
  const float rain[YEARS][MONTHS] = {
      {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
      {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
      {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
      {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
      {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2},
  };

  float subtot, total;

  show_sum(&total, &subtot, rain);

  printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
  printf("MONTHLY AVERAGES:\n\n");
  printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct ");
  printf(" Nov  Dec\n");
  show_average(&subtot, rain);
  printf("\n");
  return 0;
}

void show_sum(float* total, float* subtot, const float rain[YEARS][MONTHS]) {
  printf(" YEAR    RAINFALL  (inches)\n");
  *total = 0;
  for (int year = 0; year < YEARS; year++) {
    for (int month = 0; month < MONTHS; month++) {
      float x = rain[year][month];
      *subtot += x;
    }
    printf("%5d %15.1f\n", 2010 + year, *subtot);
    *total += *subtot;
    *subtot = 0;
  }
}

void show_average(float* subtot, const float rain[YEARS][MONTHS]) {
  *subtot = 0;
  for (int month = 0; month < MONTHS; month++) {
    for (int year = 0; year < YEARS; year++) {
      *subtot += rain[year][month];
    }
    printf("%4.1f ", *subtot / YEARS);
    *subtot = 0;
  }
}