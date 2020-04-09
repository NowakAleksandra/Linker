#pragma once
#include"Coords.h"

class Head :public Coords {
	char facing;
public:
	friend class Grid;
	friend class Stack;
	char getFacing() { return facing; };
	Head(int x = -1, int y = -1) :Coords(x, y), facing('0') { };
};

