/*
 * practice595.cpp
 * Copyright (C) 2018 Rorschach H. <yiming.whz@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

int main(void) {
  using namespace std;
  int saleDetails[3][12];

  string months[12] = {"January",   "February", "March",    "April",
                       "May",       "June",     "July",     "August",
                       "September", "October",  "November", "December"};

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 12; j++) {
      cout << "Enter the " << i + 1 << " year " << months[j] << " sales: ";
      cin >> saleDetails[i][j];
    }
  }
  int annualSales = 0;
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 12; i++) {
      annualSales += saleDetails[j][i];
    }
  }
  cout << "<<C++ For Fools>> three years sales volume: " << annualSales << endl;

  return 0;
}
