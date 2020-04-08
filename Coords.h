#pragma once

class Coords {
protected:
	int x;
	int y;
public:
	friend class Stack;
	friend class Grid;
	int getX() { return x; };
	int getY() { return y; };
	Coords(int x, int y) : x(x), y(y) { }
};