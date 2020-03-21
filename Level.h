#pragma once
#include<vector>
#include"Tile.h"
using namespace std;

class Level {
	vector<Tile> grid;
	int lvlNo;
	int diff;
public:
	void setDifficulty(int _diff);
	void import(int lvl);
	Level(int lvl);
};