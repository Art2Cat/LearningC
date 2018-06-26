/*
 * practice41310.cpp
 * Copyright (C) 2018 Rorschach H. <yiming.whz@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <array>
#include <iostream>

int main(void) {
  using namespace std;
  array<double, 3> results;
  double total = 0;
  for (int i = 0; i < 3; i++) {
    cout << "Enter your 40-meter sprint time: ";
    cin >> results[i];
    total += results[i];
  }
  int time = results.size();
  cout << time << " times 40-meter sprint average time is " << total / time
       << endl;
  return 0;
}
