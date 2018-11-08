#include <iostream>

using namespace std;
#include <cstring>

struct stringy {
  char *str;
  int ct;
};

void set(stringy &, const char *);

void show(const stringy &, int times = 1);

void show(const char *, int times = 1);

int main() {
  stringy beany;
  char testing[] = "Reality isn't what it used to be.";

  set(beany, testing);
  show(beany);
  show(beany, 2);
  testing[0] = 'D';
  testing[1] = 'u';
  show(testing);
  show(testing, 3);
  show("Done!");
  return 0;
}

void set(stringy &stry, const char *strx) {

  stry.str = new char[strlen(strx)];
  strcpy(stry.str, strx);
  stry.ct = strlen(strx);
}

void show(const stringy &stry, int times) {
  if (times == 1) {
    cout << stry.str << endl;
  } else {
    for (int i = 0; i < times; i++) {
      cout << stry.str << endl;
    }
  }
}

void show(const char *str, int times) {
  if (times == 1) {
    cout << str << endl;
  } else {
    for (int i = 0; i < times; i++) {
      cout << str << endl;
    }
  }
}
