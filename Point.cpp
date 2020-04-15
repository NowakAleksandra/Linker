#include"Point.h"

int Point::getType() const {
	if (x % 2 == 0 && y % 2 == 0) {
		return 0; // vertex (0) "+"
	}
	else if (x % 2 == 1) {
		return 1; // horizontal edge (1) "--"
	}
	else if (y % 2 == 1) {
		return 2; // vertical edge (2) "|"
	}
}