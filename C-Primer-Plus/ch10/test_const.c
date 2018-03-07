#include <stdio.h>

int main(void) {
  double rates[5] = {88.99, 100.12, 64.89, 183.11, 3410.4};
  const double locked[4] = {0.08, 0.075, 0.0725, 0.117};
  const double *pc = rates;
  double *pnc = rates;
  printf("pc = %p\n", pc);
  printf("pnc = %p\n", pnc);
  pc = locked;
  printf("pc = %p\n", pc);
  pc = &rates[3];
  printf("pc = %p\n", pc);
  printf("rates[3] = %p\n", &rates[3]);
  pnc = locked;
  printf("pnc = %p\n", pnc);
  pnc = &rates[3];
  printf("pnc = %p\n", pnc);
  printf("rates[3] = %p\n", &rates[3]);
  printf("locked = %p\n", locked);
  return 0;
}