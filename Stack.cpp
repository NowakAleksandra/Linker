#include<iostream>
#include"Stack.h"
#include"Dot.h"

void Stack::update(Grid state) {
	stack.push_back(state);
}

Grid& Stack::last() { // ostatni stan
	return stack.back();
}

void Stack::undo() {
	stack.pop_back();
}

void Stack::init(int lvl) { // inicjalizacja
	update(Grid(lvl));
	int startNo = 0;
	Coords playerPos = last().start[startNo];
	last().head.push_back(Head(playerPos.x, playerPos.y));
	last().getPoint(playerPos.x, playerPos.y).visited = true;
}

void Stack::reset(int n) {
	stack.clear();
	init(n);
}

bool Stack::lineConnected() {
	for (int i = 0; i < last().end.size(); i++) {
		if (last().end[i].x == last().head[0].x && last().end[i].y == last().head[0].y) {
			return true;
		}
	}
	return false;
}

bool Stack::isSolution() {
	for (int i = 0; i < last().logElem.size(); i++) {
		if (!(last().logElem[i]->checkFulfilled(last()))) {
			return false;
		}
	}
	return true;
}

bool Stack::move(const char dir) {
	int dX = last().head[0].x; // zalozenie jest takie ze moze byc wiecej wezy niz jeden wiec na razie jest tylko jeden; head[0]
	int dY = last().head[0].y;
	const char facing = last().head[0].facing;
	bool flag = true;
	switch (dir) {
	case 'R':
		if (facing != 'L') {
			dX++;
			flag = false;
		}
		break;
	case 'L':
		if (facing != 'R') {
			dX--;
			flag = false;
		}
		break;
	case 'U':
		if (facing != 'D') {
			dY--;
			flag = false;
		}
		break;
	case 'D':
		if (facing != 'U') {
			dY++;
			flag = false;
		}
		break;
	}
	if (flag) {
		undo();
		return true;
	}
	if (last().doesPointExist(dX, dY)) {
		if (!last().getPoint(dX, dY).visited) {
			Grid newState = stack.back();
			newState.head[0].x = dX;
			newState.head[0].y = dY;
			newState.head[0].facing = dir;
			newState.getPoint(dX, dY).visited = true;
			update(newState);
			return true;
		}
	}
	return false;
}