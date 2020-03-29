#pragma once
using namespace std;

class Tile {
	int x, y;
	int edge[4];
	bool visited[4];
public:
	int getX();
	int getY();
	bool getVisited(int);
	int getEdgeState(int);
	void visit(int);
	friend class Level;
	Tile(int _x, int _y, int* e);
};