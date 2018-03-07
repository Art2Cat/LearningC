#include <stdio.h>

void copy_arr(double target[], double source[], int length);
void copy_ptr(double* target, double* source, int length);
// copy_ptrs(x, y, z);
int main(int argc, char* argv) {
  double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
  double target1[5];
  double target2[5];
  double target3[5];
  copy_arr(target1, source, 5);
  copy_ptr(target2, source, 5);
  copy_ptr(target3, source, 5);
  //  copy_ptrs(target3, source, source + 5);

  for (int i = 0; i < 5; i++) {
    printf(
        "source[%d]=%.1lf, target1[%d]=%.1lf, target2[%d]=%.1lf, "
        "target3[%d]=%.1lf\n",
        i, source[i], i, target1[i], i, target2[i], i, target3[i]);
  }
  return 0;
}

void copy_arr(double target[], double source[], int length) {
  for (int i = 0; i < length; i++) {
    target[i] = source[i];
  }
}

void copy_ptr(double* target, double* source, int length) {
  for (int i = 0; i < length; i++) {
    *(target + i) = *source++;
  }
}

void copy_ptrs(double* target, double* source, double* index) {}