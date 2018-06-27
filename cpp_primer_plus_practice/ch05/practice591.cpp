/*
 * practice591.cpp
 * Copyright (C) 2018 Rorschach H. <yiming.whz@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

int main(void) {
  using namespace std;
  int start, end, sum = 0;

  cout << "Enter start number: ";
  cin >> start;
  cout << "Enter end number: ";
  cin >> end;
  for (int i = start; i <= end; i++) {
    sum += i;
  }
  cout << "Sum between " << start << " to " << end << " is " << sum << endl;
  return 0;
}
