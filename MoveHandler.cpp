#include"MoveHandler.h"

bool MoveHandler::isVisited(int x, int y) const {
	for (int i = 0; i < moveHistory.size(); i++) {
		if (x == moveHistory[i].getX() && y == moveHistory[i].getY()) {
			return true;
		}
	}
	return false;
}

std::pair<int, int> MoveHandler::calculateShift(char dir) const {
	std::pair<int, int> shift[4] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
	const char dirList[4] = { 'U', 'D', 'L', 'R' };
	for (int i = 0; i < 4; i++) {
		if (dir == dirList[i]) {
			return shift[i];
		}
	}
}

bool MoveHandler::isMoveValid(std::pair<int, int> shift, Level& lvl) const {
	int x = player.getX() + shift.first;
	int y = player.getY() + shift.second;
	if (lvl.doesPointExist(x, y) && !isVisited(x, y)) {
		return true;
	}
	return false;
}

bool MoveHandler::checkForReverse(char dir) const {
	const char dirList[4] = { 'U', 'D', 'L', 'R' };
	const char oppositeDirList[4] = { 'D', 'U', 'R', 'L' };
	for (int i = 0; i < 4; i++) {
		if (dir == dirList[i] && player.getHeading() == oppositeDirList[i]) {
			return true;
		}
	}
	return false;
}

void MoveHandler::undoMove() {
	moveHistory.pop_back();
	player.setPos(moveHistory.back()); // cast on Point 
	player.setHeading(moveHistory.back().getHeading());
}

bool MoveHandler::moveRequest(char dir, Level& lvl) {
	if (checkForReverse(dir)) { // reversing is always a valid action
		undoMove();
		return true;
	}
	std::pair<int, int> shift = calculateShift(dir);
	if (isMoveValid(shift, lvl)) {
		moveHistory.push_back(MoveInfo(shift.first, shift.second, dir));
		player.shiftPos(shift);
		player.setHeading(dir);
		return true;
	}
	return false;
}

MoveHandler::MoveHandler(Player& player) {
	this->player = player;
	moveHistory.push_back(MoveInfo(player.getX(), player.getY()));
}