#include <iostream>

struct patron {
  std::string name;
  double deposit;
};

const double LEVEL = 10000;

void add_patron(patron *patrons, int len);

int main() {
  using namespace std;
  patron patrons[10];
  add_patron(patrons, 10);
  cout << "Grand Patrons:" << endl;

  for (int i = 0; i < 10; i++) {
    if (patrons[i].deposit >= LEVEL) {
      cout << "name: " << patrons[i].name << ", amount: " << patrons[i].deposit
           << endl;
    }
  }

  cout << endl;
  cout << "Patrons:" << endl;
  for (int i = 0; i < 10; i++) {
    if (patrons[i].deposit > 0 && patrons[i].deposit < LEVEL) {
      cout << "name: " << patrons[i].name << ", amount: " << patrons[i].deposit
           << endl;
    }
  }

  return 0;
}

void add_patron(patron *patrons, int len) {
  using namespace std;
  for (int i = 0; i < len; i++) {
    patron *p = new patron;

    cout << "Enter your name: ";
    cin >> p->name;
    cout << "Enter your sponsor amount: ";
    cin >> p->deposit;
    patrons[i] = *p;
  }
}
