#include "move.h"
#include <iostream>

int main() {
	Move m(22,33);
	m.showMove();
	std::cout << std::endl;
	Move m1(33,44);
	m1.showMove();
	std::cout << std::endl;
	Move m2 = m.add(m1);
	m2.showMove();
	std::cout << std::endl;
	m.reset();
	m.showMove();
	return 0;
}
