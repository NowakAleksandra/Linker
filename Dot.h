#pragma once
#include"LogicElement.h"
#include"Grid.h"

class Dot :public LogicElement {
public:
	virtual bool checkFulfilled(Grid& grid) {
		if (grid.getPoint(x, y).isVisited()) {
			fulfilled = true;
			return true;
		}
		else return false;
	}
	Dot(int x = -1, int y = -1) :LogicElement(x, y) { };
};
