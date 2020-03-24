#pragma once
#include<vector>
#include<string>
#include"Tile.h"
#include"Enter.h"
#include"Exit.h"
using namespace std;

class Level {
	vector<Tile> grid;
	vector<Enter> entryPoints;
	vector<Exit> exitPoints;
	string name;
	int lvlNo;
	int diff;
public:
	void setDiff(int);
	void setName(string);
	void setLevelNo(int);
	void displayInfo(); // debug
	friend bool isVisited(const Level& lvl, int _x, int _y, int _v);
	Level(int lvl);
};