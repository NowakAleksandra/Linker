#pragma once
#include<vector>
#include"Grid.h"

class Stack {
	std::vector<Grid> stack;
public:
	void update(Grid);
	void reset(int);
	void undo();
	bool move(char);
	Grid& last();
	bool lineConnected();
	bool isSolution();
	void init(int);
};
