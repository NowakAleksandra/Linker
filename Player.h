#pragma once
#include"Point.h"
#include<utility>

class Player : public Point {
protected:
	char heading; // U - up, D - down, L - left, R - right, 0 - nowhere
public:
	char getHeading() const { return heading; }
	void setHeading(char dir) { heading = dir; }
	void shiftPos(std::pair<int, int> shift) { x += shift.first; y += shift.second; }
	void setPos(Point& p) { x = p.getX(); y = p.getY(); }
	Player(int x = -1, int y = -1, char dir = '0') : Point(x, y) { heading = dir; }
};