#pragma once

class OurPoint {
protected:
	int x;
	int y;
public:
	int getX() const { return x; }
	int getY() const { return y; }
	int getType() const;
	Point(int x = -1, int y = -1) : x(x), y(y) { }
};
