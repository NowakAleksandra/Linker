#pragma once

class Tile {
	int x, y;
	int edge[4];
public:
	Tile(int _x, int _y, int* e);
};