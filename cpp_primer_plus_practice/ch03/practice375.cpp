#include <iostream>

int main(void) {
  using namespace std;
  long long worldPop, usPop;
  cout << "Enter the world's population: ";
  cin >> worldPop;
  cout << "Enter the population of the US: ";
  cin >> usPop;
  double ratio = (usPop / (worldPop * 1.0)) * 100;
  cout << "The population of the US is " << ratio
       << "\% of the world population.\n";
  return 0;
}
