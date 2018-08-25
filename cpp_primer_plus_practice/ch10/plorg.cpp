#include "plorg.h"
#include <cstring>
#include <iostream>

using namespace std;

Plorg::Plorg(const char * n, int c) {
	strcpy(name,n);
	ci = c;
}

void Plorg::updateCI(int c) {
	ci = c;
}

void Plorg::show() const {
	cout << "Plorg { name: " << name << ", CI: " << ci << " }.\n";
}
