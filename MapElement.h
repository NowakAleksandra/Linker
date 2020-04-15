#pragma once
#include"Point.h"
#include<string>

class MapElement : public Point {
protected:
	std::string name;
	bool fulfilled;
public:
	// important for SolutionChecker
	virtual bool checkConditions() const = 0;
	bool isFulfilled() const { return fulfilled; }
	MapElement(int x = -1, int y = -1, std::string name = "") : Point(x, y), name(name), fulfilled(false) { }
};