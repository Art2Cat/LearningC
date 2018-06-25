#include <iostream>

struct student {
  char first_name[20];
  char last_name[20];
  char grade;
  int age;
};

int main(void) {
  using namespace std;

  student *st = new student;
  cout << "What is your first name? ";
  cin.getline(st->first_name, 20);
  cout << "What is your last name? ";
  cin.getline(st->last_name, 20);
  cout << "What letter do you deserve? ";
  cin.get(&(st->grade), 2);
  cout << "What is your age? ";
  cin >> st->age;
  cout << "Name: " << st->first_name << ", " << st->last_name << endl;
  cout << "Grade: " << (char)(st->grade + 1) << endl;
  cout << "Age: " << st->age << endl;

  delete st;
  return 0;
}
