//#include<opencv2/opencv.hpp>
//#include<iostream>
//using namespace std;
//using namespace cv;
//int main()
//{
//    Mat img = imread("lena.jpg");
//    namedWindow("image", WINDOW_NORMAL);
//    imshow("image", img);
//    waitKey(0);
//    return 0;
//}

#include<iostream>
#include"StateStack.h"
using namespace std;

bool isVisited(const Level& lvl, int _x, int _y, int _v);
int findEdgeState(StateStack& state, int _x, int _y, int _v, const char dir); // metoda?
char checkForMoveKeyPress(); // debug
bool movePlayer(StateStack&, const char); // metoda?

int main(void) {
	StateStack stateStack;
	stateStack.addState(Level(1));
	stateStack.last().addPlayer(Player(0, 0, 3));
	stateStack.last().getTile(0, 0).visit(3);
	while (true) {
		cout << stateStack.last().getPlayer(0).getX() << ", " << stateStack.last().getPlayer(0).getY() << ", " << stateStack.last().getPlayer(0).getV() << "\n";
		if (movePlayer(stateStack, checkForMoveKeyPress()))
			cout << "Moved!\n";
		else
			cout << "Coudn't move!\n";
	}
}

int findEdgeState(StateStack& state, int _x, int _y, int _v, const char dir) {
	if (dir == 'r') { // right
		if (_v == 0 || _v == 1) {
			if (state.last().doesTileExist(_x + 1, _y)) {
				return state.last().getTile(_x + 1, _y).getEdgeState((_v == 0) ? 3 : 1);
			}
			else {
				return 0;
			}
		}
		return state.last().getTile(_x, _y).getEdgeState((_v == 2) ? 1 : 3);
	}
	else if (dir == 'd') { // down
		if (_v == 1 || _v == 2) {
			if (state.last().doesTileExist(_x, _y + 1)) {
				return state.last().getTile(_x, _y + 1).getEdgeState((_v == 1) ? 0 : 2);
			}
			else {
				return 0;
			}
		}
		return state.last().getTile(_x, _y).getEdgeState((_v == 0) ? 0 : 2);
	}
	else if (dir == 'u') { // up
		if (_v == 0 || _v == 3) {
			if (state.last().doesTileExist(_x, _y - 1)) {
				return state.last().getTile(_x, _y - 1).getEdgeState((_v == 0) ? 0 : 2);
			}
			else {
				return 0;
			}
		}
		return state.last().getTile(_x, _y).getEdgeState((_v == 1) ? 0 : 2);
	}
	else if (dir == 'l') { // left
		if (_v == 2 || _v == 3) {
			if (state.last().doesTileExist(_x - 1, _y)) {
				return state.last().getTile(_x - 1, _y).getEdgeState((_v == 2) ? 1 : 3);
			}
			else {
				return 0;
			}
		}
		return state.last().getTile(_x, _y).getEdgeState((_v == 0) ? 3 : 1);
	}
}

bool movePlayer(StateStack& state, const char dir) {
	// w zalozeniu wszystkie krwadedzie istnieja, dodac wyjatki na brak krawedzi
	int pX = state.last().getPlayer(0).getX();
	int pY = state.last().getPlayer(0).getY();
	int pV = state.last().getPlayer(0).getV();
	if (findEdgeState(state, pX, pY, pV, dir) != 1) {
		return 0;
	}
	if (dir == 'r') { // right
		if ((pV == 0 || pV == 1) && !isVisited(state.last(), pX + 1, pY, pV)) {
			pX++;
		}
		else if ((pV == 2 || pV == 3) && !isVisited(state.last(), pX, pY, (pV == 2) ? 1 : 0)) {
			pV = (pV == 2) ? 1 : 0;
		}
		else {
			return false;
		}
	}
	else if (dir == 'd') { // down
		if ((pV == 0 || pV == 3) && !isVisited(state.last(), pX, pY, (pV == 0) ? 1 : 2)) {
			pV = (pV == 0) ? 1 : 2;
		}
		else if ((pV == 1 || pV == 2) && !isVisited(state.last(), pX, pY + 1, pV)) {
			pY++;
		}
		else {
			return false;
		}
	}
	else if (dir == 'u') { // up
		if (pY == 0 && (pV == 1 || pV == 2) && !isVisited(state.last(), pX, pY, (pV == 1) ? 0 : 3)) {
			pV = (pV == 1) ? 0 : 3;
		}
		else if (!isVisited(state.last(), pX, pY - 1, pV)) {
			pY--;
		}
		else {
			return false;
		}
	}
	else if (dir == 'l') { // left
		if (pX == 0 && (pV == 0 || pV == 1) && !isVisited(state.last(), pX, pY, (pV == 0) ? 3 : 2)) {
			pV = (pV == 0) ? 3 : 2;
		}
		else if (!isVisited(state.last(), pX - 1, pY, pV)) {
			pX--;
		}
		else {
			return false;
		}
	}
	// valid move
	Level newState = state.last();
	newState.getPlayer(0).setPlayerCoords(pX, pY, pV);
	newState.getTile(pX, pY).visit(pV);
	state.addState(newState);
	return true;
}

char checkForMoveKeyPress() {
	//debug mode
	char k;
	while (true) {
		cin >> k;
		switch (k) {
		case 'w':
			return 'u';
		case 'a':
			return 'l';
		case 's':
			return 'd';
		case 'd':
			return 'r';
		}
	}
}

bool isVisited(const Level& lvl, int _x, int _y, int _v) {
	for (int i = 0; i < lvl.gridSize(); i++) {
		if (lvl.grid[i].getX() == _x && lvl.grid[i].getY() == _y) {
			cout << "Found!\n";
			return lvl.grid[i].getVisited(_v);
		}
	}
	return true; // if vertex does not exist
}