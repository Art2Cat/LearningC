#include <iostream>

struct candy_bar {
  char brand[20];
  double weight;
  int calorie;
};

int main(void) {
  using namespace std;
  candy_bar mocha = {"Mocha Munch", 2.3, 350};
  cout << "Brand: " << mocha.brand << endl;
  cout << "Weight: " << mocha.weight << endl;
  cout << "Calorie: " << mocha.calorie << endl;
  return 0;
}
