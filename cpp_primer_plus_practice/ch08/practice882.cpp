#include <cstring>
#include <iostream>

using namespace std;
const int STR_LEN = 30;

struct CandyBar {
  char name[STR_LEN];
  double weight;
  int heat_quantity;
};

inline void display(const CandyBar &);

void fill_candy_bar(CandyBar &, const char *name = "Millennium Munch",
                    double weight = 2.85, int hq = 350);

int main() {
  CandyBar *cb = new CandyBar;
  fill_candy_bar(*cb);
  const char *name = "Munch";
  double weight = 2.33;
  int heat = 222;
  fill_candy_bar(*cb, name, weight, heat);
  return 0;
}

inline void display(const CandyBar &cb) {
  cout << "CandyBar[name: " << cb.name << ", weight: " << cb.weight
       << ", heat quantity: " << cb.heat_quantity << "]" << endl;
}

void fill_candy_bar(CandyBar &cb, const char *name, double weight, int hq) {
  strcpy(cb.name, name);
  cb.weight = weight;
  cb.heat_quantity = hq;
  display(cb);
}
