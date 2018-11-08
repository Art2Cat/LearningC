#include "golf.h"
#include <iostream>

int main() {
	Golf ann("Ann Birdfree", 24);
	ann.showGolf();
	ann.setHandicap(23);
	ann.showGolf();

	Golf andy;
	andy.setGolf();
	andy.showGolf();
	andy.setFullName("Andy Jeff");
	andy.showGolf();
	return 0;
}
