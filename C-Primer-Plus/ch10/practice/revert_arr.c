#include <stdio.h>

int find_min(const double* source, int length) {
  double min = source[0];
  int index = 0;
  for (int i = 1; i < length; i++) {
    if (source[i] < min) {
      min = source[i];
      index = i;
    }
  }
  return index;
}

int find_max(const double* source, int length) {
  double max = source[0];
  int index = 0;
  for (int i = 1; i < length; i++) {
    if (source[i] > max) {
      max = source[i];
      index = i;
    }
  }
  return index;
}

void revert(double* source, int length) {
  double buffer[length];
  for (int i = 0; i < length; i++) {
    int x = find_max(source, length);
    buffer[i] = source[x];
    source[x] = 0.0;
  }

  for (int i = length - 1; i > 0; i--) {
    int x = find_min(source, length);
    if (buffer[i] == 0.0) {
      buffer[i] = source[x];
    }
    source[x] = 0.0;
  }

  for (int j = 0; j < length; j++) {
    source[j] = buffer[j];
  }
};

int main(void) {
  double source[10] = {5.2, -1.1, -5.6, 7.2, 1.8, 0.0, 0.2, 9.9, 0.4, 0.3};
  printf("origin source\n");
  for (int i = 0; i < 10; i++) {
    printf("%.1lf  ", source[i]);
  }
  printf("\n");
  revert(source, 10);

  printf("reverted source\n");
  for (int i = 0; i < 10; i++) {
    printf("%.1lf  ", source[i]);
  }
  printf("\n");
  return 0;
}