#pragma once
#include"Player.h"
#include"Level.h"
#include"MoveInfo.h"
#include<utility>
#include<vector>

class MoveHandler {
	Player player;
	std::vector<MoveInfo> moveHistory;
	bool checkForReverse(char) const;
	std::pair<int, int> calculateShift(char) const;
	bool isMoveValid(std::pair<int, int>, Level&) const;
	void undoMove();
public:
	bool isVisited(int x, int y) const;
	// requests move operation, returns true if succeeded
	bool moveRequest(char dir, Level& lvl);
	MoveHandler(Player& player);
	// default constructor
	MoveHandler() { }
};