#pragma once
using namespace std;

class Player {
	int x, y, v;
public:
	void setPlayerCoords(int, int, int);
	int getX();
	int getY();
	int getV();
	Player(int, int, int);
};