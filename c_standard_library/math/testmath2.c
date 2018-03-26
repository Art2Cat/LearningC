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
  assert(approx(acos(rthalf), 3.0 * piby4));
  assert(approx(acos(0.0), 2.0 * piby4));
  assert(approx(acos(rthalf), piby4));
  assert(approx(acos(1.0), 0.0));
  assert(approx(asin(-1.0), -2.0 * piby4));
  assert(approx(asin(-rthalf), -piby4));
  assert(approx(asin(0.0), 0.0));
  assert(approx(asin(rthalf), piby4));
  assert(approx(asin(1.0), 2.0 * piby4));
  assert(approx(atan(-DBL_MAX), -2.0 * piby4));
  assert(approx(atan(-1.0), -piby4));
  assert(approx(atan(0.0), 0.0));
  assert(approx(atan(1.0), piby4));
  assert(approx(atan(DBL_MAX), 2.0 * piby4));
  puts("SUCCESS testing <math.h>, part 2");
  return 0;
}
