#include <iostream>

using namespace std;
long fact(int);

int main() {

  long result;
  int n;

  cout << "Enter number: ";
  while (cin >> n) {
    result = fact(n);
    cout << n << "! = " << result << endl;
    cout << "Enter number: ";
  }

  return 0;
}

long fact(int n) {
  if (n == 0)
    return 1;

  return n * fact(n - 1);
}
