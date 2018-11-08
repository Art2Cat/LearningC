#include <iostream>
#include <cstring>

using namespace std;

class Person {
	private:
		static const int LIMIT = 25;
		string lname;
		char fname[LIMIT];
	public:
		Person() { lname = ""; fname[0] = '\0'; }
		Person(const string &ln, const char *fn = "Heyyou");
		void show() const;
		void formalShow() const;
};

int main() {

	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy", "Sam");
	one.show();
	cout << endl;
	one.formalShow();
	cout << endl;
	two.show();
	cout << endl;
	two.formalShow();
	cout << endl;
	three.show();
	cout << endl;
	three.formalShow();
	cout <<endl;
	return 0;
}

Person::Person(const string &ln, const char *fn) {
	lname = ln;
	strcpy(fname, fn);
}

void Person::show() const {
	cout << fname << " " << lname << endl;
}

void Person::formalShow() const {
	cout << lname << ", " << fname << endl;
}
