/*
 * practice6111.cpp
 * Copyright (C) 2018 Rorschach H. <yiming.whz@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <cctype>
#include <iostream>

int main(void) {
  using namespace std;
  char c;
  cout << "Enter text(type '@' to exit): \n";
  cin.get(c);
  while (c != '@') {
    cin.get(c);
    if (isdigit(c)) {
      continue;
    } else if (isalpha(c)) {
      if (isupper(c)) {
        c = tolower(c);
      } else if (islower(c)) {
        c = toupper(c);
      }
    }
    putchar(c);
  }
  return 0;
}
