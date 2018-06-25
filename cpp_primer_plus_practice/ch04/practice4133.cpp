#include <cstring>
#include <iostream>

int main(void) {
  using namespace std;
  char first_name[20];
  char last_name[20];
  char *full_name;
  cout << "Enter your first name: ";
  cin.getline(first_name, 20);
  cout << "Enter your last name: ";
  cin.getline(last_name, 20);
  char *tmp = strcat(first_name, ", ");
  full_name = strcat(tmp, last_name);
  cout << "Here's the information in a single string: " << full_name << endl;
  return 0;
}
