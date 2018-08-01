#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>

struct patron {
  std::string name;
  double deposit;
};

const double LEVEL = 10000;

void add_patron(patron *patrons, int len);

int main() {
  using namespace std;
  string file_name;
  ifstream inFile;
  cout << "Enter name of data file: ";
  cin >> file_name;

  inFile.open(file_name.c_str());

  if (!inFile.is_open()) {
    cout << "Could not open the file " << file_name << endl;
    cout << "Program terminating." << endl;
    exit(EXIT_FAILURE);
  }

  int total;
  inFile >> total;
  cout << "total line: " << total << endl;
  inFile.get();
  patron patrons[total];

  for (int i = 0; i < total; i++) {
    getline(inFile, (patrons + i)->name);
    inFile >> patrons[i].deposit;
    inFile.get();
  }

  inFile.close();

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
