#pragma once

class Point {
protected:
	int x;
	int y;
public:
	int getX() const { return x; }
	int getY() const { return y; }
	Point(int x = -1, int y = -1) : x(x), y(y) { }
};
