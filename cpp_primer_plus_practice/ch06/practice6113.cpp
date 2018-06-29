/*
 * practice6113.cpp
 * Copyright (C) 2018 Rorschach H. <yiming.whz@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

int main(void) {
  using namespace std;
  cout << "Please enter on of the following choice:" << endl;
  cout << "c) carnivore        ";
  cout << "p) pianist" << endl;
  cout << "t) tree             ";
  cout << "g) game" << endl;
  char choice;
  while (cin >> choice) {
    if (choice == 'c' || choice == 'p' || choice == 't' || choice == 'g') {
      break;
    }
    cout << "Please enter a c, p, t, or g: ";
  }

  switch (choice) {
  case 'c':
    cout << "Tiger is a carnivore." << endl;
    break;
  case 'p':
    cout << "Mozart is a pianist." << endl;
    break;
  case 't':
    cout << "A mapple is a tree." << endl;
    break;
  case 'g':
    cout << "Let's play game." << endl;
    break;
  }
  return 0;
}
