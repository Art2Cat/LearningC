#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

static double eps;

static int approx(double d1, double d2) {
  return (d2 ? fabs((d2 - d1) / d2) : fabs(d1)) < eps;
}

int main(void) {
  double x;
  int xexp;
  static double piby4 = (0.78539816339744830962);
  static double rthalf = (0.70710678118654752440);
  eps = DBL_EPSILON * 4.0;
  assert(approx(acos(-1.0), 4.0 * piby4));
  return 0;
}
