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
char checkForMoveKeyPress();
bool movePlayer(StateStack&, const char);

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

bool movePlayer(StateStack& state, const char key) {
	// w zalozeniu wszystkie krwadedzie istnieja, dodac wyjatki na brak krawedzi
	int pX = state.last().getPlayer(0).getX();
	int pY = state.last().getPlayer(0).getY();
	int pV = state.last().getPlayer(0).getV();
	if (key == 'r') { // right
		if ((pV == 0 || pV == 1) && !isVisited(state.last(), pX + 1, pY, pV)) {
			pX++;
		}
		else if ((pV == 2 || pV == 3) && !isVisited(state.last(), pX, pY, pV + (pV == 2) ? -1 : 1)) {
			pV += (pV == 2) ? -1 : 1;
		}
		else {
			return false;
		}
	}
	else if (key == 'd') { // down
		if ((pV == 0 || pV == 3) && !isVisited(state.last(), pX, pY, pV + (pV == 0) ? 1 : -1)) {
			pV += (pV == 0) ? 1 : -1;
		}
		else if ((pV == 1 || pV == 2) && !isVisited(state.last(), pX, pY + 1, pV)) {
			pY++;
		}
		else {
			return false;
		}
	}
	else if (key == 'u' && !isVisited(state.last(), pX, pY - 1, pV)) { // up, always torward (0,0)
		pY--;
	}
	else if (key == 'l' && !isVisited(state.last(), pX - 1, pY, pV)) { // left, always torwards (0,0)
		pX--;
	}
	else { // when up and left fail
		return false;
	}
	// valid move
	Level newState = state.last();
	newState.getPlayer(0).setPlayerCoords(pX, pY, pV % 4);
	newState.getTile(pX, pY).visit(pV % 4);
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
	for (int i = 0; i < lvl.grid.size(); i++) {
		if (lvl.grid[i].getX() == _x && lvl.grid[i].getY() == _y) {
			cout << "Found!\n";
			return lvl.grid[i].getVisited(_v % 4);
		}
	}
	return true; // if vertex does not exist
}