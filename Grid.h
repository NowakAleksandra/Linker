#pragma once
#include<vector>
#include"Point.h"
#include"Head.h"
#include"LogicElement.h"
#include<memory>

class Grid {
	std::vector<Point> vertex;
	std::vector<Point> edge;
	std::vector<Head> head;
	std::vector<Coords> start;
	std::vector<Coords> end;
	std::vector<std::shared_ptr<LogicElement>> logElem;
public:
	friend class Stack;
	Point& getPoint(int, int);
	Grid(int);
	bool doesPointExist(int, int);
	void draw(); // debug
};