#include"StateStack.h"

void StateStack::addState(Level state) {
	stack.push_back(state);
}

Level& StateStack::last() {
	return stack.back();
}

Level StateStack::reverse() {
	stack.pop_back();
	return last();
}

Level& StateStack::ndLast() {
	return stack[stack.size() - 2];
	//risk of executing when stack is of size 1
}

bool StateStack::move(const char dir) {
	int pX = last().getPlayer(0).getX();
	int pY = last().getPlayer(0).getY();
	int pV = last().getPlayer(0).getV();
	if (last().findEdgeState(pX, pY, pV, dir) != 1) { // checkig for valid edge 
		return 0;
	}
	if (dir == 'r') { // right
		if ((pV == 0 || pV == 1) && !last().isVertexVisited(pX + 1, pY, pV)) {
			pX++;
		}
		else if ((pV == 2 || pV == 3) && !last().isVertexVisited(pX, pY, (pV == 2) ? 1 : 0)) {
			pV = (pV == 2) ? 1 : 0;
		}
		else {
			return false;
		}
	}
	else if (dir == 'd') { // down
		if ((pV == 0 || pV == 3) && !last().isVertexVisited(pX, pY, (pV == 0) ? 1 : 2)) {
			pV = (pV == 0) ? 1 : 2;
		}
		else if ((pV == 1 || pV == 2) && !last().isVertexVisited(pX, pY + 1, pV)) {
			pY++;
		}
		else {
			return false;
		}
	}
	else if (dir == 'u') { // up
		if (pY == 0 && (pV == 1 || pV == 2) && !last().isVertexVisited(pX, pY, (pV == 1) ? 0 : 3)) {
			pV = (pV == 1) ? 0 : 3;
		}
		else if (!last().isVertexVisited(pX, pY - 1, pV)) {
			pY--;
		}
		else {
			return false;
		}
	}
	else if (dir == 'l') { // left
		if (pX == 0 && (pV == 0 || pV == 1) && !last().isVertexVisited(pX, pY, (pV == 0) ? 3 : 2)) {
			pV = (pV == 0) ? 3 : 2;
		}
		else if (!last().isVertexVisited(pX - 1, pY, pV)) {
			pX--;
		}
		else {
			return false;
		}
	}
	// valid move
	Level newState = last();
	newState.getPlayer(0).setPlayerCoords(pX, pY, pV);
	newState.getTile(pX, pY).visit(pV);
	addState(newState);
	return true;
}

void StateStack::draw(Mat image)
{	
	last().draw(image);
}
