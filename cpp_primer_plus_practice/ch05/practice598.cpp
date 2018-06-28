/*
 * practice598.cpp
 * Copyright (C) 2018 Rorschach H. <yiming.whz@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <cstring>
#include <iostream>

const int STR_LEN = 20;

int main(void) {
  using namespace std;
  char str[STR_LEN];
  int sum = 0;
  cout << "Enter words(to stop, type the word done): ";
  do {
    cin.getline(str, STR_LEN);
    sum++;
  } while (strcmp(str, "done") != 0);
  cout << "You entered a total of " << sum << " words." << endl;
  return 0;
}
