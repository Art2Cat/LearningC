/*
 * practice593.cpp
 * Copyright (C) 2018 Rorschach H. <yiming.whz@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

int main(void) {
  using namespace std;
  double input, total = 0;
  cout << "Enter a number: ";
  cin >> input;
  while (input) {
    total += input;
    cout << "Enter a number: ";
    cin >> input;
  }
  cout << "The sum of input numbers is " << total << endl;
  return 0;
}
