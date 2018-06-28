/*
 * practice597.cpp
 * Copyright (C) 2018 Rorschach H. <yiming.whz@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

struct car {
  std::string maker;
  int made_of_year;
};

int main(void) {
  using namespace std;
  int size;
  cout << "How many cars do you wish to catalog? ";
  cin >> size;
  car *cars = new car[size];
  for (int i = 0; i < size; i++) {
    cout << "Car #" << i + 1 << endl;
    cout << "Please enter the make: ";
    cin >> cars[i].maker;
    cout << "Please enter the year made: ";
    cin >> cars[i].made_of_year;
  }
  cout << "Here is your collection:" << endl;
  for (int j = 0; j < size; j++) {
    cout << cars[j].made_of_year << " " << cars[j].maker << endl;
  }
  delete[] cars;
  return 0;
}
