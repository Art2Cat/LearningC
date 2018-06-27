/*
 * practice592.cpp
 * Copyright (C) 2018 Rorschach H. <yiming.whz@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <array>
#include <iostream>

const int AR_SIZE = 16;

int main(void) {
  using namespace std;
  array<long double, AR_SIZE> factorials;
  factorials[1] = factorials[0] = 1L;
  for (int i = 2; i < AR_SIZE; i++) {
    factorials[i] = i * factorials[i - 1];
  }
  for (int i = 0; i < AR_SIZE; i++) {
    cout << i << "! = " << factorials[i] << endl;
  }
  return 0;
}
