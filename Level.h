#pragma once
#include<vector>
#include<string>
#include"Tile.h"
#include"Enter.h"
#include"Exit.h"
#include"Player.h"
#include"StateStack.h"
using namespace std;

class Level {
	vector<Enter> entryPoints;
	vector<Exit> exitPoints;
	vector<Player> player;
	vector<Tile> grid;
	string name;
	int lvlNo;
	int diff;
public:
	void setDiff(int);
	void setName(string);
	void setLevelNo(int);
	void displayInfo(); // debug
	void addPlayer(Player);
	bool doesTileExist(int, int);
	int findEdgeState(int, int, int, const char);
	Player& getPlayer(int);
	Tile& getTile(int, int);
	bool isVertexVisited(int _x, int _y, int _v);
	Level(int lvl);
};