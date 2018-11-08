#include "golf.h"
#include <cstring>
#include <iostream>

using namespace std;

void setGolf(golf &g, const char *name, int hc) {
	strcpy(g.fullname, name);
	// g.fullname = name;
	g.handicap = hc;
}

int setGolf(golf &g) {
	cout << "Enter fullname: ";
	cin.getline(g.fullname, LEN);
	cout << "Enter handicap: ";
	cin >> g.handicap;

	if (strlen(g.fullname) > 0) {
		return 1;
	}

	return 0;
}

void handicap(golf &g, int hc) { g.handicap = hc; }

void showGolf(const golf &g) {
	cout << "Golf: " << g.fullname << ", " << g.handicap << "." << endl;
}
