#include <iostream>

using namespace std;

const int SLEN = 30;
struct student {
  char fullname[SLEN];
  char hobby[SLEN];
  int ooplevel;
};

int getInfo(student pa[], int n);

void display1(student st);

void display2(const student *ps);

void display3(const student pa[], int n);

int main() {
  cout << "Enter class size: ";
  int class_size;
  cin >> class_size;
  while (cin.get() != '\n') {
    continue;
  }
  student *stu_p = new student[class_size];
  int entered = getInfo(stu_p, class_size);
  for (int i = 0; i < entered; i++) {
    display1(stu_p[i]);
    display2(&stu_p[i]);
  }
  cout << endl;
  display3(stu_p, entered);
  delete[] stu_p;
  cout << "Done\n";
  return 0;
}

int getInfo(student pa[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    cout << "Enter student fullname: ";
    if (cin >> pa[i].fullname) {
      cin.clear();
    } else if (cin.fail()) {
      break;
    }
    cout << "Enter student hobby: ";
    cin >> pa[i].hobby;
    cin.clear();
    cout << "Enter student ooplevel: ";
    if (cin >> pa[i].ooplevel) {
      cin.clear();
    } else if (cin.fail()) {
      break;
    }
  }
  return i;
}

void display1(student st) {
  cout << "Student: " << st.fullname << ", hobby: " << st.hobby
       << ", ooplevel: " << st.ooplevel << ".\n";
}

void display2(const student *ps) {
  cout << "Student: " << ps->fullname << ", hobby: " << ps->hobby
       << ", ooplevel: " << ps->ooplevel << ".\n";
}

void display3(const student pa[], int n) {
  for (int i = 0; i < n; i++) {
    display1(pa[i]);
  }
}
