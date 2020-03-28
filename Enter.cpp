#include"Enter.h"

Enter::Enter(int _x, int _y, int v) {
	x = _x;
	y = _y;
	vertex = v;
	active = false;
}

void Enter::changeState(bool state) {
	active = state;
}

bool Enter::isActive() {
	return active;
}