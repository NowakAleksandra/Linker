#pragma once
#include"Coords.h"

class Point :public Coords {
	bool visited;
public:
	friend class Grid;
	friend class Stack;
	bool isVisited() { return visited; };
	Point(int x = -1, int y = -1) :Coords(x, y), visited(false) { };
};