#include <iostream>

struct candy_bar {
  char brand[20];
  double weight;
  int calorie;
};

int main(void) {
  using namespace std;
  candy_bar candies[3];
  candies[0] = {"Mocha Munch", 2.3, 350};
  candies[1] = {"Mocha Munch", 2.3, 350};
  candies[2] = {"Mocha Munch", 2.3, 350};
  for (int i = 0; i < 3; i++) {
    cout << "Brand: " << candies[i].brand << endl;
    cout << "Weight: " << candies[i].weight << endl;
    cout << "Calorie: " << candies[i].calorie << endl;
  }
  return 0;
}
