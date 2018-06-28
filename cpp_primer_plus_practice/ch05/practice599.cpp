/*
 * practice59.cpp
 * Copyright (C) 2018 Rorschach H. <yiming.whz@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <string>

int main(void) {
  using namespace std;
  string word;
  int sum = 0;
  cout << "Enter words(to stop, type the word done): ";
  while ("done" != word) {
    getline(cin, word);
    sum++;
  }
  cout << "You entered a total of " << sum << " words." << endl;
  return 0;
}
