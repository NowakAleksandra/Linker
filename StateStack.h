#pragma once
#include<vector>
#include"Level.h"

class StateStack {
	vector<Level> stack;
public:
	void addState(Level);
	Level reverse();
	Level& last();
	Level& ndLast();
};