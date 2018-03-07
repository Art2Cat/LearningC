#include <stdio.h>
#include <string.h>

typedef struct lens {
  float foclen;
  float fstop;
  char brand[10];
} LENS;

void printLens(int length, LENS lenses[]);

int main(int argc, char **argv) {
  LENS lenses[10];

  for (int i = 0; i < 10; i++) {
    if (i == 2) {
      lenses[i].foclen = 500;
      lenses[i].fstop = 2.0;
      strcpy(lenses[i].brand, "Remarkata");
    } else {
      lenses[i].foclen = 200;
      lenses[i].fstop = 3.0;
      strcpy(lenses[i].brand, "test");
    }
  }

  printLens(10, lenses);
  puts("Done!");
  return 0;
}

void printLens(int length, LENS lenses[]) {
  for (int i = 0; i < length; i++) {
    printf("%.2f; %.2f; %s\n", lenses[i].foclen, lenses[i].fstop,
           lenses[i].brand);
  }
}