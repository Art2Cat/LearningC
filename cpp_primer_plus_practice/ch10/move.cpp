#include "move.h"
#include <iostream>

Move::Move(double a, double b) {
	x = a;
	y = b;
}

void Move::showMove() const {
	std::cout << "Move { x: " << x << "; y: " << y << " }" << std::endl;
}

Move Move::add(const Move &m) const {
	return Move(x + m.x, y+m.y);
}

void Move::reset(double a, double b) {
	x = a;
	y = b;
}

