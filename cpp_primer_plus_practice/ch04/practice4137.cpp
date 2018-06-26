/*
 * practice4137.cpp
 * Copyright (C) 2018 Rorschach H. <yiming.whz@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

struct company {
  std::string name;
  double diameter;
  double weight;
};

int main(void) {
  using namespace std;
  company *compy = new company;
  cout << "Enter company name: ";
  getline(cin, compy->name);
  cout << "Enter pizza's diameter: ";
  cin >> compy->diameter;
  cout << "Enter pizza's weight: ";
  cin >> compy->weight;
  cout << "Company Name: " << compy->name << endl;
  cout << "Pizza's diameter: " << compy->diameter << endl;
  cout << "Pizza's weight: " << compy->weight << endl;
  delete compy;
  return 0;
}
