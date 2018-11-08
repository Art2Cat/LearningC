#include "golf.h"
#include <iostream>

using namespace std;

Golf::Golf() {
	strcpy(fullname, "");
	handicap = 0;
}

Golf::Golf(const char *name, int hc) {
	strcpy(fullname, name);
	handicap = hc;
}

int Golf::setGolf() {
	cout << "Enter fullname: ";
	char * name = new char [LEN];
	cin.getline(name, LEN);
	cout << "Enter handicap: ";
	int hc;
	cin >> hc;
	this->setFullName(name);
	this->setHandicap(hc);

	delete [] name;
	if (strlen(this->getFullName()) > 0) {
		return 1;
	}

	return 0;
}

void Golf::setFullName(const char * name) {
	strcpy(fullname, name);
}

const char * Golf::getFullName() const {
	return this->fullname;
}

void Golf::setHandicap(int hc) { handicap = hc; }

int Golf::getHandicap() const {
	return this->handicap;
}
void Golf::showGolf() {
	cout << "Golf: " << fullname << ", " << handicap << "." << endl;
}
