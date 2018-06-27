/*
 * practice594.cpp
 * Copyright (C) 2018 Rorschach H. <yiming.whz@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

const double INTEREST_RATE = 0.10;
const double COMPOUND_INTEREST_RATE = 0.05;

int main(void) {
  using namespace std;
  double daphneIV, cleoIV;
  double daphnePricipal = 100, cleoPricipal = 100;
  int year = 0;
  daphneIV = daphnePricipal;
  cleoIV = cleoPricipal;
  do {
    cleoIV *= (1 + COMPOUND_INTEREST_RATE);
    year++;
  } while (daphneIV > cleoIV);

  cout << "year: " << year << endl;
  cout << "daphne's investment value: " << daphneIV << endl;
  cout << "cleo's investment value: " << cleoIV << endl;
  return 0;
}
