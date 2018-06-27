/*
 * practice595.cpp
 * Copyright (C) 2018 Rorschach H. <yiming.whz@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

int main(void) {
  using namespace std;
  int saleDetails[12];
  string hints[12] = {"Enter January sales: ",   "Enter February sales: ",
                      "Enter March sales: ",     "Enter April sales: ",
                      "Enter May sales: ",       "Enter June sales: ",
                      "Enter July sales: ",      "Enter August sales: ",
                      "Enter September sales: ", "Enter October sales: ",
                      "Enter November sales: ",  "Enter December sales: "};

  for (int i = 0; i < 12; i++) {
    cout << hints[i];
    cin >> saleDetails[i];
  }
  int annualSales = 0;
  for (int i = 0; i < 12; i++) {
    annualSales += saleDetails[i];
  }
  cout << "<<C++ For Fools>> annual sales: " << annualSales << endl;

  return 0;
}
