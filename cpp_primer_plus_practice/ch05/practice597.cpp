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
    car *c = new car;
    cout << "Please enter the make: ";
    cin >> c->maker;
    cout << "Please enter the year made: ";
    cin >> c->made_of_year;
    cars[i] = *c;
  }
  cout << "Here is your collection:" << endl;
  for (int j = 0; j < size; j++) {
    cout << cars[j].made_of_year << " " << cars[j].maker << endl;
  }
  delete[] cars;
  return 0;
}
