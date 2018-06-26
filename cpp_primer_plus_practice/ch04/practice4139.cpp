#include <iostream>

struct candy_bar {
  std::string brand;
  double weight;
  int calorie;
  /* candy_bar(std::string brand, double weight, int calorie) {
     this->brand = brand;
     this->weight = weight;
     this->calorie = calorie;
   }
         **/
};

int main(void) {
  using namespace std;
  candy_bar *candies = new candy_bar[3];
  candy_bar *candy = new candy_bar;
  candy->brand = "Mocha Munch";
  candy->weight = 2.3;
  candy->calorie = 350;
  candies[0] = *candy;
  candies[1] = *candy;
  candies[2] = *candy;
  for (int i = 0; i < 3; i++) {
    cout << "Brand: " << candies[i].brand << endl;
    cout << "Weight: " << candies[i].weight << endl;
    cout << "Calorie: " << candies[i].calorie << endl;
  }
  delete candy;
  delete[] candies;
  return 0;
}
