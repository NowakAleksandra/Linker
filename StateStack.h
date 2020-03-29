#pragma once
#include<vector>
#include"Level.h"

class StateStack {
	vector<Level> stack;
public:
	void addState(Level);
	bool move(const char);
	Level reverse();
	Level& last();
	Level& ndLast();
};