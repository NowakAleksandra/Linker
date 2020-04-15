#pragma once
#include"MapElement.h"

// example of conditional map element; Objective: must be visited to be fulfilled
class Dot : public MapElement {
public:
	virtual bool checkConditions() const { return false; } // TEMP
	Dot(int x = -1, int y = -1) : MapElement(x, y, "dot") { }
};