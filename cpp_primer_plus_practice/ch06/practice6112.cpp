/*
 * practice6112.cpp
 * Copyright (C) 2018 Rorschach H. <yiming.whz@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
const int SIZE = 10;

int main(void) {
  using namespace std;
  double donations[SIZE];
  double donation;
  double sum = 0;
  int index = 0;
  cout << "Enter donation(type non-digit to exit): \n";
  while (index < SIZE) {
    cin >> donation;
    if (cin.fail()) {
      cin.clear();
      break;
    }
    donations[index] = donation;
    sum += donation;
    index++;
  }
  double average = sum / index;
  int num = 0;
  for (int i = 0; i < index; i++) {
    if (donations[i] > average) {
      num++;
    }
  }
  cout << "The average donation is " << average << " and " << num
       << " donator(s) beyond average.";
  return 0;
}
