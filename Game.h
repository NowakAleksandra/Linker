#pragma once
#include"Level.h"
#include"MoveHandler.h"
#include"SolutionChecker.h"

class Game {
	int currLvlNo;
	Level level;
	/*
		+ info [points] about map layout (panel)
		+ info [pos, type] about conditional map elements (mapElem)
		+ info [points] about entry and exit points (entry/exit)
	*/
	MoveHandler moveHandler;
	/*
		+ info [pos, heading dir] about player location (player)
		+ vector of visited points (visited) - important for SolutionChecker
		+ handles moves and checks if they are valid
	*/
	SolutionChecker solutionChecker;
public:
	void loadNewLevel(int lvlNo);
	Game(int currLvlNo);
};