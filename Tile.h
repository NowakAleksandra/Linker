#pragma once
using namespace std;

class Tile {
	int x, y;
	int edge[4];
	bool visited[4];
public:
	int getX() const;
	int getY() const;
	bool getVisited(int) const;
	int getEdgeState(int) const;
	void visit(int);
	friend class Level;
	Tile(int _x, int _y, int* e);
};