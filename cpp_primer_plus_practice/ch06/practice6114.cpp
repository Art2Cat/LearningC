/*
 * practice6114.cpp
 * Copyright (C) 2018 Rorschach H. <yiming.whz@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <cstring>
#include <iostream>

const int STR_SIZE = 20;

enum preference_e { FULL_NAME, TITLE, BOP_NAME };

struct bop {
  char fullname[STR_SIZE];
  char title[STR_SIZE];
  char bopname[STR_SIZE];
  preference_e preference;
};

int main(void) {
  using namespace std;
  bop *bops = new bop[5];
  for (int i = 0; i < 5; i++) {
    strcpy(bops[i].fullname, ("test fullname v" + to_string(i)).c_str());
    strcpy(bops[i].title, ("test title v" + to_string(i)).c_str());
    strcpy(bops[i].bopname, ("bopname v" + to_string(i)).c_str());
    if (i < 2) {
      bops[i].preference = FULL_NAME;
    } else if (i > 2) {
      bops[i].preference = TITLE;
    } else {
      bops[i].preference = BOP_NAME;
    }
  }

  cout << "Benevolent Order of Programers Report" << endl;
  cout << "a. display by name     ";
  cout << "b. display by title" << endl;
  cout << "c. display by bopname  ";
  cout << "d. display by preference" << endl;
  cout << "q. quit" << endl;
  cout << "Enter your choice: ";

  char choice;
  while (cin >> choice) {
    if ('q' == choice) {
      cout << "Bye!" << endl;
      break;
    } else if ('a' == choice || 'b' == choice || 'c' == choice ||
               'd' == choice) {
      for (int i = 0; i < 5; i++) {
        switch (choice) {
        case 'a':
          cout << bops[i].fullname << endl;
          break;
        case 'b':
          cout << bops[i].title << endl;
          break;
        case 'c':
          cout << bops[i].bopname << endl;
          break;
        case 'd':
          switch (bops[i].preference) {
          case FULL_NAME:
            cout << bops[i].fullname << endl;
            break;
          case TITLE:
            cout << bops[i].title << endl;
            break;
          case BOP_NAME:
            cout << bops[i].bopname << endl;
            break;
          }
          break;
        }
      }
      cout << "Next choice: ";
    }
  }

  delete[] bops;
  return 0;
}
