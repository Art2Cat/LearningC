#include "golf.h"
#include <iostream>

int main() {
	golf ann;
	setGolf(ann, "Ann Birdfree", 24);

	showGolf(ann);

	golf andy;
	setGolf(andy);
	showGolf(andy);
	return 0;
}
