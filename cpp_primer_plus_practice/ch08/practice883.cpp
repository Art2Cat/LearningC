#include <iostream>
#include <string>

using namespace std;

void toUpper(string &);

int main() {
  string str;
  cout << "Enter a string(q to quit): ";

  while (true) {
    getline(cin, str);

    if (str == "q") {
      break;
    }
    toUpper(str);

    cout.clear();
    cout << str << endl;
    cout << "Next string(q to quit): ";
  }
  cout << "Exit." << endl;
  return 0;
}
void toUpper(string &str) {
  for (auto &c : str)
    c = toupper(c);
}
