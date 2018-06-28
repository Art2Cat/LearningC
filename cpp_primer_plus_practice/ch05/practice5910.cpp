/*
 * practice5910.cpp
 * Copyright (C) 2018 Rorschach H. <yiming.whz@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

int main(void) {
  int row = 0;
  std::cout << "Enter number of rows: ";
  std::cin >> row;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < row - i - 1; j++) {
      std::cout << ".";
    }
    for (int k = 0; k < i + 1; k++) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
  return 0;
}
