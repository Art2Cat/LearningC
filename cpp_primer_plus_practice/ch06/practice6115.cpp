/*
 * practice6115.cpp
 * Copyright (C) 2018 Rorschach H. <yiming.whz@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

int main(void) {
  using namespace std;
  unsigned long income;
  while (true) {

    cout << "Please enter your income: ";
    cin >> income;
    if (cin.fail()) {
      break;
    }
    double incomeTax;
    if (income <= 5000) {
      incomeTax = 0;
    } else if (5000 < income && income <= 15000) {
      incomeTax = (income - 5000) * 0.1;
    } else if (15000 < income && income <= 35000) {
      incomeTax = 10000 * 0.1 + (income - 15000) * 0.15;
    } else if (35000 < income) {
      incomeTax = 10000 * 0.1 + 20000 * 0.15 + (income - 35000) * 0.2;
    } else {
      incomeTax = -1;
    }

    if (incomeTax == -1) {
      break;
    }
    cout << "Your income tax is " << incomeTax << endl;
  }
  return 0;
}
