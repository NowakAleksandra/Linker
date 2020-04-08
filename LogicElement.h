#pragma once

class LogicElement :public Coords {
protected:
	bool fulfilled;
public:
	virtual bool checkFulfilled(Grid& grid) = 0;
	LogicElement(int x = -1, int y = -1) :Coords(x, y), fulfilled(false) { };
};