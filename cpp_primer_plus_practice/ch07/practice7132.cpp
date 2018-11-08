#include <iostream>

using namespace std;
const int SIZE = 10;

bool input(double *, int *);

void print(const double *, double, int);

double average(const double *, int);

int main() {
  while (true) {
    double result[SIZE] = {0};
    int size = 0;
    if (!input(result, &size)) {
      break;
    }
    double avg = average(result, size);
    print(result, avg, size);
    cout << size << endl;
  }
  cout << "exit!" << endl;
  return 0;
}

bool input(double *result, int *size) {
  bool flag = true;
  for (int i = 0; i < SIZE; i++) {
    cout << "Enter your score(enter -1 to exit): ";
    double x = 0;
    if (cin >> x) {
      if (x == -1) {
        break;
      }
      result[i] = x;
      *size = i + 1;
    } else if (cin.fail()) {
      flag = false;
      break;
    }
  }
  return flag;
}

double average(const double *result, int size) {
  double sum = 0;
  for (int i = 0; i < size; i++) {
    sum += result[i];
  }
  return sum / size;
}

void print(const double *result, double avg, int size) {
  cout << "score is [";
  for (int i = 0; i < size; i++) {
    cout << result[i] << " ";
  }
  cout << "], average score is " << avg << endl;
  size = 99;
}
